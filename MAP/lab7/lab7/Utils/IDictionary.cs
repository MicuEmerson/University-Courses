using System.Collections;

namespace lab7.Utils
{
    public interface IDictionary <K, V> : IEnumerable
    {
         bool exists(K key);
         V getValue(K key);
         void setValue(K key, V value);
         void updateValue(K key, V value);
    }
}