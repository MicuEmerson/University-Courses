package repository;
import models.Vehicle;


public class Repository implements RepoInterface {
	
	private Vehicle[] myArray;
	private int currentIndex;

	
	public Repository() {
		
		myArray = new Vehicle[100];
		currentIndex = 0;
		
	}
	
	public void resize() {
		
		Vehicle[] newArray = new Vehicle[myArray.length * 2];
		for(int i=0; i<currentIndex; i++)
		     newArray[i] = myArray[i];
		
		myArray = newArray;
	}
	
	public boolean search(Vehicle x) {
		
		for(int i=0; i<currentIndex; i++)
			if(myArray[i].equals(x))
				return true;
		return false;
	}
	
	@Override
	public void add(Vehicle x) {
      
		if(currentIndex == myArray.length)
			this.resize();
		
		myArray[currentIndex++] = x;
	}
	
    
	@Override
	public void remove(Vehicle x) {
	
		for(int i=0; i<currentIndex; i++)
			if(myArray[i].equals(x)) {
				myArray[i] = myArray[currentIndex];
		        currentIndex--;
		        return;
			}
		
 	}
	
	@Override
	public Vehicle[] getAllVehicles() {
		
		Vehicle [] returnedArray = new Vehicle[currentIndex];
		for(int i=0; i<currentIndex;i++)
			returnedArray[i] = myArray[i];
		
		return returnedArray;
	}

}
