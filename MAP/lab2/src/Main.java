
import models.*;
import controller.*;
import repository.*;
import utils.*;
import exceptions.*;
import java.util.Scanner;

public class Main {


    public static void main(String[] args) {

        // Example1:
        // v=2;
        // Print(v)
        Statement s1 = new CompStmt(new AssignStmt("v", new ConstExp(2)), new PrintStmt(new VarExp("v")));


        // Example2:
        // a=2+3*5;
        // b=a+1;
        // Print(b)
        Statement a = new AssignStmt("a", new ArithExp('+', new ConstExp(2), new ArithExp('*', new ConstExp(3), new ConstExp(5))));
        Statement b = new CompStmt(new AssignStmt("b", new ArithExp('+', new VarExp("a"), new ConstExp(1))), new PrintStmt(new VarExp("b")));
        Statement s2 = new CompStmt(a,b);


        //a=2-2;
        //(If a Then v=2 Else v=3);
        //Print(v)
        Statement aa = new AssignStmt("a", new ArithExp('-', new ConstExp(2), new ConstExp(2)));
        Statement thenS = new AssignStmt("v", new ConstExp(2));
        Statement elseS = new AssignStmt("v", new ConstExp(3));
        Statement decision = new IfStmt(new VarExp("a"),  thenS, elseS);
        Statement s3 = new CompStmt(aa, new CompStmt(decision, new PrintStmt(new VarExp("v"))));


        IExeStack<Statement> exeStack = new ExeStack<>();
        IDictionary<String, Integer> dict = new Dictionary<>();
        IList<Integer> list = new  MyList<>();



        Scanner scann = new Scanner(System.in);
        String s = "\t 1) exemple 1\n" + "\t 2) exemple 2\n" + "\t 3) exemple 3";
        String ss = "\t 1)OneStepExecution\n" + "\t 2) ExecuteAll";

        System.out.println(s);
        int cmd = scann.nextInt();

        if(cmd == 1)
            exeStack.push(s1);
        else if(cmd == 2)
            exeStack.push(s2);
        else if(cmd == 3)
            exeStack.push(s3);
        else {
            System.out.println("wrong input");
            return;
        }

        PrgState state = new PrgState(exeStack, dict, list, null);


        IRepository repo = new Repository();
        Controller ctrl = new Controller(repo);
        repo.addPrgState(state);


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
        }
    }

}
