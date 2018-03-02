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

        //hardcodam programe
        Statement a = new AssignStmt("a", new ArithExp('+', new ConstExp(2), new ArithExp('*', new ConstExp(3), new ConstExp(5))));
        Statement b = new CompStmt(new AssignStmt("b", new ArithExp('+', new VarExp("a"), new ConstExp(1))), new PrintStmt(new VarExp("b")));
        Statement ex1 = new CompStmt(a,b);

        Statement aa = new AssignStmt("a", new ArithExp('-', new ConstExp(2), new ConstExp(2)));
        Statement thenS = new AssignStmt("v", new ConstExp(2));
        Statement elseS = new AssignStmt("v", new ConstExp(3));
        Statement decision = new IfStmt(new VarExp("a"),  thenS, elseS);
        Statement ex2 = new CompStmt(aa, new CompStmt(decision, new PrintStmt(new VarExp("v"))));


        Statement a1 =  new AssignStmt("v", new ConstExp(6));
        Statement a2 = new WhileStmt(new ArithExp('-',new VarExp("v"), new ConstExp(4) ),
                new CompStmt(new PrintStmt(new VarExp("v")), new AssignStmt("v", new ArithExp('-',new VarExp("v"), new ConstExp(1) ))));
        Statement a3 = new PrintStmt(new VarExp("v"));
        Statement ex3 = new CompStmt(new CompStmt(a1,a2), a3);

        Statement q1 = new AssignStmt("v", new ConstExp(10));
        Statement q2 = new HeapAllocation("a", new ConstExp(22));
        Statement q3 = new HeapWriting("a", new ConstExp(30));
        Statement q4 = new AssignStmt("v", new ConstExp(32));
        Statement q5 = new PrintStmt(new VarExp("v"));
        Statement q6 = new PrintStmt(new HeapReading("a"));
        Statement q7 = new CompStmt(new CompStmt(q3,q4), new CompStmt(q5,q6));
        Statement q8 = new ForkStmt(q7);
        Statement q9 = new PrintStmt(new VarExp("v"));
        Statement q10 = new PrintStmt(new HeapReading("a"));
        Statement c1 = new CompStmt(q1, q2);
        Statement c2 = new CompStmt(q8, new CompStmt(q9, q10));
        Statement ex4 = new CompStmt(c1,c2);

        Statement Ts1 = new OpenRFile("var_f", "text.txt");
        Statement Ts2 = new ReadFile(new VarExp("var_f"), "var_c");
        Statement TthenS1 = new ReadFile(new VarExp("var_f"), "var_c");
        Statement TthenS2 = new PrintStmt(new VarExp("var_c"));
        Statement TthenS = new CompStmt(TthenS1, TthenS2);
        Statement TelseS = new PrintStmt(new ConstExp(0));
        Statement Ts3 = new IfStmt(new VarExp("var_c"), TthenS, TelseS);
        Statement Ts4 = new CloseRFile(new VarExp("var_f"));
        Statement Ts5 = new CompStmt(Ts1,Ts2);
        Statement Ts6 = new CompStmt(Ts3, Ts4);
        Statement ex5 = new CompStmt(Ts5, Ts6);

        Statement Qa1 = new AssignStmt("v", new ConstExp(20));
        Statement Qa2 = new CompStmt(new PrintStmt(new VarExp("v")),
                new AssignStmt("v", new ArithExp('+', new ConstExp(1), new VarExp("v"))));
        Statement TQa1 = new PrintStmt(new VarExp("v"));
        Statement TQa2 = new CompStmt(Qa2, TQa1);
        Statement Qa3 = new ForkStmt(TQa2);
        Statement QQ4 = new CompStmt(Qa3, Qa3);

        Statement Qa4 = new ForStmt(new AssignStmt("v", new ConstExp(0)),
                new Lower(new VarExp("v"), new ConstExp(10)),
                new AssignStmt("v",  new ArithExp('+', new VarExp("v"), new ConstExp(1))),
                QQ4
        );
        Statement Qa5 = new PrintStmt(new ArithExp('*' , new VarExp("v"), new ConstExp(10)));
        Statement ex6 = new CompStmt(Qa1, new CompStmt(Qa4, Qa5));



        StmtList.add(ex1);StmtList.add(ex2);StmtList.add(ex3);StmtList.add(ex4);StmtList.add(ex5);StmtList.add(ex6);


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
