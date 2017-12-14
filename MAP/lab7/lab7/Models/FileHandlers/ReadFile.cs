using System;
using System.IO;

namespace lab7.Models.FileHandlers
{
    public class ReadFile : IStatement
    {
        private IExpression expID;
        private string newVarName;

        public ReadFile(IExpression expId, string newVarName)
        {
            expID = expId;
            this.newVarName = newVarName;
        }


        public PrgState execute(PrgState state)
        {
            int id = expID.eval(state.Dict);
            StreamReader sw = state.FileTable.get(id).Sw;

            string line = sw.ReadLine();
            if(line == "")
                throw new SystemException("Can't read the line");
            
            
            int value = int.Parse(line);
            
            state.Dict.setValue(newVarName, value);

            return state;


        }

        public override string ToString()
        {
            return "ReadFile(" + newVarName + ")";
        }
    }
}