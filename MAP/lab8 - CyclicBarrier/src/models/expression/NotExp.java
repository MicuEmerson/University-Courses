package models.expression;

import utils.IDictionary;
import utils.IHeap;

public class NotExp implements IExpression {
    private IExpression exp;


    public NotExp(IExpression exp) {
        this.exp = exp;
    }

    @Override
    public int eval(IDictionary<String, Integer> d, IHeap<Integer, Integer> heap) {

        if(exp.eval(d,heap) > 0)
            return 0;

        return 1;

    }
    @Override
    public String toString(){
        return "NotExp(" + exp + ")";
    }
}
