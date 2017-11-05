package repository;

import models.PrgState;

public interface IRepository {

    public void addPrgState(PrgState st);
    public  PrgState getCurrentProgram();
}
