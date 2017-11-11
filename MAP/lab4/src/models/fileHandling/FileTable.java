package models.fileHandling;

import java.util.HashMap;
import java.util.Map;

public class FileTable <K,V> implements IFileTable <K,V> {

    private Map<K, V> dict = new HashMap<>();

    @Override
    public void add(K key, V val) {
        dict.put(key, val);
    }

    @Override
    public void delete(K key) {
        dict.remove(key);
    }

    @Override
    public V get(K key) {
        return dict.get(key);
    }

    @Override
    public boolean contains(K key) {
        return dict.containsKey(key);
    }

    @Override
    public Iterable<K> getAllKeys() {
        return dict.keySet();
    }

    @Override
    public Iterable<V> getAllValues() {
        return dict.values();
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
