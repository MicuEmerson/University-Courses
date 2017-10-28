package controller;

import repository.*;
import models.*;

public class Controller {

	private RepoInterface repo;
	
	public Controller(RepoInterface _repo){
		repo = _repo;
	}
	
	public Vehicle convertDataToVehicle(int type, String _brand,  String _model, String _color) throws Exception {
		
		switch(type) {
		case 1:
			return new Car(_brand, _model, _color);
		case 2:
			return new Moto(_brand, _model, _color);
		case 3:
			return new Bike(_brand, _model, _color);
		default:
			throw new Exception("This type of vehicle not exist");
		}	
	}
	
	public void add(Vehicle x) throws Exception {
				
		if(repo.search(x)) 
			throw new Exception("This vehicle is already added");
		else 
			repo.add(x); 
		
	}
	
	public void remove(Vehicle x) throws Exception {
		
		if(!repo.search(x))
			throw new Exception("This vehicle not exist");
		else
			repo.remove(x); 
		
		
	}
	
	public Vehicle[] printAll() {
		return  repo.getAllVehicles();
	}
	
	private int howManyRed() {
		
		int cate = 0;
		
		for(Vehicle i: repo.getAllVehicles())
			if(i.getColor().equals("red"))
				cate++;
		
		return cate;
		
	}
	
	public Vehicle[] printRed() {
		
		Vehicle[] redVehicles = new Vehicle[howManyRed()];
		Vehicle[] allVehicles = repo.getAllVehicles();
		
		for(int i=0, j=0; i<allVehicles.length; i++)  
			if(allVehicles[i].getColor().equals("red")) 
				redVehicles[j++] = allVehicles[i];
				
		return redVehicles;
			
	}
	
	
	
}
