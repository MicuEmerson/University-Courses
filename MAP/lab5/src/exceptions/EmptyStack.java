package exceptions;

public class EmptyStack extends RuntimeException{

    public EmptyStack(String s){
        super(s);
    }
}
