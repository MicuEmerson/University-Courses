using System.Collections;

namespace lab7.Utils
{
    public interface IMyList<T> : IEnumerable
    {
        void add(T x);
    }
}