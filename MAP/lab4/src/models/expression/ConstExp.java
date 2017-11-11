package models.expression;

import utils.IDictionary;
import utils.IHeap;

public class ConstExp implements IExpression {
    private int number;

    public ConstExp(int _number){
        number = _number;
    }

    @Override
    public int eval(IDictionary<String, Integer> d, IHeap<Integer, Integer> heap) {
        return number;
    }

    @Override
    public String toString(){
        return "" + number ;
    }
}
