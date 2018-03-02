package models.statement;

import models.PrgState;
import models.fileHandling.FileData;
import models.fileHandling.IFileTable;
import utils.*;

public class ForkStmt implements Statement {

    Statement statement;

    public ForkStmt(Statement statement) {
        this.statement = statement;
    }


    @Override
    public PrgState execute(PrgState state) {

        IExeStack<Statement> stack2 = new ExeStack<>();
        IDictionary<String,Integer> dict2 = state.getDict().copy();
        IList<Integer> out2 = state.getList();
        IHeap<Integer,Integer> heap2 = state.getHeap();
        IFileTable<Integer,FileData> fileTable2 = state.getFileTable();
        IBarrierTable<Integer, MyPair> barrierTable2 = state.getBarrierTable();


        stack2.push(statement);
        Integer ID = GenIDFork.getID();
        return new PrgState(stack2,dict2,out2,null,fileTable2,heap2,barrierTable2,ID);

    }

    @Override
    public String toString(){
        return "fork("+statement+")";
    }
}
