package models.expression;

import utils.IDictionary;
import utils.IHeap;

public class VarExp implements IExpression {
    String id;
    public VarExp(String _id){
        id = _id;
    }



    @Override
    public int eval(IDictionary<String, Integer> d, IHeap<Integer, Integer> heap) {

        int idHeap = d.getValue(id);

        return heap.get(idHeap);
    }

    @Override
    public String toString(){
        return id;
    }

}
