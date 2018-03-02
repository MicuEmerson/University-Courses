package models.statement;

import models.PrgState;
import models.expression.ConstExp;

public class Sleep implements  Statement {

    ConstExp number;

    public Sleep(ConstExp number) {
        this.number = number;
    }

    @Override
    public PrgState execute(PrgState state) {

        int value = number.eval(state.getDict(), state.getHeap());

        if(number.eval(state.getDict(), state.getHeap()) != 0)
            state.getStack().push(new Sleep(new ConstExp(value-1)));


        return null;
    }

    @Override
    public String toString(){
        return "sleep(" + number + ")";
    }
}
