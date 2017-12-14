using System.Collections;
using System.Collections.Generic;

namespace lab7.Models.FileHandlers
{
    public class FileTable <K, V> :  IEnumerable
    {
        Dictionary<K, V> fileTable = new Dictionary<K, V>();

        public void add(K key, V value)
        {
            fileTable[key] = value;
        }

        public void delete(K key)
        {
            fileTable.Remove(key);
        }

        public bool exists(K key)
        {
            return fileTable.ContainsKey(key);
        }

        public V get(K key)
        {
            return fileTable[key];
        }

        public void update(K key, V value)
        {
            fileTable[key] = value;
        }

        public bool constainKey(K key)
        {
            return fileTable.ContainsKey(key);
        }

        public bool constainValue(V value)
        {
            return fileTable.ContainsValue(value);
        }

        public IEnumerable allValues()
        {
            return fileTable.Values;
        }

        public IEnumerator GetEnumerator()
        {
            return fileTable.GetEnumerator();
        }
    }
}