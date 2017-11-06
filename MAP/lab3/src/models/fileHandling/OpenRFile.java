package models.fileHandling;

import exceptions.fileExceptions.FileException;
import models.PrgState;
import models.statement.Statement;
import utils.IDictionary;

import java.io.*;


public class OpenRFile implements Statement {

    private String fileName;
    private String varName;

    public OpenRFile(String varName, String fileName) {
        this.fileName = fileName;
        this.varName = varName;
    }

    @Override
    public PrgState execute(PrgState state) {

        IFileTable<Integer, FileData> fileTable = state.getFileTable();
        IDictionary<String, Integer> dict = state.getDict();
        BufferedReader reader;

        for(FileData d: fileTable.getAllValues()) {
            if (d.getFileName().equals(fileName))
                throw new FileException("The file is already opened in FileTable");
        }

        try{
            reader = new BufferedReader(new FileReader(fileName));
         } catch (IOException e) {
             throw new FileException("File not found");
         }

         int id = GeneratorInteger.gen_ID();

         fileTable.add(id, new FileData(fileName, reader));
         dict.setValue(varName, id);

         return state;
    }

    @Override
    public String toString(){
           return "open("+varName+", "+fileName+')';
    }

}
