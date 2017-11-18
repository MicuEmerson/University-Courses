package models.expression;

import utils.IDictionary;
import utils.IHeap;

public interface IExpression {
    public int eval(IDictionary<String, Integer> d, IHeap<Integer, Integer> heap) ;
}
