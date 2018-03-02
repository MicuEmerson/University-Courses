package models.statement;

import models.PrgState;
import models.expression.IExpression;

public class NewLatch implements Statement {

    String varName;
    IExpression exp;

    public NewLatch(String varName, IExpression exp) {
        this.varName = varName;
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) {

        int number = exp.eval(state.getDict(), state.getHeap());

        synchronized (state.getLatchTable()){
              int id = GenCountDownLatchID.getID();

              state.getLatchTable().add(id, number);

              if(state.getDict().exists(varName))
                  state.getDict().updateValue(varName, id);
              else
                  state.getDict().setValue(varName,id);
        }

        return null;
    }

    @Override
    public String toString(){
        return "NewLatch("+varName+ "," + exp+")";
    }

    }
