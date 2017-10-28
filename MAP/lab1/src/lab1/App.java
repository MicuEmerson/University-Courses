package lab1;
import models.*;
import repository.*;
import controller.Controller;
import ui.UI;


public class App {
	
    
	public static void main(String[] args)   {
	   
		Vehicle a = new Car("BMW", "X5", "red");		
		Vehicle b = new Moto("Suzuki", "Ninja", "black");
		Vehicle c = new Bike("MountainBike", "PathFinder", "white");
		Vehicle d = new Car("BMW", "M6", "blue");
		Vehicle e = new Moto("Yamaha", "Runner", "red");
		Vehicle f = new Bike("BMX", "Nuj", "blue");
		
		RepoInterface repo = new Repository();
		
		repo.add(a); repo.add(b); repo.add(c); repo.add(d); repo.add(e); repo.add(f);
		
		Controller ctrl = new Controller(repo);
		UI ui = new UI(ctrl);
		ui.run();
		
	
	
	}

	
}
