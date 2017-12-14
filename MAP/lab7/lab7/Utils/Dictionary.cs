using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;

namespace lab7.Utils
{
    public class MyDictionary<K, V> : IDictionary<K, V>
    {
        private Dictionary<K, V> dict = new Dictionary<K, V>();
          
        public bool exists(K key)
        {
            return dict.ContainsKey(key);
        }

        public V getValue(K key)
        {
            return dict[key];
        }

      
        public void setValue(K key, V value)
        {
            dict[key] = value;
        }

        public void updateValue(K key, V value)
        {
            dict[key] = value;
        }


        public IEnumerator GetEnumerator()
        {
            return dict.GetEnumerator();
        }
    }


}