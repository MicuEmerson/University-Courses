package controller;

import exceptions.ControllerException;
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
import java.util.concurrent.*;
import java.util.stream.Collectors;

public class Controller {

    private IRepository repo;
    private ExecutorService executor;

    public Controller(IRepository _repo){
        repo = _repo;
    }


    public List<PrgState> removeCompletedPrg(List<PrgState> l){
        return l.stream().filter(e-> e.isNotCompleted())
                         .collect(Collectors.toList());
    }



    public void oneStepForAll(List<PrgState> list)  {


        List<Callable<PrgState>> callList = list.stream()
                                            .map((PrgState p) -> (Callable<PrgState>)(() -> {return p.oneStep();}))
                                            .collect(Collectors.toList());


        List<PrgState> newList = null;
        try {
            newList = executor.invokeAll(callList)
                                                .stream()
                                                .map(  future ->
                                                {
                                                    try {
                                                        return future.get();
                                                    } catch (InterruptedException e) {
                                                        throw new ControllerException(e.getMessage());
                                                    } catch (ExecutionException e) {
                                                        throw new ControllerException(e.getMessage());
                                                    }
                                                })
                                                .filter(p -> p != null)
                                                .collect(Collectors.toList());
        } catch (InterruptedException e) {
            throw new ControllerException(e.getMessage());
        }



        list.forEach(prg-> repo.logPrgStateExec(prg));
        list.addAll(newList);
        repo.setPrgList(list);

    }




    public void allStep() {
        executor = Executors.newFixedThreadPool(2);

        List<PrgState> prgList = removeCompletedPrg(repo.getPrgList());

        prgList.forEach(prg->repo.logPrgStateExec(prg));

        while(prgList.size() > 0){

            oneStepForAll(prgList);
            prgList = removeCompletedPrg(repo.getPrgList());

        }

        executor.shutdownNow();

        repo.setPrgList(prgList);
    }



   private Map<Integer,Integer> conservativeGarbageCollector(List<Integer> symTableValues, IHeap<Integer, Integer> heap){

        return heap.entrySet().stream()
                .filter(e->symTableValues.contains(e.getKey()))
                        .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }






}
