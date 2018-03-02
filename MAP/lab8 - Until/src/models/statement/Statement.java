package models.statement;


import models.PrgState;

public interface Statement {
   public PrgState execute(PrgState state);

}
