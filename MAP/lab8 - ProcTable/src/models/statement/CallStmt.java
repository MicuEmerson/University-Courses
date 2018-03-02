package models.statement;

import models.PrgState;
import models.expression.IExpression;
import utils.Dictionary;
import utils.IDictionary;

import java.util.ArrayList;

public class CallStmt implements Statement {

    String fname;
    ArrayList<IExpression> expList = new ArrayList<>();

    public CallStmt(String fname, ArrayList<IExpression> expList) {
        this.fname = fname;
        this.expList = expList;
    }


    @Override
    public PrgState execute(PrgState state) {


        if(!state.getProcTable().contains(fname))
            throw new RuntimeException("this procedure " + fname + "is not in our ProcTable");

        ArrayList<Integer> evaluateExp = new ArrayList<>();
        for(IExpression exp : expList)
            evaluateExp.add(exp.eval(state.peekStackSymTab(), state.getHeap()));


        IDictionary<String, Integer> symTab = new Dictionary<>();

        for(int i = 0; i<state.getProcTable().get(fname).getList().size(); i++)
            symTab.setValue(state.getProcTable().get(fname).getList().get(i), evaluateExp.get(i));

        state.getStackSymTable().push(symTab);
        state.getStack().push(new Return());
        state.getStack().push(state.getProcTable().get(fname).getStatement());


        return null;
    }



    @Override
    public String toString(){
        String x = new String();
        x+="call("+fname +" ; ";
        for(IExpression e : expList)
            x += " "+e;

        return x;
    }


}
