package models;
import exceptions.EmptyStack;
import models.fileHandling.FileData;
import models.fileHandling.FileTable;
import models.fileHandling.IFileTable;
import models.statement.Statement;
import utils.*;


public class PrgState {

    private IExeStack<Statement> stack;
    private IDictionary<String, Integer> dict;
    private IList<Integer> list;
    private Statement root;
    private IFileTable<Integer, FileData> fileTable;
    private IHeap<Integer, Integer> heap;
    private ILatchTable<Integer, Integer> latchTable;
    private Integer ID;



    public PrgState(IExeStack<Statement> s, IDictionary<String, Integer> d, IList<Integer> l, Statement r,
                    IFileTable<Integer, FileData> fileTable, IHeap<Integer, Integer> heap,
                    ILatchTable<Integer, Integer> latchTable, Integer ID){
        stack = s;
        dict = d;
        list = l;
        root = r;
        this.fileTable = fileTable;
        this.heap = heap;
        this.latchTable = latchTable;
        this.ID = ID;
    }


    public ILatchTable<Integer, Integer> getLatchTable() {
        return latchTable;
    }

    public void setLatchTable(ILatchTable<Integer, Integer> latchTable) {
        this.latchTable = latchTable;
    }

    public void setDict(IDictionary<String, Integer> dict) {
        this.dict = dict;
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

    public IDictionary<String, Integer> getDict() {
        return dict;
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
    public void setDictionary(IDictionary<String, Integer> d){ dict = d;}
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

        str.append("\nSymTable:\n");
        for(String key: dict.getAll())
            str.append(key + "-->" + dict.getValue(key) +'\n');

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
