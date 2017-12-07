package models.heapStatements;

import exceptions.VariableNotDefined;
import models.PrgState;
import models.expression.IExpression;
import models.statement.Statement;
import utils.IDictionary;
import utils.IHeap;

public class HeapReading implements IExpression {

     String varName;

    public HeapReading(String varName) {
        this.varName = varName;
    }


    @Override
    public int eval(IDictionary<String, Integer> dict, IHeap<Integer, Integer> heap) {

        if(!dict.constains(varName)) {
            System.out.println("BAAA");
            throw new VariableNotDefined("This key is not in our symTable");
        }
        int heapID = dict.getValue(varName);

        if(!heap.contains(heapID)) {
            System.out.printf("MAAA");
            throw new VariableNotDefined("This key is not in our heapTable");
        }

        return  heap.get(heapID);
    }

    @Override
    public String toString(){
        return "heapReading(" + varName +")";
    }

}
