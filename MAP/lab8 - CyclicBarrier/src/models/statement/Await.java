package models.statement;

import models.PrgState;

public class Await implements Statement{

    private String varName;

    public Await(String varName) {
        this.varName = varName;
    }


    @Override
    public PrgState execute(PrgState state) {

        if(!state.getDict().exists(varName))
            throw new RuntimeException("This " + varName + " do not exist in symTable");

        int id = state.getDict().getValue(varName);

        if(!state.getBarrierTable().contains(id))
            throw new RuntimeException("This " + id + " do not exist in BarrierTable");

        synchronized (state.getBarrierTable()){

            if(state.getBarrierTable().get(id).getFirst().size() == state.getBarrierTable().get(id).getSecond())
                ;
            else if(state.getBarrierTable().get(id).getFirst().contains(state.getID()))
                state.getStack().push(this);
            else {
                  state.getBarrierTable().get(id).getFirst().add(state.getID());
                  state.getStack().push(this);
            }

        }

        return null;
    }

    @Override
    public String toString(){
        return "Await("+varName+")";
    }
}
