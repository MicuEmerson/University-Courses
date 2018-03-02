package models.statement;

import models.PrgState;

public class CountDown implements  Statement {

   String varName;

    public CountDown(String varName) {
        this.varName = varName;
    }

    @Override
    public PrgState execute(PrgState state) {



        if(!state.getDict().exists(varName))
            throw new RuntimeException("This " + varName + " do not exist in symTable");

        int id = state.getDict().getValue(varName);

        if(!state.getLatchTable().contains(id))
            throw new RuntimeException("This " + id + " do not exist in LatchTable");

        synchronized (state.getLatchTable()){
            if(state.getLatchTable().get(id) > 0) {
                state.getLatchTable().update(id, state.getLatchTable().get(id) - 1);
                state.getList().add(state.getID());
            }
        }

        return null;
    }

    @Override
    public String toString(){
        return "CountDown("+varName+")";
    }
}
