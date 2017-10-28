package models;

public class Moto extends Vehicle {
		
	
	public Moto(String _brand, String _model, String _color) {
		super(_brand, _model, _color);
	}

	
	@Override
	public String toString() {
		return "MOTO [" + "Brand: " + this.brand + ", Model: " + this.model + ", Color: " + this.color + "]"; 
	}
   
    @Override
    public boolean equals(Object x) {
    	
    	if(x instanceof Moto) {
    		Moto y = (Moto) x;
    		return y.brand.equals(brand) && y.model.equals(model) && y.color.equals(color);
    	}
    	
    	return false;
    }
	

}
