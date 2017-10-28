package models;

import utils.IDictionary;

public class VarExp implements IExpression {
    String id;
    public VarExp(String _id){
        id = _id;
    }

    @Override
    public int eval(IDictionary<String, Integer> d){

        return d.getValue(id);
    }

    @Override
    public String toString(){
        return id;
    }

}
