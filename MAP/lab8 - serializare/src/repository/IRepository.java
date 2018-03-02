package repository;

import models.PrgState;

import java.io.Serializable;
import java.util.List;

public interface IRepository extends Serializable {

    public void addPrgState(PrgState st);
    public void logPrgStateExec(PrgState state);
    public List<PrgState> getPrgList();
    public void setPrgList(List<PrgState> list);
}
