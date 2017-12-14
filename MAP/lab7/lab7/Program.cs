using System;
using System.Collections.Generic;
using lab7.Models;
using lab7.Utils;
using lab7.Controller;
using lab7.Models.FileHandlers;
using lab7.View;

namespace lab7
{
    internal class Program
    {
        public static void Main(string[] args)
        {
            IExeStack<IStatement> stack = new ExeStack<IStatement>();
            Utils.IDictionary<string, int> dict = new MyDictionary<string,int>();
            IMyList<int> output = new MyList<int>();
            FileTable<int, FileData> fileTable = new FileTable<int, FileData>();

            IStatement s1 = new OpenRFile("var_f", "C:\\Users\\Emy\\RiderProjects\\lab7\\text1.txt");
            IStatement s2 = new ReadFile(new VarExp("var_f"), "var_c");
            IStatement thenS1 = new ReadFile(new VarExp("var_f"), "var_c");
            IStatement thenS2 = new PrintStmt(new VarExp("var_c"));
            IStatement thenS = new CompStmt(thenS1, thenS2);
            IStatement elseS = new PrintStmt(new ConstExp(0));

            IStatement s3 = new IfStmt(new VarExp("var_c"), thenS, elseS);
            IStatement s4 = new CloseRFile(new VarExp("var_f"));

            IStatement s5 = new CompStmt(s1,s2);
            IStatement s6 = new CompStmt(s3, s4);
            IStatement s7 = new CompStmt(s5, s6);
            
            stack.push(s7);
            
            PrgState state = new PrgState(dict, stack, output, fileTable);
            Controller.Controller ctrl = new Controller.Controller(state);
            
            
            TextMenu menu = new TextMenu();
            menu.addCommand(new ExitCommand("0", "exit"));
            menu.addCommand(new RunExample("1",  "example_1", ctrl));
            menu.show();
            
        }
    }
}