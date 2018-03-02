package models.statement;


import models.PrgState;

import java.io.Serializable;

public interface Statement extends Serializable {
   public PrgState execute(PrgState state);

}
