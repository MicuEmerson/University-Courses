
import controller.*;
import models.PrgState;
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


        //v=10;new(v,20);new(a,22);print(v)
        Statement z = new AssignStmt("v", new ConstExp(10));
        Statement z1 =  new HeapAllocation("v", new ConstExp(20));
        Statement z2 = new HeapAllocation("a", new ConstExp(22));
        Statement z3 = new PrintStmt(new VarExp("v"));

        Statement a1 = new CompStmt(z,z1);
        Statement a2 = new CompStmt(z2,z3);

        Statement ex1 = new CompStmt(a1,a2);

        //v=10;new(v,20);new(a,22);print(100+rH(v));print(100+rH(a))
        Statement y =  new HeapAllocation("v", new ConstExp(20));
        Statement y1 = new HeapAllocation("a", new ConstExp(22));
        Statement y2 = new PrintStmt(new ArithExp('+',new ConstExp(100),new HeapReading("v")));
        Statement y3 = new PrintStmt(new ArithExp('+',new ConstExp(100),new HeapReading("a")));

        Statement b1 = new CompStmt(y, y1);
        Statement b2 = new CompStmt(y2, y3);

        Statement ex2 = new CompStmt(b1,b2);



        //v=10;new(v,20);new(a,22);wH(a,30);print(a);print(rH(a))
        Statement x = new AssignStmt("v",  new ConstExp(10));
        Statement x1 = new HeapAllocation("v", new ConstExp(20));
        Statement x2 = new HeapAllocation("a", new ConstExp(22));
        Statement x3 = new HeapWriting("a", new ConstExp(30));
        Statement x4 = new PrintStmt(new VarExp("a"));
        Statement x5 = new PrintStmt(new HeapReading("a"));

        Statement c1 = new CompStmt(x,x1);
        Statement c2 = new CompStmt(x2,x3);
        Statement c3 = new CompStmt(x4,x5);

        Statement ex3 = new CompStmt(c1,new CompStmt(c2,c3));



        //v=10;new(v,20);new(a,22);wH(a,30);print(a);print(rH(a));a=0
        Statement q = new AssignStmt("v", new ConstExp(10));
        Statement q1 = new HeapAllocation("v",new ConstExp(20));
        Statement q2 = new HeapAllocation("a", new ConstExp(22));
        Statement q3 = new HeapWriting("a", new ConstExp(30));
        Statement q4 = new PrintStmt(new VarExp("a"));
        Statement q5 = new PrintStmt(new HeapReading("a"));
        Statement q6 = new AssignStmt("a", new ConstExp(0));


        Statement d1 = new CompStmt(q, q1);
        Statement d2 = new CompStmt(q2, q3);
        Statement d3 = new CompStmt(q4, q5);
        Statement d4 = new CompStmt(q6, d1);

        Statement ex4 = new CompStmt(new CompStmt(d2,d3), d4);


        IExeStack<Statement> exeStack = new ExeStack<>();
        IDictionary<String, Integer> dict = new Dictionary<>();
        IList<Integer> list = new  MyList<>();
        IFileTable<Integer, FileData> fileTable = new FileTable<>();
        IHeap<Integer, Integer> heap = new Heap<>();
        //exeStack.push(q6);exeStack.push(q5);exeStack.push(q4);exeStack.push(q3);exeStack.push(q2);exeStack.push(q1);exeStack.push(q);
        //exeStack.push(ex4);
        PrgState state = new PrgState(exeStack, dict, list, null, fileTable, heap);

        IRepository repo = new Repository();
        Controller ctrl = new Controller(repo);
        repo.addPrgState(state);

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1",  q.toString(), ctrl));
        menu.show();





    }
}



