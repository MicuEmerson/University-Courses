namespace lab7.View
{
    public abstract  class Command  {
        public string key, description;
        public Command(string key, string description) { this.key = key; this.description = description;}
        public abstract void execute();
        public string getKey(){return key;}
        public string getDescription(){return description;}
    }
}