package models.statement;

import models.PrgState;

public class Return implements Statement{


    @Override
    public PrgState execute(PrgState state) {

        state.getStackSymTable().pop();
        return null;
    }

    @Override
    public String toString(){
        return "return()";
    }
}
