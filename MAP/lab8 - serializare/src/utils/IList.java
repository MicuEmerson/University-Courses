package utils;

import java.io.Serializable;

public interface IList<T> extends Serializable {
    public void add(T x);
    public Iterable<T> getAll();
}
