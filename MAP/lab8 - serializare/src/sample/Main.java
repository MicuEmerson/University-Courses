package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import models.PrgState;
import models.booleanExpression.Equal;
import models.booleanExpression.Lower;
import models.expression.ArithExp;
import models.expression.ConstExp;
import models.expression.VarExp;
import models.fileHandling.FileData;
import models.fileHandling.FileTable;
import models.fileHandling.IFileTable;
import models.statement.*;
import repository.Repository;
import utils.*;

import java.util.ArrayList;
import java.util.List;

import static java.lang.System.exit;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{

        Parent root = FXMLLoader.load(getClass().getResource("selectProgram.fxml"));

        primaryStage.setTitle("Programs");
        primaryStage.setScene(new Scene(root, 500, 300));
        primaryStage.show();

    }


    public static void main(String[] args) {


       launch(args);




        exit(0);
    }
}
