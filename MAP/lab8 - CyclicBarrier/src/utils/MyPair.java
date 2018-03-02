package utils;

import java.util.ArrayList;
import java.util.List;

public class MyPair {
    ArrayList<Integer> first;
    Integer second;

    public ArrayList<Integer> getFirst() {
        return first;
    }

    public void setFirst(ArrayList<Integer> first) {
        this.first = first;
    }

    public void setSecond(Integer second) {
        this.second = second;
    }

    public Integer getSecond() {

        return second;
    }

    public MyPair(ArrayList<Integer> first, Integer second) {
        this.first = first;
        this.second = second;

    }
}
