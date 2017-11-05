package models.fileHandling;

import exceptions.fileExceptions.FileAlreadyOpened;
import models.PrgState;
import models.expression.IExpression;
import models.statement.Statement;
import utils.IDictionary;

import java.io.BufferedReader;
import java.io.IOException;

public class ReadFile implements Statement {

    IExpression exp;
    String varName;

    public ReadFile(IExpression exp, String varName) {
        this.exp = exp;
        this.varName = varName;
    }


    @Override
    public PrgState execute(PrgState state) {

        IDictionary<String, Integer> dict = state.getDict();
        IFileTable<Integer, FileData> fileTable = state.getFileTable();
        int id = exp.eval(dict);


        if(!fileTable.contains(id))
            throw new FileAlreadyOpened("This ID is not in FileTable");

        BufferedReader reader = fileTable.get(id).getReader();

        String line = null;
        try {
            line = reader.readLine();
        } catch (IOException e) {
            throw new FileAlreadyOpened("Can't read line");
        }

        int value = 0;
        if(line != null)
            value = Integer.parseInt(line);

        dict.setValue(varName, value);

        return state;
    }
}
