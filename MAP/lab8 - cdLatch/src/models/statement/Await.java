package models.statement;

import models.PrgState;

public class Await implements Statement {

     String varName;

    public Await(String varName) {
        this.varName = varName;
    }


    @Override
    public PrgState execute(PrgState state) {

        if(!state.getDict().exists(varName))
                throw new RuntimeException("This " + varName + " do not exist in symTable");

        int id = state.getDict().getValue(varName);

        if(!state.getLatchTable().contains(id))
                throw new RuntimeException("This " + id + " do not exist in LatchTable");

        if(state.getLatchTable().get(id) != 0)
            state.getStack().push(this);


        return null;
    }

    @Override
    public String toString(){
        return "Await("+varName+")";
    }
}
