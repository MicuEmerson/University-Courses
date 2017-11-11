package view;

import controller.Controller;
import exceptions.DivisionByZero;
import exceptions.EmptyStack;
import exceptions.InvalidOperator;
import exceptions.VariableNotDefined;
import exceptions.fileExceptions.FileException;

public class RunExample extends Command {
    private Controller ctrl;

    public RunExample(String key, String desc, Controller ctr){
        super(key, desc);
        this.ctrl=ctr;
    }
    @Override
    public void execute() {
        try {
            ctrl.executeAll();
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
