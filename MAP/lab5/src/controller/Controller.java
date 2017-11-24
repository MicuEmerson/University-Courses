package controller;

import models.PrgState;
import models.fileHandling.FileData;
import models.fileHandling.IFileTable;
import models.statement.Statement;
import repository.IRepository;
import utils.IExeStack;
import exceptions.EmptyStack;
import utils.IHeap;

import java.io.IOException;
import java.util.Collection;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class Controller {

    private IRepository repo;

    public Controller(IRepository _repo){
        repo = _repo;
    }

    public void executeOneStep(){

        PrgState program = repo.getCurrentProgram();
        IExeStack<Statement> stack = program.getStack();
        if(stack.isEmpty())
            throw new EmptyStack("Stack is Empty\n");


        Statement st = stack.pop();
        st.execute(program);

        program.getHeap().setContent(this.conservativeGarbageCollector(program.getDict().getAllValues(),program.getHeap()));

        repo.logPrgStateExec();

    }

    public void executeAll(){
        PrgState state = repo.getCurrentProgram();
        IExeStack<Statement> stack = state.getStack();
        IFileTable<Integer, FileData> ft = state.getFileTable();

        repo.logPrgStateExec();
        try {
            while (!stack.isEmpty())
                executeOneStep();
        }
        catch (EmptyStack e){
            System.out.println(e);
        }
        finally {

            ft.getAllValues().stream().forEach(e-> {
                try {
                    e.getReader().close();
                } catch (IOException e1) {
                    e1.printStackTrace();
                }
            });
        }
    }


   private Map<Integer,Integer> conservativeGarbageCollector(List<Integer> symTableValues, IHeap<Integer, Integer> heap){


        return heap.entrySet().stream()
                .filter(e->symTableValues.contains(e.getKey()))
                        .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));

    }






}
