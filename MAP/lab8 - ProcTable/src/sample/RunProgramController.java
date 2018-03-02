package sample;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.fxml.FXML;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import javafx.stage.Window;
import models.PrgState;
import models.expression.ArithExp;
import models.expression.VarExp;
import models.fileHandling.*;
import models.statement.*;
import repository.Repository;
import utils.*;

import utilsTables.*;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Deque;

import static java.lang.System.exit;

public class RunProgramController {

    //HEAP TABLE
    @FXML private TableView<HeapTableView> heapTable;
    @FXML private TableColumn<HeapTableView, Integer> heapAddressColumn;
    @FXML private TableColumn<HeapTableView, Integer> heapValueColumn;

    //FILE TABLE
    @FXML private TableView<FileTableView> fileTable;
    @FXML private TableColumn<FileTableView, Integer> fileTableIdentifier;
    @FXML private TableColumn<FileTableView, String> fileTableName;

    //SYM TABLE
    @FXML private TableView<SymTableView> symTable;
    @FXML private TableColumn<SymTableView, String> symTableVarName;
    @FXML private TableColumn<SymTableView, Integer> symTableValue;

    @FXML private ListView<String> outList;
    @FXML private ListView<String> exeStack;
    @FXML private ListView<String> prgStateIdentifiers;
    @FXML private Button oneStepBTN;
    @FXML private TextField noPrgStateTextField;


    @FXML private TableView<ProcTableView> ProcTable;
    @FXML private TableColumn<ProcTableView, String> ProcTableCol1;
    @FXML private TableColumn<ProcTableView, String> ProcTableBody;

    private Controller ctrl;
    private Statement statement;

    public RunProgramController(Statement statement){
        this.statement = statement;
    }

    @FXML
    public void initialize(){

        IExeStack<Statement> exeStack = new ExeStack<>();
        IDictionary<String, Integer> dict = new Dictionary<>();
         Deque<IDictionary> stackSymTable = new ArrayDeque<>();
        IList<Integer> list = new MyList<>();
        IFileTable<Integer, FileData> fileTable = new FileTable<>();
        IHeap<Integer, Integer> heap = new Heap<>();
        IProcTable<String, MyPair> procTable = new ProcTable<>();
        IDictionary<String,Integer> x = new Dictionary<>();

        ArrayList<String> l1 = new ArrayList<>();
        l1.add("a");l1.add("b");
        Statement s1 = new AssignStmt("v", new ArithExp('+', new VarExp("a"), new VarExp("b")));
        Statement s2 = new PrintStmt(new VarExp("v"));
        Statement ex1 = new CompStmt(s1,s2);
        MyPair p1 = new MyPair(l1, ex1);

        ArrayList<String> l2 = new ArrayList<>();
        l2.add("a"); l2.add("b");
        Statement s3 = new AssignStmt("v", new ArithExp('*', new VarExp("a"), new VarExp("b")));
        Statement s4 = new PrintStmt(new VarExp("v"));
        Statement ex2 = new CompStmt(s3,s4);
        MyPair p2= new MyPair(l2, ex2);

        procTable.add("sum", p1);
        procTable.add("product", p2);



        stackSymTable.push(x);
        exeStack.push(statement);
        PrgState programState = new PrgState(exeStack, stackSymTable, list, null, fileTable, heap, procTable, GenIDFork.getID());

        Repository repo = new Repository();
        repo.addPrgState(programState);
        ctrl = new Controller(repo);


        this.heapAddressColumn.setCellValueFactory(new PropertyValueFactory<>("address"));
        this.heapValueColumn.setCellValueFactory(new PropertyValueFactory<>("value"));
        this.fileTableIdentifier.setCellValueFactory(new PropertyValueFactory<>("id"));
        this.fileTableName.setCellValueFactory(new PropertyValueFactory<>("fileName"));
        this.symTableVarName.setCellValueFactory(new PropertyValueFactory<>("varName"));
        this.symTableValue.setCellValueFactory(new PropertyValueFactory<>("value"));
        this.ProcTableCol1.setCellValueFactory(new PropertyValueFactory<>("fname"));
        this.ProcTableBody.setCellValueFactory(new PropertyValueFactory<>("body"));


        setNoPrgState();
        setPrgStateIdentifiers();
        prgStateIdentifiers.getSelectionModel().select(0);
        setExeStack();
        setProcTable();
    }



