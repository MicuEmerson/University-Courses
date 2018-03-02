package sample;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.ListView;
import javafx.stage.Modality;
import javafx.stage.Stage;
import models.booleanExpression.Lower;
import models.expression.ArithExp;
import models.expression.ConstExp;
import models.expression.IExpression;
import models.expression.VarExp;
import models.fileHandling.CloseRFile;
import models.fileHandling.OpenRFile;
import models.fileHandling.ReadFile;
import models.heapStatements.HeapAllocation;
import models.heapStatements.HeapReading;
import models.heapStatements.HeapWriting;
import models.statement.*;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;


public class SelectProgramController {

    @FXML
    private ListView<String> listView;

    @FXML
    private Button runProgramBTN;


    private List<Statement> StmtList = new ArrayList<Statement>();


    @FXML
    public void initialize() {

       Statement s1 = new AssignStmt("v", new ConstExp(2));
       Statement s2 = new AssignStmt("w", new ConstExp(5));

        ArrayList<IExpression> expList = new ArrayList<>();
        expList.add(new ArithExp('*', new VarExp("v"), new ConstExp(10)));
        expList.add(new VarExp("w"));
       Statement s3 = new CallStmt("sum", expList);

       Statement s4 = new PrintStmt(new VarExp("v"));


        ArrayList<IExpression> expList2 = new ArrayList<>();
        expList2.add(new VarExp("v"));
        expList2.add(new VarExp("w"));
       Statement s5 = new CallStmt("product", expList2 );

       Statement s6 = new CallStmt("sum", expList2);

       Statement f1 = new ForkStmt(new CompStmt(s5,new ForkStmt(s6)));
       Statement c1 = new CompStmt(s1,s2);
       Statement c2 = new CompStmt(s3,s4);
       Statement ex1 = new CompStmt(new CompStmt(c1,c2), f1);

        StmtList.add(ex1);



        ObservableList<String> list = FXCollections.observableArrayList();
        for(Statement i : StmtList)
            list.add(""+i);

        listView.setItems(list);

        listView.getSelectionModel().selectIndices(0);
    }

    @FXML
    public void buttonRun() throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("runProgram.fxml"));
        loader.setController(new RunProgramController(StmtList.get(listView.getSelectionModel().getSelectedIndex())));

        Stage stage = new Stage();
        Parent root = loader.load();
        stage.setTitle("Running Program");
        stage.setScene(new Scene(root, 800, 600));
        stage.initModality(Modality.APPLICATION_MODAL);
        stage.show();

    }

}
