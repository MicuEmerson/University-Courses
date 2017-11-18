
import controller.*;
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


import static java.util.stream.Collectors.toList;

public class Interpretor {


    public static void main(String[] args) {


        //v=6; (while (v-4) print(v);v=v-1);print(v)
        Statement a1 =  new AssignStmt("v", new ConstExp(6));
        Statement a2 = new WhileStmt(new ArithExp('-',new VarExp("v"), new ConstExp(4) ),
                                     new CompStmt(new PrintStmt(new VarExp("v")), new AssignStmt("v", new ArithExp('-',new VarExp("v"), new ConstExp(1) ))));

        Statement a3 = new PrintStmt(new VarExp("v"));

        Statement ex1 = new CompStmt(new CompStmt(a1,a2), a3);


        IExeStack<Statement> exeStack = new ExeStack<>();
        IDictionary<String, Integer> dict = new Dictionary<>();
        IList<Integer> list = new  MyList<>();
        IFileTable<Integer, FileData> fileTable = new FileTable<>();
        IHeap<Integer, Integer> heap = new Heap<>();
        exeStack.push(ex1);

        PrgState state = new PrgState(exeStack, dict, list, null, fileTable, heap);

        IRepository repo = new Repository();
        Controller ctrl = new Controller(repo);
        repo.addPrgState(state);

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1",  ex1.toString(), ctrl));
        menu.show();







    }
}



