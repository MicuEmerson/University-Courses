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
import models.booleanExpression.Equal;
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

         Statement s1 = new HeapAllocation("v1", new ConstExp(2));
         Statement s2 = new HeapAllocation("v2", new ConstExp(3));
         Statement s3 = new HeapAllocation("v3", new ConstExp(4));
         Statement s4 = new newBarrier("cnt", new HeapReading("v3"));

         Statement s5 = new Await("cnt");
         Statement s6 = new PrintStmt(new HeapReading("v1"));
         Statement s7 = new PrintStmt(new HeapReading("v2"));
         Statement s8 = new PrintStmt(new HeapReading("v3"));

         Statement s9 = new HeapWriting("v1", new ArithExp('*', new HeapReading("v1"), new ConstExp(10)));
         Statement s10 = new HeapWriting("v2", new ArithExp('*', new HeapReading("v2"), new ConstExp(10)));
         Statement s11 = new HeapWriting("v3", new ArithExp('*', new HeapReading("v3"), new ConstExp(10)));

         Statement f1 = new CompStmt(s9, new CompStmt(s6,s5));
         Statement f2 = new CompStmt(s5, new CompStmt(s10, s7));
         Statement f3 = new CompStmt(new CompStmt(s5,s11), new CompStmt(s11, s8));

         Statement c1 = new CompStmt(new CompStmt(s1,s2), new CompStmt(s3,s4));
         Statement c2 = new CompStmt(new ForkStmt(f1), new CompStmt(new ForkStmt(f2), new ForkStmt(f3)));
         Statement c3 = new CompStmt(s5, new PrintStmt(new ConstExp(2000)));

         Statement ex1 = new CompStmt(c1, new CompStmt(c2,c3));

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
