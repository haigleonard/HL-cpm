/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package carparkmanagement;

import java.util.Scanner;

/**
 *
 * @author Haig
 */
public class CarParkManagement {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        //input string
        Scanner sc = new Scanner(System.in); 
	String input = sc.nextLine();
	//insatnce of Manage passing s, can be empty for default constructor for test string
	//set ticket
	CarPark carpark = new CarPark(input);
	//processes string
	carpark.processTicket();
	//prints state of car park
        carpark.print();
    }
    
}
