using System;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using lab7.Models;
using lab7.Utils;
using System.IO;
using lab7.Models.FileHandlers;

namespace lab7.Controller
{
    public class Controller
    {
        private PrgState state;
        
        public Controller(PrgState state)
        {
            this.state = state;
        }

        public void printState(PrgState state)
        {
            using (StreamWriter sw = File.AppendText("C:\\Users\\Emy\\RiderProjects\\lab7\\text.txt"))
            {
                sw.WriteLine("\nStack: ");
                foreach (var i in state.Stack)
                {
                       sw.WriteLine(i);
                }
                
                sw.WriteLine("\nDict: ");
                foreach (KeyValuePair<string, int> kvp  in state.Dict)
                {
                       sw.WriteLine(kvp.Key + " --> " + kvp.Value);
                }
 
                sw.WriteLine("\nOutput: ");
                foreach (var i in state.OutList)
                {
                      sw.WriteLine(i);
                }
                
                sw.WriteLine("\nFileTable: ");
                foreach (KeyValuePair<int, FileData> kvp  in state.FileTable)
                {
                    sw.WriteLine(kvp.Key + " --> " + kvp.Value.Name);
                }
                
                sw.WriteLine("\n");
            }
        }

        public void executeOneStep(){
             
            IExeStack<IStatement> stack = state.Stack;
            
            IStatement statement = stack.pop();
            
            statement.execute(state);
            printState(state);
        }

        public void executeAll()
        {

            IExeStack<IStatement> stack = state.Stack;

            while(!stack.isEmpty())
                executeOneStep();
            
        }
        
    }
}