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


        Statement s1 = new AssignStmt("v", new ConstExp(10));
        Statement s2 = new AssignStmt("v", new ArithExp('-', new VarExp("v"), new ConstExp(1)));
        Statement s3 = new PrintStmt(new VarExp("v"));
        Statement s4 = new Sleep(new ConstExp(10));
        Statement s5 = new PrintStmt(new ArithExp('*', new VarExp("v"), new ConstExp(10)));
        Statement f1 = new CompStmt(s2, new CompStmt(s2,s3));
        Statement ex1 = new CompStmt(new CompStmt(s1,new ForkStmt(f1)), new CompStmt(s4,s5));


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
