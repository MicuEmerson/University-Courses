package repository;

import exceptions.FileException;
import models.PrgState;
import models.fileHandling.FileData;
import models.fileHandling.IFileTable;
import models.statement.Statement;
import utils.*;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

public class Repository implements IRepository {

    List<PrgState> list = new ArrayList<>();

    @Override
    public void addPrgState(PrgState x) {
        list.add(x);
    }


    @Override
    public List<PrgState> getPrgList() {
        return list;
    }

    @Override
    public void setPrgList(List<PrgState> list) {
        this.list = list;
    }

    @Override
    public void logPrgStateExec(PrgState state) {


        try(PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter("text2.txt", true)))){

            IExeStack<Statement> stack = state.getStack();
            IDictionary<String, Integer> dict = state.getDict();
            IList<Integer> out = state.getList();
            IFileTable<Integer, FileData> fileTable = state.getFileTable();
            IHeap<Integer, Integer> heap = state.getHeap();
            IBarrierTable<Integer, MyPair> barrierTable = state.getBarrierTable();


            logFile.println("ExeStack: " + state.getID());
            for(Statement S: stack.getAll())
                logFile.println(""+ S);


            logFile.println("\nSymTable:\n");
            for(String key: dict.getAll())
                logFile.println(key + "-->" + dict.getValue(key) +'\n');

            logFile.println("\nOut:\n");
            for(Integer i: out.getAll())
                logFile.println(""+i+"\n" );


            logFile.println("\nFileTable:\n");
            for(Integer i: fileTable.getAllKeys())
                logFile.println("" + i + "-->" + fileTable.get(i).getFileName() + "\n");


            logFile.println("\nHeap:\n");
            for(Integer key: heap.getAll())
                logFile.println(key + "-->" + heap.get(key) +'\n');

            logFile.println("\nBarrierTable:\n");
            for(Integer key: barrierTable.getAll()) {
                String l = new String();
                for(Integer i : barrierTable.get(key).getFirst())
                    l += " "+i;
                logFile.println(key + "-->" + barrierTable.get(key).getSecond() + ", list: "+ l+'\n');
            }

            logFile.println("\n");

        } catch (FileNotFoundException e) {
            throw new FileException("File not found in PrintWriter");
        } catch (IOException e) {
            throw new FileException("IO exception at PrintWriter");
        }

    }
}
