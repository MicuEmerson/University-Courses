package models.statement;

import models.PrgState;
import models.fileHandling.FileData;
import models.fileHandling.IFileTable;
import utils.*;

import java.util.ArrayDeque;
import java.util.Deque;

public class ForkStmt implements Statement {

    Statement statement;

    public ForkStmt(Statement statement) {
        this.statement = statement;
    }


    @Override
    public PrgState execute(PrgState state) {

        IExeStack<Statement> stack2 = new ExeStack<>();
        IList<Integer> out2 = state.getList();
        IHeap<Integer,Integer> heap2 = state.getHeap();
        IFileTable<Integer,FileData> fileTable2 = state.getFileTable();
        Deque<IDictionary> stackSymTable2 = state.copyDequeStack();
        IProcTable<String, MyPair> procTable2 = state.getProcTable();

        stack2.push(statement);
        Integer ID = GenIDFork.getID();
        return new PrgState(stack2,stackSymTable2,out2,null,fileTable2,heap2,procTable2,ID);

    }

    @Override
    public String toString(){
        return "fork("+statement+")";
    }
}
