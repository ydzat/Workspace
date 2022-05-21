package sequ2;

public class Test {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		
		//E=0, cb,sl,q00,q01
		boolean E;
		E=false;
		boolean f=false;
		boolean t = true;
		Cacu cal0000 = new Cacu(false,false,false,false,false);
		Cacu cal0001 = new Cacu(E,false,false,false,true);
		Cacu cal0010= new Cacu(E,false,false,true,false);
		Cacu cal0011= new Cacu(E,false,false,true,true);
		Cacu cal0100= new Cacu(E,false,true,false,false);
		Cacu cal0101= new Cacu(E,false,true,false,true);
		Cacu cal0110= new Cacu(E,false,true,true,false);
		Cacu cal0111= new Cacu(E,false,true,true,true);
		Cacu cal1000= new Cacu(E,true,false,false,false);
		Cacu cal1001= new Cacu(E,true,false,false,true);
		Cacu cal1010= new Cacu(E,true,false,true,false);
		Cacu cal1011= new Cacu(E,t,f,t,t);
		Cacu cal1100= new Cacu(E,t,t,f,f);
		Cacu cal1101= new Cacu(E,t,t,f,t);
		Cacu cal1110= new Cacu(E,t,t,t,f);
		Cacu cal1111= new Cacu(E,t,t,t,t);
		
		//E=1
		E = true;
		Cacu cal0000e = new Cacu(false,false,false,false,false);
		Cacu cal0001e = new Cacu(E,false,false,false,true);
		Cacu cal0010e= new Cacu(E,false,false,true,false);
		Cacu cal0011e= new Cacu(E,false,false,true,true);
		Cacu cal0100e= new Cacu(E,false,true,false,false);
		Cacu cal0101e= new Cacu(E,false,true,false,true);
		Cacu cal0110e= new Cacu(E,false,true,true,false);
		Cacu cal0111e= new Cacu(E,false,true,true,true);
		Cacu cal1000e= new Cacu(E,true,false,false,false);
		Cacu cal1001e= new Cacu(E,true,false,false,true);
		Cacu cal1010e= new Cacu(E,true,false,true,false);
		Cacu cal1011e= new Cacu(E,t,f,t,t);
		Cacu cal1100e= new Cacu(E,t,t,f,f);
		Cacu cal1101e= new Cacu(E,t,t,f,t);
		Cacu cal1110e= new Cacu(E,t,t,t,f);
		Cacu cal1111e= new Cacu(E,t,t,t,t);
		System.out.println("=====================================0000");
		cal0000.getArr();
		System.out.println("=====================================0001");
		cal0001.getArr();
		System.out.println("=====================================0010");
		cal0010.getArr();
		System.out.println("=====================================0011");
		cal0011.getArr();
		System.out.println("=====================================0100");
		cal0100.getArr();
		System.out.println("=====================================0101");
		cal0101.getArr();
		System.out.println("=====================================0110");
		cal0110.getArr();
		System.out.println("=====================================0111");
		cal0111.getArr();
		System.out.println("=====================================1000");
		cal1000.getArr();
		System.out.println("=====================================1001");
		cal1001.getArr();
		System.out.println("=====================================1010");
		cal1010.getArr();
		System.out.println("=====================================1011");
		cal1011.getArr();
		System.out.println("=====================================1100");
		cal1100.getArr();
		System.out.println("=====================================1101");
		cal1101.getArr();
		System.out.println("=====================================1110");
		cal1110.getArr();
		System.out.println("=====================================1111");
		cal1111.getArr();
		System.out.println("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE");
		
		
		cal0000e.getArr();
		System.out.println("=====================================0000e");
		cal0001e.getArr();
		System.out.println("=====================================0001");
		cal0010e.getArr();
		System.out.println("=====================================0010");
		cal0011e.getArr();
		System.out.println("=====================================0011");
		cal0100e.getArr();
		System.out.println("=====================================0100");
		cal0101e.getArr();
		System.out.println("=====================================0101");
		cal0110e.getArr();
		System.out.println("=====================================0110");
		cal0111e.getArr();
		System.out.println("=====================================0111");
		cal1000e.getArr();
		System.out.println("=====================================1000");
		cal1001e.getArr();
		System.out.println("=====================================1001");
		cal1010e.getArr();
		System.out.println("=====================================1010");
		cal1011e.getArr();
		System.out.println("=====================================1011");
		cal1100e.getArr();
		System.out.println("=====================================1100");
		cal1101e.getArr();
		System.out.println("=====================================1101");
		cal1110e.getArr();
		System.out.println("=====================================1110");
		cal1111e.getArr();
		System.out.println("=====================================1111");
		
		
		
		
	}

}
