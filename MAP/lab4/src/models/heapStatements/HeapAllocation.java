package models.heapStatements;

import models.PrgState;
import models.expression.IExpression;
import models.statement.Statement;

public class HeapAllocation implements Statement {

     String varName;
     IExpression exp;

    public HeapAllocation(String varName, IExpression exp) {
        this.varName = varName;
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) {

    }
}
