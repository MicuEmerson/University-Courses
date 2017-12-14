using System;


namespace lab7.View
{
    public class ExitCommand : Command {
    public ExitCommand(string key, string desc) : base(key, desc){}
 
    
    public override void execute()
    {
        Environment.Exit(0);
    }
    }
}