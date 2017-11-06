
import controller.*;
import exceptions.fileExceptions.FileException;
import models.PrgState;
import models.expression.ConstExp;
import models.expression.VarExp;
import models.fileHandling.*;
import models.statement.*;
import repository.*;
import utils.*;
import exceptions.*;
import java.util.Scanner;

public class Main {


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
        exeStack.push(s7);

        PrgState state = new PrgState(exeStack, dict, list, null, fileTable);

        IRepository repo = new Repository();
        Controller ctrl = new Controller(repo);
        repo.addPrgState(state);


        Scanner scann = new Scanner(System.in);
        String ss = "\t 1)OneStepExecution\n" + "\t 2) ExecuteAll";
        int cmd;

        while(!exeStack.isEmpty()){
            try {
                System.out.println(ss);
                cmd = scann.nextInt();
                if (cmd == 1)
                    ctrl.executeOneStep();
                else if (cmd == 2)
                    ctrl.executeAll();
                else
                    System.out.println("wrong input");
            }
            catch (EmptyStack eStk){
                System.out.println(eStk);
            }
            catch(DivisionByZero div){
                System.out.println(div);
            }
            catch(InvalidOperator invO){
                System.out.println(invO);
            }
            catch(VariableNotDefined varND){
                System.out.println(varND);
            }
            catch(FileException f){
                System.out.println(f);
            }
        }

    }


}
