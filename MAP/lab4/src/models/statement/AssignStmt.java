package models.statement;

import models.PrgState;
import models.expression.IExpression;
import utils.IDictionary;
import utils.IHeap;


public class AssignStmt implements Statement {
   private String id;
   private IExpression exp;

   public AssignStmt(String _id, IExpression _exp){
       id = _id;
       exp = _exp;
   }


    @Override
    public PrgState execute(PrgState state) {

        IDictionary<String, Integer> dict = state.getDict();
        IHeap<Integer,Integer> heap = state.getHeap();
        int val = exp.eval(dict, heap);
        dict.setValue(id, val);
        return state;
    }
    @Override
    public String toString(){
       return id + "=" + exp + "; ";
   }
}
