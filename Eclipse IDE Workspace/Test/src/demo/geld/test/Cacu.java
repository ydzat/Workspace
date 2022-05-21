package demo.geld.test;

public class Cacu {
	
	int boxZ;
	
	double inHand = 100;
	double box = 16.5, ticketS = 24, ticketE = 16, cityE = 2.7, cityT = 7.6;
	
	public Cacu(int boxZ) {
		this.boxZ = boxZ;
	}
	
	double getBoxGeld() {
		return boxZ * boxZ;
	}
	
	double getTicketSGeld(int i) {
		return ticketS * i;
	}
	
	double getTicketEGeld(int i) {
		return ticketE * i;
	}
	
	double getCityEGeld(int i) {
		return cityE * i;
	}
	
	double getCityTGeld(int i) {
		return cityT * i;
	}
	
	
	
	
	
	
	
	
	
	
	
}
