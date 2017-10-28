package models;

public class Bike extends Vehicle {

	public Bike(String _brand, String _model, String _color) {
		super(_brand, _model, _color);
	}

	
	@Override
	public String toString() {
		return "BIKE [" + "Brand: " + this.brand + ", Model: " + this.model + ", Color: " + this.color + "]"; 
	}

	
	 @Override
	 public boolean equals(Object x) {
	    	
	   	if(x instanceof Bike) {
    		Bike y = (Bike) x;
	    	return y.brand.equals(brand) && y.model.equals(model) && y.color.equals(color);
	   	}	
	  	return false;
	  }
	

}
