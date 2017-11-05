package utils;

public interface IDictionary<K, V>{
    public boolean exists(K key);
    public V getValue(K key);
    public void setValue(K key, V value);
    public void updateValue(K key, V value);
    public Iterable<K> getAll();
}
