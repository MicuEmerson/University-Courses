using System.Collections;
using System.Collections.Generic;
using System.IO;

namespace lab7.Utils
{
    public class MyList<T> : IMyList<T>
    {
        private List<T> list = new List<T>();

        public void add(T x)
        {
            list.Add(x);
            
        }

        public IEnumerator GetEnumerator()
        {
            return list.GetEnumerator();
        }
    }
}