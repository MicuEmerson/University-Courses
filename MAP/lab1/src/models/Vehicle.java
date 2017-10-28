package models;



public abstract class Vehicle {
   
	protected String brand;
	protected String model;
	protected String color;
	
	protected Vehicle(String _brand, String _model, String _color) {
		this.color = _color;
		this.brand = _brand;
		this.model = _model;
	}
	
	public String getColor() { return color; }
	public String getModel() { return model; }
	public String getBrand() { return brand; }
	
	public void setColor(String color) {this.color = color;}
	public void setBrand(String brand) {this.brand = brand;}
	public void setModel(String model) {this.model = model;}

	
}
