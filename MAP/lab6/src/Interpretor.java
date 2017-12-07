
import controller.*;
import exceptions.ControllerException;
import models.PrgState;
import models.booleanExpression.Equal;
import models.expression.ArithExp;
import models.expression.ConstExp;
import models.expression.VarExp;
import models.fileHandling.*;
import models.heapStatements.HeapAllocation;
import models.heapStatements.HeapReading;
import models.heapStatements.HeapWriting;
import models.statement.*;
import repository.*;
import utils.*;
import view.ExitCommand;
import view.RunExample;
import view.TextMenu;

import javax.swing.plaf.nimbus.State;


import java.util.concurrent.ExecutionException;

import static java.util.stream.Collectors.toList;

public class Interpretor {


    public static void main(String[] args) {


        IExeStack<Statement> exeStack = new ExeStack<>();
        IDictionary<String, Integer> dict = new Dictionary<>();
        IList<Integer> list = new  MyList<>();
        IFileTable<Integer, FileData> fileTable = new FileTable<>();
        IHeap<Integer, Integer> heap = new Heap<>();

       /*
          Example:
          v=10;new(a,22);
          fork(wH(a,30);v=32;print(v);print(rH(a)));
          print(v);print(rH(a))
        */
        Statement a1 = new AssignStmt("v", new ConstExp(10));
        Statement a2 = new HeapAllocation("a", new ConstExp(22));

        Statement a3 = new HeapWriting("a", new ConstExp(30));
        Statement a4 = new AssignStmt("v", new ConstExp(32));
        Statement a5 = new PrintStmt(new VarExp("v"));
        Statement a6 = new PrintStmt(new HeapReading("a"));
        Statement a7 = new CompStmt(new CompStmt(a3,a4), new CompStmt(a5,a6));

        Statement a8 = new ForkStmt(a7);

        Statement a9 = new PrintStmt(new VarExp("v"));
        Statement a10 = new PrintStmt(new HeapReading("a"));

        Statement c1 = new CompStmt(a1, a2);
        Statement c2 = new CompStmt(a8, new CompStmt(a9, a10));
        Statement ex1 = new CompStmt(c1,c2);

        exeStack.push(ex1);

        PrgState state = new PrgState(exeStack, dict, list, null, fileTable, heap, GenIDFork.getID());

        IRepository repo = new Repository();
        Controller ctrl = new Controller(repo);
        repo.addPrgState(state);



        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1",  ex1.toString(), ctrl));
        try {
            menu.show();
        }
        catch (ControllerException c){
            System.out.printf(c.getMessage());
        }



    }
}



