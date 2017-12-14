namespace lab7.Models
{
    public interface IStatement
    {
        PrgState execute(PrgState state);

    }
}