package models;
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

    public void setDict(IDictionary<String, Integer> dict) {
        this.dict = dict;
    }

    public IFileTable<Integer, FileData> getFileTable() {
        return fileTable;
    }

    public void setFileTable(FileTable<Integer, FileData> fileTable) {
        this.fileTable = fileTable;
    }

    public PrgState(IExeStack<Statement> s, IDictionary<String, Integer> d, IList<Integer> l, Statement r, IFileTable<Integer, FileData> fileTable){
        stack = s;
        dict = d;
        list = l;
        root = r;
        this.fileTable = fileTable;
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

    public Statement getRoot() {
        return root;
    }

    public void setStack(IExeStack<Statement> s){ stack = s;}
    public void setDictionary(IDictionary<String, Integer> d){ dict = d;}
    public void setList(IList<Integer> l) { list = l;}
    public void setRoot(Statement s){ root = s;}



    @Override
    public String toString() {
        StringBuffer str = new StringBuffer();

        str.append("\nExeStack:\n");
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

        str.append("\n");
        /*
        str.append("PrgState{\n");
        str.append("stack{").append(stack).append("}\n");
        str.append("dict{").append(dict).append("}\n");
        str.append("output{").append(list).append("}\n");
        str.append("fileTable{").append(fileTable).append("}\n\n}");
        //str.append("root{").append(root).append("}\n}\n");
        */
        return str.toString();
    }

}
