package exceptions.fileExceptions;

public class FileAlreadyOpened extends RuntimeException {
    public FileAlreadyOpened(){}
    public FileAlreadyOpened(String msg){
        super(msg);
    }
}
