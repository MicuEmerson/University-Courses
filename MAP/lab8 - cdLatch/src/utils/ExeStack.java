package utils;

import java.util.ArrayDeque;
import java.util.Deque;

public class ExeStack<T> implements IExeStack<T> {

    private Deque<T> stack = new ArrayDeque<>();

    @Override
    public void push(T x) {
         stack.push(x);
    }

    @Override
    public T pop() {

        return stack.pop();
    }

    @Override
    public boolean isEmpty() {
        return stack.size() == 0;
    }

    @Override
    public Iterable<T> getAll() {
        return stack;
    }

    @Override
    public String toString(){
        StringBuffer str = new StringBuffer();
        for(T i : stack){
            str.append(i);
        }
        return str.toString();
    }
}
