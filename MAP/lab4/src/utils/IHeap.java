package utils;

public interface IHeap<K, V> {
    public void add(K key, V value);
    public boolean contains(K key);
    public void update(K key, V value);
    public void remove(K key);
    public V get(K key);
    public Iterable<K> getAll();
}
