package models;

public class Car extends Vehicle{
	
	public Car(String _brand, String _model, String _color) {
		super(_brand, _model, _color);
	}


	@Override
	public String toString() {
		return "CAR [" + "Brand: " + this.brand + ", Model: " + this.model + ", Color: " + this.color + "]"; 
	}
 
	@Override
	public boolean equals(Object x) {
	    	
	    	if(x instanceof Car) {
	    		Car y = (Car) x; 
	    		return y.brand.equals(brand) && y.model.equals(model) && y.color.equals(color);
	    	}
	    	
	    	return false;
    }
	
}
