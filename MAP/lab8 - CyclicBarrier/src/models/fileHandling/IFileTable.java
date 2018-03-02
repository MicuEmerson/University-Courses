package models.fileHandling;

import java.io.BufferedReader;
import java.util.Collection;
import java.util.List;

public interface IFileTable<K, V> {
   public void add(K key, V val);
   public void delete(K key);
   public V get(K key);
   public boolean contains(K key);
   public Iterable<K> getAllKeys();
   public Collection<V> getAllValues();

}
