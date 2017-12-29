package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
import models.statement.*;
import models.booleanExpression.*;
import models.expression.*;
import models.fileHandling.*;
import models.heapStatements.*;

import javax.naming.ldap.Control;
import java.util.ArrayList;
import java.util.List;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{



        Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));

        primaryStage.setTitle("Programs");
        primaryStage.setScene(new Scene(root, 500, 300));
        primaryStage.show();

    }


    public static void main(String[] args) {
        launch(args);
    }
}
