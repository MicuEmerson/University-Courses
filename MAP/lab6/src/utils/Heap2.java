package utils;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class Heap2<K,V> implements Map<K,V>{
    Map<K, V> dict = new HashMap<>();

    @Override
    public int size() {
        return 0;
    }

    @Override
    public boolean isEmpty() {
        return false;
    }

    @Override
    public boolean containsKey(Object key) {
        return dict.containsKey(key);
    }

    @Override
    public boolean containsValue(Object value) {
        return false;
    }

    @Override
    public V get(Object key) {
        return null;
    }

    @Override
    public V put(K key, V value) {
       return dict.put(key, value);
    }

    @Override
    public V remove(Object key) {
        return dict.remove(key);
    }

    public void update(K key, V value) {
        dict.put(key, value);
    }

    @Override
    public void putAll(Map<? extends K, ? extends V> m) {
           ;
    }

    @Override
    public void clear() {
         ;
    }

    @Override
    public Set<K> keySet() {
        return dict.keySet();
    }

    @Override
    public Collection<V> values() {
        return dict.values();
    }

    @Override
    public Set<Entry<K, V>> entrySet() {
        return dict.entrySet();
    }
}
