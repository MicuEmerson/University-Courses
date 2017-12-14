using lab7.Utils;

namespace lab7.Models
{
    public class ConstExp : IExpression
    {
        private int number;

        public ConstExp(int number)
        {
            this.number = number;
        }


        public int eval(IDictionary<string, int> dict)
        {
            return number;
        }

        public override string ToString()
        {
            return " "+ number;
        }
    }
}