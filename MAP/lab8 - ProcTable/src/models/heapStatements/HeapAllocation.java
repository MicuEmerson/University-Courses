package models.heapStatements;

import models.PrgState;
import models.expression.IExpression;
import models.statement.Statement;
import utils.Dictionary;
import utils.IDictionary;
import utils.IHeap;

import javax.print.attribute.IntegerSyntax;

public class HeapAllocation implements Statement {

     String varName;
     IExpression exp;

    public HeapAllocation(String varName, IExpression exp) {
        this.varName = varName;
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) {

        IDictionary<String, Integer> dict = state.peekStackSymTab();
        IHeap<Integer, Integer> heap = state.getHeap();

        int id = GenIDHeap.getID();
        int val = exp.eval(dict, heap);

        heap.add(id, val);
        if(dict.constains(varName))
                dict.updateValue(varName, id);
        else
                 dict.setValue(varName, id);


        return null;
    }

    @Override
     public String toString(){
        return "NewH(" + varName + ", " + exp + ")";
     }
}
