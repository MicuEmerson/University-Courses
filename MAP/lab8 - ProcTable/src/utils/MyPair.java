package utils;

import models.statement.Statement;

import java.util.ArrayList;

public class MyPair {

    ArrayList<String> list = new ArrayList<>();
    Statement statement;

    public MyPair(ArrayList<String> list, Statement statement) {
        this.list = list;
        this.statement = statement;
    }

    public void setList(ArrayList<String> list) {
        this.list = list;

    }

    public void setStatement(Statement statement) {
        this.statement = statement;
    }

    public ArrayList<String> getList() {
        return list;
    }

    public Statement getStatement() {
        return statement;
    }


}
