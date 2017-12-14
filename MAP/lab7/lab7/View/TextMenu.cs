using System;
using System.Collections.Generic;

namespace lab7.View
{
    
    public class TextMenu {
        private Dictionary<string, Command> commands;

        public TextMenu()
        {
            commands = new Dictionary<string, Command>();
        }

        public void addCommand(Command c)
        {
            commands[c.getKey()] = c;
        }

        private void printMenu(){
            foreach(Command com in commands.Values)
            {
                string line = string.Format(com.getKey()+" "+  com.getDescription());
                System.Console.WriteLine(line);
            }
        }

        public void show(){
           
            while(true){
                printMenu();
                System.Console.WriteLine("Input the option: ");

                string key = Console.ReadLine();
                
                Command com=commands[key];
                if (com==null){
                    System.Console.WriteLine("Invalid Option");
                    continue; }
                com.execute();
            }
        }
    }
}