package demo.geld.test;

public class Test {

	public static void main(String[] args) {
		/*
		 总持有 = 100;
		double 箱子 = 16.5, 州票 = 24, 单程票 = 16, 室内单程 = 2.7, 室内24 = 7.6;
		 */
		double inHand = 100;
		double box = 16.5, ticketS = 24, ticketE = 16, cityE = 2.7, cityT = 7.6;
		
		Cacu m1 = new Cacu(4);

		
		double s1 = m1.getBoxGeld() + m1.getTicketSGeld(2) + m1.getCityTGeld(1) ;

		
		System.out.println(s1);

		
	}

}
