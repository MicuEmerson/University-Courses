package models.statement;

import models.PrgState;
import models.expression.IExpression;
import utils.IDictionary;
import utils.IList;

public class PrintStmt implements Statement {

    private IExpression exp;
    public PrintStmt(IExpression _exp){
        exp = _exp;
    }


    @Override
    public PrgState execute(PrgState state) {
        IList<Integer> list = state.getList();
        IDictionary<String, Integer> dict = state.getDict();
        int val = exp.eval(dict);
        list.add(val);
        return state;
    }

    @Override
    public String toString(){ return "print(" + exp + ");" ;}
}
