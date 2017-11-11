package utils;

import java.util.HashMap;
import java.util.Map;

public class Heap<K, V> implements  IHeap<K, V> {

    Map<K, V> dict = new HashMap<>();

    @Override
    public void add(K key, V value) {
           dict.put(key, value);
    }

    @Override
    public boolean contains(K key) {
         return dict.containsKey(key);
    }

    @Override
    public void update(K key, V value) {
          dict.put(key, value);
    }

    @Override
    public void remove(K key) {
         dict.remove(key);
    }

    @Override
    public V get(K key) {
        return dict.get(key);
    }

    @Override
    public Iterable<K> getAll() {
        return dict.keySet();
    }

    @Override
    public String toString(){
        StringBuffer str = new StringBuffer();
        for(Map.Entry<K, V> e : dict.entrySet()){
            str.append("<"+e.getKey() + ", " + e.getValue() + ">; ");
        }
        return str.toString();
    }

}
