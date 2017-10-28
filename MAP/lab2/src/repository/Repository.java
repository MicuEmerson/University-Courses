package repository;

import models.PrgState;
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
}
