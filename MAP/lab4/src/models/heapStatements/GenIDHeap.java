package models.heapStatements;

public class GenIDHeap {
    private static int number=0;
    public static  int getID(){
        return number++;
    }
}
