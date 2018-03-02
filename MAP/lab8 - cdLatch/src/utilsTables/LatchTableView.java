package utilsTables;

import javafx.beans.property.SimpleIntegerProperty;


public class LatchTableView {
    private SimpleIntegerProperty address, value, ba;

    public LatchTableView(Integer address, Integer value) {
        this.address = new SimpleIntegerProperty(address);
        this.value = new SimpleIntegerProperty(value);

    }


    public SimpleIntegerProperty baProperty() {
        return ba;
    }

    public void setAddress(int address) {
        this.address.set(address);
    }

    public void setValue(int value) {
        this.value.set(value);
    }



    public SimpleIntegerProperty addressProperty() {
        return address;
    }

    public int getValue() {
        return value.get();
    }

    public SimpleIntegerProperty valueProperty() {
        return value;
    }
}
