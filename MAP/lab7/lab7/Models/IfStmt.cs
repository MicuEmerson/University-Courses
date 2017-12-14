namespace lab7.Models
{
    public class IfStmt : IStatement
    {
        private IStatement thenS;
        private IStatement elseS;
        private IExpression exp;

        public IfStmt(IExpression exp, IStatement thenS, IStatement elseS)
        {
            this.thenS = thenS;
            this.elseS = elseS;
            this.exp = exp;
        }

        public PrgState execute(PrgState state)
        {
            if(exp.eval(state.Dict) != 0)
                state.Stack.push(thenS);
            else
                state.Stack.push(elseS);

            return state;

        }

        public override string ToString()
        {
            return "IF("+ exp + ") THEN(" +thenS + ")ELSE(" + elseS + ")";
        }
    }
}