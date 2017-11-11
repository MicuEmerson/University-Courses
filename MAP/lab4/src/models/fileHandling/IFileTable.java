package models.fileHandling;

public interface IFileTable<K, V> {
   public void add(K key, V val);
   public void delete(K key);
   public V get(K key);
   public boolean contains(K key);
   public Iterable<K> getAllKeys();
   public Iterable<V> getAllValues();

}
