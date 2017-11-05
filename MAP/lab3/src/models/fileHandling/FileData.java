package models.fileHandling;

import java.io.BufferedReader;
import java.nio.Buffer;

public class FileData {
    String fileName;
    BufferedReader reader;

    public FileData(String n, BufferedReader r){
        fileName = n;
        r = reader;
    }

    public String getFileName() {
        return fileName;
    }

    public void setFileName(String fileName) {
        this.fileName = fileName;
    }

    public void setReader(BufferedReader reader) {
        this.reader = reader;
    }

    public BufferedReader getReader() {
        return reader;

    }

    @Override
    public String toString(){
        return fileName;
    }
}


