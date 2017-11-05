package models.fileHandling;

import exceptions.fileExceptions.FileAlreadyOpened;
import models.PrgState;
import models.expression.IExpression;
import models.statement.Statement;
import utils.IDictionary;
import utils.IExeStack;

import java.io.BufferedReader;
import java.io.IOException;
import java.nio.Buffer;


public class CloseRFile implements Statement {

    private IExpression exp;

    public CloseRFile(IExpression exp){
        this.exp = exp;
    }

    @Override
    public PrgState execute(PrgState state) {

        IDictionary<String, Integer> dict = state.getDict();
        IFileTable<Integer, FileData> fileTable = state.getFileTable();
        int id = exp.eval(dict);

        boolean ok = false;
        for(Integer d: fileTable.getAllKeys())
            if(id == d)
                ok = true;

        if(!ok)
            throw new FileAlreadyOpened("Can't close the file because don't exist in FileTable");

        FileData fileData = fileTable.get(id);
        BufferedReader bufferedReader = fileData.getReader();

        try {
            bufferedReader.close();
        } catch (IOException e) {
            throw new FileAlreadyOpened("Can't close the file");
        }

        fileTable.delete(id);

        return state;
    }

    @Override
    public String toString(){
        return "close("+exp+")";
    }


}
