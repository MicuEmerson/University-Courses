package repository;

import models.PrgState;

import java.util.List;

public interface IRepository {

    public void addPrgState(PrgState st);
    public void logPrgStateExec(PrgState state);
    public List<PrgState> getPrgList();
    public void setPrgList(List<PrgState> list);
}
