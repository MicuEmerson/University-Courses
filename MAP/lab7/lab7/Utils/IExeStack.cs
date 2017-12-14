using System.Collections;

namespace lab7.Utils
{
    public interface IExeStack<T> : IEnumerable
    {
         void push(T x);
         T pop();
         bool isEmpty();
    }
}