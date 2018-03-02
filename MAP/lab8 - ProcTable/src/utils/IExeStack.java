package utils;

public interface IExeStack <T>{
    public void push(T x);
    public T pop();
    public boolean isEmpty();
    public Iterable<T> getAll();
}
