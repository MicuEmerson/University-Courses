package models;

import utils.IDictionary;



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
        int val = exp.eval(dict);
        dict.setValue(id, val);
        return state;
    }
    @Override
    public String toString(){
       return id + "=" + exp + "; ";
   }
}
