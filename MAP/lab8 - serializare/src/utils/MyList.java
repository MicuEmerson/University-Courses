package utils;

import java.util.ArrayList;
import java.util.List;

public class MyList<T> implements IList<T> {

    List <T> l = new ArrayList<>();
    @Override
    public void add(T x) {
         l.add(x);
    }

    @Override
    public Iterable<T> getAll() {
        return l;
    }

    @Override
    public String toString(){
        StringBuffer buff = new StringBuffer();

        for(T i: l)
            buff.append(i + " ");

        return buff.toString();
    }
}
