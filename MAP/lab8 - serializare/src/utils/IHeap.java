package utils;

import java.io.Serializable;
import java.util.Map;
import java.util.Set;

public interface IHeap<K, V>  extends Serializable {
    public void add(K key, V value);
    public boolean contains(K key);
    public void update(K key, V value);
    public void remove(K key);
    public V get(K key);
    public Iterable<K> getAll();
    public void setContent(Map<K,V> m);
    public Set<Map.Entry<K, V>> entrySet() ;
}
