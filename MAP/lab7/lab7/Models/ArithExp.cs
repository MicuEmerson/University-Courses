using System;
using lab7.Utils;

namespace lab7.Models
{
    public class ArithExp : IExpression
    {
        private IExpression st;
        private IExpression dr;
        private char op;

        public ArithExp(IExpression st, IExpression dr, char op)
        {
            this.st = st;
            this.dr = dr;
            this.op = op;
        }


        public int eval(IDictionary<string, int> dict)
        {
            int vst = st.eval(dict);
            int vdr = dr.eval(dict);

            if (op == '+')
                return vst + vdr;
            if (op == '-')
                return vst - vdr;
            if (op == '*')
                return vst * vdr;
            else
            {
                if (vdr == 0)
                    throw new DivideByZeroException();
                else
                    return vst / vdr;
            }
        }
        
        public override string ToString()
        {
            return "" + st + op + dr;
        }




    }
}
