package models.statement;

public class GenCountDownLatchID{
        private static int number=1;
        public static  int getID(){
            return number++;
        }
}
