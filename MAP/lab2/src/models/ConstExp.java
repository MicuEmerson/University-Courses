package models;

import utils.IDictionary;

public class ConstExp implements IExpression {
    private int number;

    public ConstExp(int _number){
        number = _number;
    }

    @Override
    public int eval(IDictionary<String, Integer> d){
        return number;
    }

    @Override
    public String toString(){
        return "" + number ;
    }
}
