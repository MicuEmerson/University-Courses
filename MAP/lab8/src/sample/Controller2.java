package sample;

import javafx.fxml.FXML;
import models.PrgState;
import models.fileHandling.*;
import models.statement.GenIDFork;
import models.statement.Statement;
import repository.Repository;
import utils.*;

public class Controller2 {

    @FXML
    public void initialize(){


        IExeStack<Statement> exeStack = new ExeStack<>();
        IDictionary<String, Integer> dict = new Dictionary<>();
        IList<Integer> list = new MyList<>();
        IFileTable<Integer, FileData> fileTable = new FileTable<>();
        IHeap<Integer, Integer> heap = new Heap<>();
        exeStack.push(Controller.statement);
        PrgState programState = new PrgState(exeStack, dict, list, null, fileTable, heap, GenIDFork.getID());

        Repository repo = new Repository();
        repo.addPrgState(programState);

        System.out.println(""+Controller.statement);
    }
}
