package utils;

import java.io.Serializable;

public interface IExeStack <T> extends Serializable {
    public void push(T x);
    public T pop();
    public boolean isEmpty();
    public Iterable<T> getAll();
}
