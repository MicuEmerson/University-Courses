using System.Collections;
using lab7.Utils;

namespace lab7.Models
{
    public class AssignStmt : IStatement
    {
        private IExpression exp;
        private string id;

        public AssignStmt(IExpression exp, string id)
        {
            this.exp = exp;
            this.id = id;
        }

        public PrgState execute(PrgState state)
        {
      
            int result = exp.eval(state.Dict);      
            state.Dict.setValue(id,result);

            return state;

        }

        public override string ToString()
        {
            return "Assign(" + id + "=" + exp + ")";
        }
    }
}