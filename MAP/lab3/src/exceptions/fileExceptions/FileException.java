package exceptions.fileExceptions;

public class FileException extends RuntimeException {
    public FileException(){}
    public FileException(String msg){
        super(msg);
    }
}
