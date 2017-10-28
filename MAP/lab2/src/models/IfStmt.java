package models;

import utils.IDictionary;
import utils.IExeStack;

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
        int val = exp.eval(dict);

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
