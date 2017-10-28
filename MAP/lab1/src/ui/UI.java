package ui;
import controller.Controller;
import models.Vehicle;

import java.util.Scanner;

public class UI {

	 private Controller ctrl;
	 private Scanner keyboard;
	 
	 public UI(Controller _ctrl) {
		 ctrl = _ctrl;
		 keyboard = new Scanner(System.in);
	 }
	 
	 private void menu() {
		 System.out.println("\t\tWelcome");
		 System.out.println("\t1)Add");
		 System.out.println("\t2)Remove");
		 System.out.println("\t3)Print All");
		 System.out.println("\t4)Print Red");
		 System.out.println("\t0)Exit");
		 
	 }
	 
	 private void vehicleTypes() {
		 System.out.println("\t1)Car");
		 System.out.println("\t2)Moto");
		 System.out.println("\t3)Bike");
	 }
	 
	 private Vehicle readData() throws Exception{
		 
		 String brand, model, color;
		 int type;
		 
		 vehicleTypes();
		 type = keyboard.nextInt();
		 keyboard.nextLine();
		 System.out.println("\tBrand:");
		 brand = keyboard.nextLine();
		 
		 System.out.println("\tModel:");
		 model = keyboard.nextLine();
		 
		 System.out.println("\tColor:");
		 color = keyboard.nextLine();
		 
		 return ctrl.convertDataToVehicle(type, brand, model, color) ;
	 }
	 
	 private void printVehicles(Vehicle[] myArray) {
		 
		 for(Vehicle i: myArray)
			 System.out.println(i);
		 
	 }
	 
	 public void run() {
		 
		 int cmd = 0;
		 
		 while(true) {
			 
			 
			 try {
			  this.menu();
			  cmd = keyboard.nextInt();
			  if(cmd < 0 || cmd > 4)
				  throw new Exception("Please select only one number from the console");
			 }
			 catch(Exception e) {
				 System.out.println(e.getMessage());
			 }
		
			 try {
				 if(cmd == 1) {
					 Vehicle x = readData();
					 ctrl.add(x);
				 }
				 else if(cmd == 2) {
					 Vehicle x = readData();
					 ctrl.remove(x);
				 }
				 else if(cmd == 3) {
					 printVehicles(ctrl.printAll());
				 }
				 else if(cmd == 4) {
					 printVehicles(ctrl.printRed());
				 }
				 else if(cmd == 0){
					 break;
				 }
			 }
			 catch(Exception e) {
				 System.out.println(e.getMessage());
			 }
			
		 }
		 
	 }
	
}
