package models.fileHandling;

public class GeneratorInteger {
    public static int counter = 0;
    public static int gen_ID(){
        return counter++;
    }
}
