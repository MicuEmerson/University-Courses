using System;
using lab7.Utils;

namespace lab7.Models
{
    public class VarExp : IExpression
    {
        private String id;

        public VarExp(string id)
        {
            this.id = id;
        }

        public int eval(IDictionary<string, int> dict)
        {
            return dict.getValue(id);
        }

        public override string ToString()
        {
            return id;
        }
    }
}