    private void setNoPrgState(){
         Integer nr = ctrl.noPrgStates();
         noPrgStateTextField.setText(String.valueOf(nr));
    }

    private void setPrgStateIdentifiers(){
        prgStateIdentifiers.setItems(ctrl.getPrgStatesID());
    }

    PrgState getCurrentProgramState(){
        int index = prgStateIdentifiers.getSelectionModel().getSelectedIndex();
        if(index == -1)
            index = 0;
        return ctrl.getPrgStateByIndex(index);
    }

    private void setExeStack(){

        ObservableList<String> list = FXCollections.observableArrayList();
        PrgState programState = getCurrentProgramState();


        for(Statement i : programState.getStack().getAll())
            list.add(""+i);

        exeStack.setItems(list);
    }

    private void setHeapTable(){

        ObservableList<HeapTableView> list = FXCollections.observableArrayList();
        PrgState programState = getCurrentProgramState(); // here we don't need to get current because heap is shared by all
                                                          // but i used to don't make another function to get one programState

        for(Integer key: programState.getHeap().getAll())
            list.add(new HeapTableView(key, programState.getHeap().get(key)));

        heapTable.setItems(list);
    }

    private void setProcTable(){
        ObservableList<ProcTableView> list = FXCollections.observableArrayList();
        PrgState programeState = getCurrentProgramState();

        for(String key: programeState.getProcTable().getAll()){

              String procAndParam = new String();
              procAndParam += key+"(";
             for(String s : programeState.getProcTable().get(key).getList())
                 procAndParam += " "+s;
             procAndParam +=")";

        list.add(new ProcTableView(procAndParam,  programeState.getProcTable().get(key).getStatement().toString()));
            ProcTable.setItems(list);
        }

    }

    private void setFileTable(){

        ObservableList<FileTableView> list = FXCollections.observableArrayList();
        PrgState programState = getCurrentProgramState(); // here we don't need to get current because fileTable is shared by all
                                                         // but i used to don't make another function to get one programState

        for(Integer key: programState.getFileTable().getAllKeys())
            list.add(new FileTableView(key, programState.getFileTable().get(key).getFileName()));

        fileTable.setItems(list);
    }

    private void setSymTable(){

        ObservableList<SymTableView> list = FXCollections.observableArrayList();
        PrgState programState = getCurrentProgramState();
        IDictionary<String, Integer> dict= programState.peekStackSymTab();

        for(String key: dict.getAll())
            list.add(new SymTableView(key, dict.getValue(key)));

        symTable.setItems(list);
    }

    private void setOutList(){
        ObservableList<String> list = FXCollections.observableArrayList();
        PrgState programState = getCurrentProgramState();   // they all share the same outList

        for(Integer i: programState.getList().getAll())
            list.add(""+i);

        outList.setItems(list);
    }


    private void setAll(){
        setNoPrgState();
        setPrgStateIdentifiers();
        setExeStack();
        setHeapTable();
        setFileTable();
        setSymTable();
        setOutList();
        setProcTable();
    }



    public void executeOneStep(ActionEvent ae){

        try {
            if (ctrl.oneStepGUI()) {
                setAll();
            } else {
                setNoPrgState();
                setPrgStateIdentifiers();
                symTable.getItems().clear();
            }
        }
        catch (RuntimeException e){
            Node source = (Node) ae.getSource();
            Stage theStage = (Stage) source.getScene().getWindow();
            Alert a = new Alert(Alert.AlertType.ERROR, e.getMessage());
            a.show();
            theStage.close();
        }
    }

    public void mouseClickPrgStateIdentifiers(){

        if(ctrl.noPrgStates() > 0)
            setAll();
    }
}
