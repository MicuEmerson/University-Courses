package models.statement;

import models.PrgState;
import utils.IExeStack;

public class CompStmt implements Statement{

    private Statement first, second;
    public CompStmt(Statement f, Statement s){
        first = f;
        second = s;
    }

    @Override
    public PrgState execute(PrgState state) {
        IExeStack<Statement> stack = state.getStack();
        stack.push(second);
        stack.push(first);

        return null;
    }

    @Override
    public String toString(){
        return "[" + first +" , "+ second + "]";
    }
}
