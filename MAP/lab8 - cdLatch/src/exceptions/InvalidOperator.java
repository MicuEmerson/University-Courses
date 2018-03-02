package exceptions;

public class InvalidOperator extends RuntimeException {
    public InvalidOperator(String s){
        super(s);
    }
}
