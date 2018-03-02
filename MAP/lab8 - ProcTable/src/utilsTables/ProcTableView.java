package utilsTables;

import javafx.beans.property.SimpleIntegerProperty;
import javafx.beans.property.SimpleStringProperty;

public class ProcTableView{

    private SimpleStringProperty fname;
    private SimpleStringProperty body;

    public ProcTableView(String fname, String body) {
        this.fname =  new SimpleStringProperty(fname);
        this.body =  new SimpleStringProperty(body);
    }

    public String getFname() {
        return fname.get();
    }

    public void setFname(String fname) {
        this.fname.set(fname);
    }

    public void setBody(String body) {
        this.body.set(body);
    }

    public SimpleStringProperty fnameProperty() {
        return fname;
    }

    public String getBody() {
        return body.get();
    }

    public SimpleStringProperty bodyProperty() {
        return body;
    }
}
