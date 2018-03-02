package models.statement;

import models.PrgState;
import models.expression.IExpression;

public class ForStmt implements Statement {

     Statement s1,s3,s4;
     IExpression s2;

    public ForStmt(Statement s1,  IExpression s2, Statement s3, Statement s4) {

        this.s1 = s1;
        this.s3 = s3;
        this.s4 = s4;
        this.s2 = s2;
    }



    @Override
    public PrgState execute(PrgState state) {

        Statement a1 = new WhileStmt(s2,new CompStmt(s4,s3));
        Statement a2 = new CompStmt(s1, a1);

        state.getStack().push(a2);
        return null;
    }

    @Override
    public String toString(){
        return "for(" + s1 + ";" + s2 + ";" + s3 + ")"+ "{" + s4 + "}";
    }
}
