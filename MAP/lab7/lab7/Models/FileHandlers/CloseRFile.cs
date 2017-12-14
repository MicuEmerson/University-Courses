using System;

namespace lab7.Models.FileHandlers
{
    public class CloseRFile : IStatement
    {
        private IExpression exp;

        public CloseRFile(IExpression exp)
        {
            this.exp = exp;
        }

        public PrgState execute(PrgState state)
        {
            int id = exp.eval(state.Dict);

            if (!state.FileTable.exists(id)) 
                throw new SystemException("This file" + exp + "can't be closed because do not exist");
            
            state.FileTable.get(id).Sw.Close();
            state.FileTable.delete(id);

            return state;
        }

        public override string ToString()
        {
            return "Close(" + exp + ")";
        }
    }
}