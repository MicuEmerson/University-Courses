using System;

namespace lab7.View
{
   
    public class RunExample : Command {
    private Controller.Controller ctrl;
    public RunExample(string key, string desc, Controller.Controller ctr) : base(key, desc)
    {
        this.ctrl=ctr;
    }
    
    public override void execute() {

        try
        {
            ctrl.executeAll();
        }
        catch (SystemException e)
        {
            Console.WriteLine(e.Message);
        }
    }
        
    }
}