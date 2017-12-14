using System;
using lab7.Utils;

namespace lab7.Models
{
    public interface IExpression
    {
        int eval(IDictionary<String, int> dict);
        
    }
}