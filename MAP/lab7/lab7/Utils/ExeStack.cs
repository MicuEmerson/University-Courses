using System.Collections;
using System.Collections.Generic;
using System.Linq;

namespace lab7.Utils
{
    public class ExeStack<T> : IExeStack<T>
    {
        private Stack<T> stack = new Stack<T>();


        public void push(T x)
        {
            stack.Push(x);
        }

        public T pop()
        {
            return stack.Pop();
        }

        public bool isEmpty()
        {
            return stack.Count == 0;
        }

        public IEnumerator GetEnumerator()
        {
            return stack.GetEnumerator();
        }
    }
}