package utils;

import models.Statement;

public interface IExeStack <T>{
    public void push(T x);
    public T pop();
    public boolean isEmpty();
}
