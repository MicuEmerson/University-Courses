package models.statement;

import models.PrgState;
import models.expression.IExpression;
import utils.IDictionary;
import utils.IHeap;
import utils.IList;

public class PrintStmt implements Statement {

    private IExpression exp;
    public PrintStmt(IExpression _exp){
        exp = _exp;
    }


    @Override
    public PrgState execute(PrgState state) {
        IList<Integer> list = state.getList();
        IDictionary<String, Integer> dict = state.peekStackSymTab();
        IHeap<Integer, Integer> heap = state.getHeap();
        int val = exp.eval(dict, heap);
        list.add(val);
        return null;
    }

    @Override
    public String toString(){ return "print(" + exp + ");" ;}
}
