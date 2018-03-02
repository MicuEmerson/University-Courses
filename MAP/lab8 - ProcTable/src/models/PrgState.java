package models;
import exceptions.EmptyStack;
import models.fileHandling.FileData;
import models.fileHandling.FileTable;
import models.fileHandling.IFileTable;
import models.statement.Statement;
import utils.*;

import java.util.ArrayDeque;
import java.util.Deque;


public class PrgState {


    private IExeStack<Statement> stack;
    private Deque<IDictionary> stackSymTable = new ArrayDeque<>();
    //private IDictionary<String, Integer> dict;
    private IList<Integer> list;
    private Statement root;
    private IFileTable<Integer, FileData> fileTable;
    private IHeap<Integer, Integer> heap;
    private Integer ID;
    private IProcTable<String, MyPair> procTable;


    public Deque<IDictionary> copyDequeStack(){
        Deque<IDictionary> newStack = new ArrayDeque<>();
        for(IDictionary x : stackSymTable)
            newStack.push(x.copy());

        return newStack;
    }

    public void setStackSymTable(Deque<IDictionary> stackSymTable) {
        this.stackSymTable = stackSymTable;
    }

    public Deque<IDictionary> getStackSymTable() {
        return stackSymTable;
    }

    public IProcTable<String, MyPair> getProcTable() {
        return procTable;
    }

    public void setProcTable(IProcTable<String, MyPair> procTable) {
        this.procTable = procTable;
    }

    public PrgState(IExeStack<Statement> s, Deque<IDictionary> stackSymTable, IList<Integer> l, Statement r,
                    IFileTable<Integer, FileData> fileTable, IHeap<Integer,
                    Integer> heap, IProcTable<String, MyPair> procTable, Integer ID){
        stack = s;
        this.stackSymTable = stackSymTable;
        list = l;
        root = r;

        this.fileTable = fileTable;

        this.heap = heap;
        this.procTable = procTable;

        this.ID = ID;



    }

    public void pushStackSymTab(IDictionary x){
        stackSymTable.add(x);
    }
    public IDictionary popStackSymTab(){
        return stackSymTable.pop();
    }
    public IDictionary peekStackSymTab(){
        return stackSymTable.peek();
    }


    public IFileTable<Integer, FileData> getFileTable() {
        return fileTable;
    }

    public void setFileTable(IFileTable<Integer, FileData> fileTable) {
        this.fileTable = fileTable;
    }

    public IHeap<Integer, Integer> getHeap() {
        return heap;
    }

    public void setHeap(IHeap<Integer, Integer> heap) {
        this.heap = heap;
    }

    public IExeStack<Statement> getStack(){
        return stack;
    }



    public IList<Integer> getList() {
        return list;
    }

    public Integer getID() {
        return ID;
    }

    public Statement getRoot() {
        return root;
    }

    public void setStack(IExeStack<Statement> s){ stack = s;}

    public void setList(IList<Integer> l) { list = l;}
    public void setRoot(Statement s){ root = s;}
    public boolean isNotCompleted(){
        return !stack.isEmpty();
    }

    public PrgState oneStep(){

        if(stack.isEmpty())
            return null;
            //throw new EmptyStack("Stack is Empty\n");

        Statement st = stack.pop();

        return st.execute(this);
    }

    @Override
    public String toString() {
        StringBuffer str = new StringBuffer();

        str.append("\nExeStack: \n" + this.ID + "\n");
        for(Statement S: stack.getAll())
            str.append(""+ S + '\n');

        /*
        str.append("\nSymTable:\n");
        for(String key: dict.getAll())
            str.append(key + "-->" + dict.getValue(key) +'\n');
        */
        str.append("\nOut:\n");
        for(Integer i: list.getAll())
            str.append(""+i+"\n" );


        str.append("\nFileTable:\n");
        for(Integer i: fileTable.getAllKeys())
            str.append("" + i + fileTable.get(i).getFileName() + "\n");

        str.append("\nHeap:\n");
        for(Integer key: heap.getAll())
            str.append("" +key + heap.get(key) + "\n");

        str.append("\n");

        return str.toString();
    }

}
