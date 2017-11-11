package models.heapStatements;

import exceptions.VariableNotDefined;
import models.PrgState;
import models.expression.IExpression;
import models.statement.Statement;
import utils.IDictionary;
import utils.IHeap;

public class HeapWriting implements Statement {

    String varName;
    IExpression exp;

    public HeapWriting(String varName, IExpression exp) {
        this.varName = varName;
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) {
        IDictionary<String, Integer> dict = state.getDict();
        IHeap<Integer, Integer> heap = state.getHeap();

        if(!dict.constains(varName))
            throw new VariableNotDefined("This key is not in our symTable");
        int heapID = dict.getValue(varName);

        if(!heap.contains(heapID))
            throw new VariableNotDefined("This key is not in our heapTable");

        int val = exp.eval(dict, heap);
        heap.update(heapID, val);

        return state;

    }

    @Override
    public String toString(){
        return "heapWriting("+varName+","+exp+")";
    }
}
