package models;
import utils.*;


public class PrgState {

    private IExeStack<Statement> stack;
    private IDictionary<String, Integer> dict;
    private IList<Integer> list;
    private Statement root;

    public PrgState(IExeStack<Statement> s, IDictionary<String, Integer> d, IList<Integer> l, Statement r){
        stack = s;
        dict = d;
        list = l;
        root = r;
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
        str.append("PrgState{\n");
        str.append("stack{").append(stack).append("}\n");
        str.append("dict{").append(dict).append("}\n");
        str.append("output{").append(list).append("}\n}\n");
        //str.append("root{").append(root).append("}\n}\n");

        return str.toString();
    }

}
