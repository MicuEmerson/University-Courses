package repository;

import models.Vehicle;

public interface RepoInterface {
	
	public void add(Vehicle x);
	public void remove(Vehicle x);
	public boolean search(Vehicle x);
	public Vehicle[] getAllVehicles();
	
}
