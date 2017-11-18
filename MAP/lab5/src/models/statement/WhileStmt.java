package models.statement;

import models.PrgState;
import models.expression.IExpression;
import utils.IDictionary;
import utils.IExeStack;
import utils.IHeap;

public class WhileStmt implements Statement {
    IExpression exp;
    Statement statement;

    public WhileStmt(IExpression exp, Statement statement) {
        this.exp = exp;
        this.statement = statement;
    }


    @Override
    public PrgState execute(PrgState state) {

        IExeStack<Statement> stack = state.getStack();
        IHeap<Integer, Integer> heap = state.getHeap();
        IDictionary<String, Integer> dict = state.getDict();

        int val = exp.eval(dict, heap);

        if(val != 0) {
            stack.push(new WhileStmt(exp, statement));
            stack.push(statement);
        }

        return state;
    }

    @Override
    public String toString(){
        return "While("+exp+"){"+statement+"}";
    }
}
