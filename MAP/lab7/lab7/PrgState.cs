using System.Collections;
using lab7.Models;
using lab7.Models.FileHandlers;
using lab7.Utils;

namespace lab7
{
    public class PrgState
    {
        private IDictionary<string, int> dict;
        private IExeStack<IStatement> stack;
        private IMyList<int> outList;
        private FileTable<int, FileData> fileTable;

        public PrgState(IDictionary<string, int> dict, IExeStack<IStatement> stack, IMyList<int> outList, FileTable<int, FileData> fileTable)
        {
            this.dict = dict;
            this.stack = stack;
            this.outList = outList;
            this.fileTable = fileTable;
        }

        public IDictionary<string, int> Dict
        {
            get { return dict; }
            set { dict = value; }
        }

        public FileTable<int, FileData> FileTable
        {
            get { return fileTable; }
            set { fileTable = value; }
        }

        public IExeStack<IStatement> Stack
        {
            get { return stack; }
            set { stack = value; }
        }

        public IMyList<int> OutList
        {
            get { return outList; }
            set { outList = value; }
        }
    }
}