package models.booleanExpression;

import models.expression.IExpression;
import utils.IDictionary;
import utils.IHeap;


public class GreaterEqual implements IExpression {

    IExpression st,dr;

    public GreaterEqual(IExpression st, IExpression dr) {
        this.st = st;
        this.dr = dr;
    }


    @Override
    public int eval(IDictionary<String, Integer> d, IHeap<Integer, Integer> heap) {
        if(st.eval(d,heap) >= dr.eval(d,heap))
            return 1;
        return 0;
    }

    @Override
    public String toString(){
        return "GreaterEqual("+st+">="+dr+") ";
    }

}
