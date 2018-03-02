package models.statement;

import models.PrgState;
import models.booleanExpression.NotEqual;
import models.expression.IExpression;
import models.expression.NotExp;

public class Repeat implements Statement {


   private Statement statement;
   private  IExpression exp;
   private  IExpression dr;

    public Repeat(Statement statement, IExpression exp) {
        this.statement = statement;
        this.exp = exp;
    }



    @Override
    public PrgState execute(PrgState state) {

        Statement s1 = new WhileStmt(new NotExp(exp), statement);
        state.getStack().push(new CompStmt(statement, s1));


        return null;
    }

    @Override
    public String toString(){
        return "repeat(" + statement + ") untill(" + exp + ")";
    }
}
