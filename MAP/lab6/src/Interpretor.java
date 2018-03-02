
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
        //Statement c2 = new CompStmt(a9,a10);
        Statement ex1 = new CompStmt(c1,c2);

/*
        Statement s1 = new AssignStmt("v", new ConstExp(10));
        Statement s2 = new AssignStmt("v", new ConstExp(11));
        Statement s3 = new AssignStmt("v", new ConstExp(12));

        Statement s8 = new ForkStmt(new CompStmt(new ForkStmt(s2), s3));
        exeStack.push(s8);
        exeStack.push(s1);
*/


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

        exeStack.push(ex5);

        PrgState state = new PrgState(exeStack, dict, list, null, fileTable, heap, GenIDFork.getID());

        IRepository repo = new Repository();
        Controller ctrl = new Controller(repo);
        repo.addPrgState(state);



        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1",  ex5.toString(), ctrl));
        try {
            menu.show();
        }
        catch (ControllerException c){
            System.out.printf(c.getMessage());
        }



    }
}



