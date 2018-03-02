package sample;

import exceptions.ControllerException;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import models.PrgState;
import models.fileHandling.FileData;
import models.fileHandling.IFileTable;
import models.statement.Statement;
import repository.IRepository;
import utils.IExeStack;
import exceptions.EmptyStack;
import utils.IHeap;

import java.io.*;
import java.util.ArrayList;
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
        executor = Executors.newFixedThreadPool(5);
    }


    public int noPrgStates(){
        return repo.getPrgList().size();
    }

    public PrgState getPrgStateByIndex(int index){
       return  repo.getPrgList().get(index);
    }

    public ObservableList<String> getPrgStatesID(){
        ObservableList<String> list = FXCollections.observableArrayList();
        for(PrgState i : repo.getPrgList())
           list.add( String.valueOf(i.getID()));

        return list;
    }

    public  void serializare(){
        try (ObjectOutputStream oos=new ObjectOutputStream(new FileOutputStream("serializare.txt")))
        {
            oos.writeObject(repo.getPrgList().get(0));

        } catch (IOException e) {
            e.printStackTrace();
        }


    }

    public void deserializare(){
        try(ObjectInputStream str= new ObjectInputStream (new FileInputStream("serializare.txt")))
        {
            Object o =str.readObject();
            if(o instanceof PrgState){
                System.out.println((PrgState)o);
            }

        }
        catch(Exception e1){
            throw new RuntimeException("Eroare: "+e1);
        }
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




        list.addAll(newList);
        list.forEach(prg-> repo.logPrgStateExec(prg));

        repo.setPrgList(list);

    }



    public boolean oneStepGUI (){

        List<PrgState> prgList = removeCompletedPrg(repo.getPrgList());

        if(prgList.size() > 0){
            oneStepForAll(prgList);
            prgList = removeCompletedPrg(repo.getPrgList());
            return true;
        }
        else{
            executor.shutdownNow();
            repo.setPrgList(prgList);
            return false;
        }



    }







    /*
   private Map<Integer,Integer> conservativeGarbageCollector(List<Integer> symTableValues, IHeap<Integer, Integer> heap){

        return heap.entrySet().stream()
                .filter(e->symTableValues.contains(e.getKey()))
                        .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }
    */

}
