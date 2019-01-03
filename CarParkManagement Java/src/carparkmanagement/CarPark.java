/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package carparkmanagement;

/**
 *
 * @author Haig
 */
public class CarPark {
    private String ticket;
    private Space[] spaces = new Space[10];
    private int freeSpaces = 10;
    private int ticketstart = 5000;
    
    CarPark(String input) {
        ticket = input;
        for (int i = 0; i < spaces.length; i++) 
		spaces[i] = new Space(); 
    }
    
    public boolean processTicket() {
        //returns false due to string being empty therefore processing not possible
        if (ticket.isEmpty()) return false;
        //splits string using ', ' delimiter  
        String[] data = ticket.split(", ");
        //cycle through string array of each isntruction, processing instruction depending on first character       
        //could use regular expression, but for more concise code and for the problem requirement the following method is best
	for(int i = 0 ; i < data.length; i ++) 
		if (data[i].charAt(0) == 'p')
                    addSpace(data[i].replaceAll("p", ""));
		else if (data[i].charAt(0) == 'u')
                    removeSpace(Integer.parseInt(data[i].replaceAll("\\D+","")));
		else if (data[i].charAt(0) == 'c') 
                    shuffleSpaces();
        return true;
    }

    private boolean addSpace(String s) {
        
	//if there are no spaces, break
	if (freeSpaces == 0)  return false;
	//cycle through the ten spaces, if empty add current ticketID count and reg no. ticket ++, return true to end for loop;
	for (int i = 0; i < spaces.length; i++)
		if (spaces[i].getEmpty()) {
			spaces[i] = new Space(s, ticketstart); 
                        freeSpaces--;
                        ticketstart++;
			return true;
		}
	return false;
    }
    
    private boolean removeSpace(int tID) {
	//if there are no cars/10 free spaces return
	if (freeSpaces == spaces.length) return false;
	//cycloe through 10 spaces, if ticketID referenced is equal to space[i], clear and add to freespaces
	for (int i = 0; i < spaces.length; i++) 
		if (spaces[i].getticketNumber() == tID)
		{
			spaces[i] = new Space();
			freeSpaces++;
			return true;
		}
	return false;
    }
    
    private void shuffleSpaces() {
	// cycle from first to second from last and check is space is empty
	for (int i = 0; i < 9; i++) 
		if (spaces[i].getEmpty())
			//cycle through from i to find next position that is not empty and move it to i. clear space, e = 9 to end inner for loop
			for (int e = i + 1; e < 9 - i; e++) 
				if (!spaces[e].getEmpty())
				{
                                    //copy constructor moving taken sapce to space to left
					spaces[i] = new Space(spaces[e]);
                                        //reinitialising space
					spaces[e] = new Space();
                                        //sets e to 9 to exit inner forloop and move to next space
					e = 9;
				}
    }
    
    public void print() { 
	//print each space number plate
	for (int i = 0; i < spaces.length; i++)
            System.out.print(spaces[i]);
    }
    
    private class Space
    {
        private String noplate;
        private int ticketnumber;
        private boolean empty = false;
        
        //default constructor for initialising space
        Space() { 
            noplate = ""; 
            ticketnumber = 0; 
            empty = true; 
        }
        
        //assigning car to space with reg, ticketnumber and assigning it is not empty
        Space(String noplat, int ticketnum) { 
	noplate = noplat;
	ticketnumber = ticketnum;
	empty = false; 
        }
        
        //copy constructor for shuffle
        Space(Space s) {
            noplate = s.noplate;
            ticketnumber = s.ticketnumber;
            empty = s.empty;
        }
        
        //returns state of space
        public boolean getEmpty() {
            return empty;
        }
        
        //returns format of toString
        @Override
        public String toString() {
            return noplate + ",";
        }
        
        //returns ticket number
        public int getticketNumber() {
            return ticketnumber;
        }
    }
}



