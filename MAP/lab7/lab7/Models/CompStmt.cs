namespace lab7.Models
{
    public class CompStmt : IStatement
    {
        private IStatement first;
        private IStatement second;

        public CompStmt(IStatement first, IStatement second)
        {
            this.first = first;
            this.second = second;
        }
        
        public PrgState execute(PrgState state)
        {
            state.Stack.push(second);
            state.Stack.push(first);
            return state;
        }

        public override string ToString()
        {
            return "[" + first + ";" + second +"]";
        }

       
    }
}