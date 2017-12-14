using System;
using System.Collections;
using lab7.Utils;

namespace lab7.Models
{
    public class PrintStmt : IStatement
    {
        private IExpression exp;

        public PrintStmt(IExpression exp)
        {
            this.exp = exp;
        }

        public PrgState execute(PrgState state)
        {
  
            int result = exp.eval(state.Dict);          
            state.OutList.add(result);
            
            return state;
        }

        public override string ToString()
        {
            return "Print(" + exp + ")";
        }
    }
}