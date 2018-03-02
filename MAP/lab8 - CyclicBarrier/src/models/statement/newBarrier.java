package models.statement;

import models.PrgState;
import models.expression.IExpression;
import utils.MyPair;

import java.util.ArrayList;
import java.util.List;

public class newBarrier implements Statement {
    String varName;
    IExpression exp;
    private static int id = 0;

    public newBarrier(String varName, IExpression exp) {
        this.varName = varName;
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) {

        int number = exp.eval(state.getDict(), state.getHeap());

        synchronized (state.getBarrierTable()){

            state.getBarrierTable().add(id, new MyPair(new ArrayList<Integer>(), number));
            if(state.getDict().exists(varName))
                state.getDict().updateValue(varName,id);
            else
                state.getDict().setValue(varName, id);
        }


        return null;
    }

    @Override
    public String toString(){
        return "newBarrier("+ varName +","+exp+")";
    }
}
