package repository;

import exceptions.fileExceptions.FileException;
import models.PrgState;

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
            logFile.println(this.getCurrentProgram());

        } catch (FileNotFoundException e) {
            throw new FileException("File not found in PrintWriter");
        } catch (IOException e) {
            throw new FileException("IO exception at PrintWriter");
        }

    }
}
