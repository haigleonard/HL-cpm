/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package carparkmanagement;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author Haig
 */
public class CarPark {
    String ticket;
    Space[] spaces = new Space[10];
    int freeSpaces = 10;
    int ticketstart = 5000;
    
    CarPark(String input) {
        ticket = input;
        for (int i = 0; i < 10; i++) 
		spaces[i] = new Space(); 
    }
    
    public boolean ProcessTicket() {
        
        if (ticket.isEmpty()) return false;
        
        String[] data = ticket.split(", ");
                
	for(int i = 0 ; i < data.length; i ++) 
		if (data[i].charAt(0) == 'p')
                    addSpace(data[i].replaceAll("(?:\\b)[a-z]*(?:\\b)", "").replace("  ", " "));
		else if (data[i].charAt(0) == 'u')
                    removeSpace(Integer.parseInt(data[i].replaceAll("\\D+","")));
		else if (data[i].charAt(0) == 'c') 
                    shuffle();
        return true;
    }

    public boolean addSpace(String s) {
	//if there are no spaces, break
	if (freeSpaces == 0)  return false;
	//cycle through the ten spaces, if empty add current ticketID count and reg no. ticket ++, return true to end for loop;
	for (int i = 0; i < 10; i++)
		if (spaces[i].getEmpty()) {
			spaces[i] = new Space(s, ticketstart); 
                        freeSpaces--;
                        ticketstart++;
			return true;
		}
	return false;
    }
    
    boolean removeSpace(int tID) {
	//if there are no cars/10 free spaces return
	if (freeSpaces == 10) return false;
	//cycloe through 10 spaces, if ticketID referenced is equal to space[i], clear and add to freespaces
	for (int i = 0; i < 10; i++) 
		if (spaces[i].getticketNumber() == tID)
		{
			spaces[i].clear();
			freeSpaces++;
			return true;
		}
	return false;
    }
    
    void shuffle() {
	// cycle from first to second from last and check is space is empty
	for (int i = 0; i < 9; i++) 
		if (spaces[i].getEmpty())
			//cycle through from i to find next position that is not empty and move it to i. clear space, e = 9 to end inner for loop
			for (int e = i + 1; e < 9 - i; e++) 
				if (!spaces[e].getEmpty())
				{
					spaces[i] = new Space(spaces[e]);
					spaces[e].clear();
					e = 9;
				}
    }
    
    public void print() { 
	//print each space number plate
	for (int i = 0; i < 10; i++)
            System.out.print(spaces[i]);
    }
    
    public class Space
    {
        String noplate;
        int ticketnumber;
        boolean empty = false;
        
        Space() { 
            noplate = ""; 
            ticketnumber = 0; 
            empty = true; 
        }
        
        Space(String noplat, int ticketnum) { 
	noplate = noplat;
	ticketnumber = ticketnum;
	empty = false; 
        }
        
        Space(Space s) {
            noplate = s.noplate;
            ticketnumber = s.ticketnumber;
            empty = s.empty;
        }
        
        public boolean getEmpty() {
            return empty;
        }
        
        @Override
        public String toString() {
            return noplate + ",";
        }
        
        public String getnoPlate() { 
            if (!empty) return noplate;
            else return ""; 
        }
        
        //returns ticket number if empty is not true/filled
        public int getticketNumber() {
            if (!empty) return ticketnumber;
            else return 0;
        }

        //sets space to empty (number plate to clear (""), tickernumber equalling 0 and empty to true)
        public void clear() { 
                noplate = ""; 
                ticketnumber = 0; 
                empty = true; 
        }     
    }
}



