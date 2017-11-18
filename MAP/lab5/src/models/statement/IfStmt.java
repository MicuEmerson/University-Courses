package models.statement;

import models.PrgState;
import models.expression.IExpression;
import utils.IDictionary;
import utils.IExeStack;
import utils.IHeap;

public class IfStmt implements Statement {

    private IExpression exp;
    private Statement thenS;
    private Statement elseS;

    public IfStmt(IExpression _exp, Statement _thenS, Statement _elseS){
        exp = _exp;
        thenS = _thenS;
        elseS = _elseS;
    }

    @Override
    public PrgState execute(PrgState state) {
        IDictionary <String, Integer> dict = state.getDict();
        IExeStack<Statement> stack = state.getStack();
        IHeap<Integer, Integer> heap = state.getHeap();
        int val = exp.eval(dict, heap);

        if(val != 0)
            stack.push(thenS);
        else
            stack.push(elseS);

        return state;
    }

    @Override
    public String toString(){
        return "IF("+ exp + ") THEN(" +thenS + ")ELSE(" + elseS + ") ;";
    }
}
