
import controller.*;
import models.PrgState;
import models.expression.ConstExp;
import models.expression.VarExp;
import models.fileHandling.*;
import models.statement.*;
import repository.*;
import utils.*;
import view.ExitCommand;
import view.RunExample;
import view.TextMenu;

public class Interpretor {


    public static void main(String[] args) {


         Statement s1 = new OpenRFile("var_f", "text.txt");
         Statement s2 = new ReadFile(new VarExp("var_f"), "var_c");
         Statement thenS1 = new ReadFile(new VarExp("var_f"), "var_c");
         Statement thenS2 = new PrintStmt(new VarExp("var_c"));
         Statement thenS = new CompStmt(thenS1, thenS2);
         Statement elseS = new PrintStmt(new ConstExp(0));

         Statement s3 = new IfStmt(new VarExp("var_c"), thenS, elseS);
         Statement s4 = new CloseRFile(new VarExp("var_f"));

         Statement s5 = new CompStmt(s1,s2);
         Statement s6 = new CompStmt(s3, s4);
         Statement s7 = new CompStmt(s5, s6);


        IExeStack<Statement> exeStack = new ExeStack<>();
        IDictionary<String, Integer> dict = new Dictionary<>();
        IList<Integer> list = new  MyList<>();
        IFileTable<Integer, FileData> fileTable = new FileTable<>();
        IHeap<Integer, Integer> heap = new Heap<>();
        exeStack.push(s7);

        PrgState state = new PrgState(exeStack, dict, list, null, fileTable, heap);

        IRepository repo = new Repository();
        Controller ctrl = new Controller(repo);
        repo.addPrgState(state);

        TextMenu menu = new TextMenu();
        menu.addCommand(new ExitCommand("0", "exit"));
        menu.addCommand(new RunExample("1",  s7.toString(), ctrl));
        menu.show();

        }

}



