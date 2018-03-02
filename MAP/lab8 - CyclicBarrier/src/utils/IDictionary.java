package utils;

import java.util.Collection;
import java.util.List;

public interface IDictionary<K, V>{
    public boolean exists(K key);
    public V getValue(K key);
    public List<V> getAllValues();
    public void setValue(K key, V value);
    public void updateValue(K key, V value);
    public Iterable<K> getAll();
    public void delete(K key);
    public boolean constains(K key);
    public IDictionary<K, V> copy();
}
