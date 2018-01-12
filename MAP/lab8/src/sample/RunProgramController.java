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
import models.fileHandling.*;
import models.statement.GenIDFork;
import models.statement.Statement;
import repository.Repository;
import utils.*;

import utilsTables.*;

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

    private Controller ctrl;




    @FXML
    public void initialize(){

        IExeStack<Statement> exeStack = new ExeStack<>();
        IDictionary<String, Integer> dict = new Dictionary<>();
        IList<Integer> list = new MyList<>();
        IFileTable<Integer, FileData> fileTable = new FileTable<>();
        IHeap<Integer, Integer> heap = new Heap<>();
        exeStack.push(SelectProgramController.statement);
        PrgState programState = new PrgState(exeStack, dict, list, null, fileTable, heap, GenIDFork.getID());

        Repository repo = new Repository();
        repo.addPrgState(programState);
        ctrl = new Controller(repo);


        this.heapAddressColumn.setCellValueFactory(new PropertyValueFactory<>("address"));
        this.heapValueColumn.setCellValueFactory(new PropertyValueFactory<>("value"));
        this.fileTableIdentifier.setCellValueFactory(new PropertyValueFactory<>("id"));
        this.fileTableName.setCellValueFactory(new PropertyValueFactory<>("fileName"));
        this.symTableVarName.setCellValueFactory(new PropertyValueFactory<>("varName"));
        this.symTableValue.setCellValueFactory(new PropertyValueFactory<>("value"));


        setNoPrgState();
        setPrgStateIdentifiers();
        prgStateIdentifiers.getSelectionModel().select(0);
        setExeStack();
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

        for(String key: programState.getDict().getAll())
            list.add(new SymTableView(key, programState.getDict().getValue(key)));

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
    }



    public void executeOneStep(ActionEvent ae){

        try {
            if (ctrl.oneStepGUI()) {
                setAll();
            } else {
                setNoPrgState();
                setPrgStateIdentifiers();
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
