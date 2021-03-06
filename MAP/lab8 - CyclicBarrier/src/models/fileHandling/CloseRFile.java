package models.fileHandling;

import exceptions.FileException;
import models.PrgState;
import models.expression.IExpression;
import models.statement.Statement;
import utils.IDictionary;
import utils.IHeap;

import java.io.BufferedReader;
import java.io.IOException;


public class CloseRFile implements Statement {

    private IExpression exp;

    public CloseRFile(IExpression exp){
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) {

        IDictionary<String, Integer> dict = state.getDict();
        IFileTable<Integer, FileData> fileTable = state.getFileTable();
        IHeap<Integer, Integer> heap = state.getHeap();
        int id = exp.eval(dict, heap);


        if(!fileTable.contains(id))
            throw new FileException("Can't close the file because don't exist in FileTable");

        FileData fileData = fileTable.get(id);
        BufferedReader bufferedReader = fileData.getReader();

        try {
            bufferedReader.close();
        } catch (IOException e) {
            throw new FileException("Can't close the file");
        }

        fileTable.delete(id);
        //dict.delete();

        return null;
    }

    @Override
    public String toString(){
        return "close("+exp+")";
    }


}
