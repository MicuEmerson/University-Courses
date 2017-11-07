package repository;

import exceptions.fileExceptions.FileException;
import models.PrgState;
import models.fileHandling.FileData;
import models.fileHandling.FileTable;
import models.fileHandling.IFileTable;
import models.statement.Statement;
import utils.IDictionary;
import utils.IExeStack;
import utils.IList;

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
    public PrgState getCurrentProgram() {
        return list.get(0);
    }

    @Override
    public void logPrgStateExec() {

        try(PrintWriter logFile = new PrintWriter(new BufferedWriter(new FileWriter("text2.txt", true)))){
            PrgState state = this.getCurrentProgram();
            IExeStack<Statement> stack = state.getStack();
            IDictionary<String, Integer>dict = state.getDict();
            IList<Integer> out = state.getList();
            IFileTable<Integer, FileData> fileTable = state.getFileTable();

            logFile.println("ExeStack:");
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
                logFile.println("" + i + fileTable.get(i).getFileName() + "\n");


            logFile.println("\n");

        } catch (FileNotFoundException e) {
            throw new FileException("File not found in PrintWriter");
        } catch (IOException e) {
            throw new FileException("IO exception at PrintWriter");
        }

    }
}
