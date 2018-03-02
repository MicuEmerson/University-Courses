package models.expression;

import utils.IDictionary;
import utils.IHeap;

import java.io.Serializable;

public interface IExpression extends Serializable {
    public int eval(IDictionary<String, Integer> d, IHeap<Integer, Integer> heap) ;
}
