using System.IO;

namespace lab7.Models.FileHandlers
{
    public class FileData
    {
        private string name;
        private StreamReader sw;

        public FileData(string name, StreamReader sw)
        {
            this.name = name;
            this.sw = sw;
        }

        public string Name
        {
            get { return name; }
            set { name = value; }
        }

        public StreamReader Sw
        {
            get { return sw; }
            set { sw = value; }
        }
    }
}