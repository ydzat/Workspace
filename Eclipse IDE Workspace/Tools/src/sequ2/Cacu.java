package sequ2;

import java.util.*;



public class Cacu {
	
	
	ArrayList<QTab> Tab;
	

	
	boolean q0;
	boolean q1;
	boolean E;
	
	
	
	Cacu(boolean E, boolean cb, boolean sl,boolean q_00,boolean q_01){
		Tab = new ArrayList<QTab>();

		
		//设定初始
		this.q0 = jk(j0(cb,sl,E),k0(cb,sl,E),q_00);
		this.q1 = jk(j1(cb,sl,q0),k1(cb,sl,q0),q_01);
		this.E= E;
		QTab temp0 = new QTab();
		temp0.set(cb,sl,q0,q1);
		Tab.add(temp0);
		
		cacu();
		
		
	}
	
	public void getArr() {
		System.out.println("CB SL q1 q0");
		for(int i = 0; i < Tab.size(); i++) {
			Tab.get(i).getdata();
		}
	}
	
	public void cacu() {
		
		QTab temp0= new QTab();
		QTab temp1= new QTab();
		QTab temp2= new QTab();
		
		boolean q001 = jk(j0(false,true,E),k0(false,true,E),q0);
		boolean q101 = jk(j1(false,true,q001),k1(false,true,q001),q1);
		//System.out.println("q001 = " + q001 + " q101 = " + q101);
		temp0.set(false,true,q001,q101);
		Tab.add(temp0);
		

		boolean q010 = jk(j0(true,false,E),k0(true,false,E),q001);
		boolean q110 = jk(j1(true,false,q010),k1(true,false,q010),q101);
		temp1.set(true,false,q010,q110);
		Tab.add(temp1);
		
		
		
		boolean q011 = jk(j0(true,true,E),k0(true,true,E),q010);
		boolean q111 = jk(j1(true,true,q011),k1(true,true,q011),q110);
		temp2.set(true, true, q011, q111);
		Tab.add(temp2);
	}
	
	
	
	public boolean j0(boolean cb, boolean sl, boolean E) {
		return (cb && (!sl)) || (((!cb) && sl)&&E);
	} 
	
	public boolean k0(boolean cb, boolean sl, boolean E) {
		return (cb && (!sl)) || (((!cb) && sl)&&(!E));
	}
	
	public boolean jk(boolean j, boolean k,boolean q) {

		if(j==false && k==false && q==false) {
			//000=0
			return false;
		}
		if(j==false && k==false && q==true) {
			//001=1
			return true;
		}
		if(j==false && k==true && q==false) {
			//010=0
			return false;
		}
		if(j==false && k==true && q==true) {
			//011=0
			return false;
		}
		
		if(j==true && k==false && q==false) {
			//100=1
			return true;
		}
		if(j==true && k==false && q==true) {
			//101=1
			return true;
		}
		if(j==true && k==true && q==false) {
			//110=1
			return true;
		}
		if(j==true && k==true && q==true) {
			//111=0
			return false;
		}	
		return false;
	}
	
	
	public boolean j1(boolean cb, boolean sl, boolean jk1) {
		boolean res=((cb && (!sl) && (!jk1)) || ((!cb)&&sl&&jk1));
		//System.out.println("j1 = "+cb +" "+ sl + " " + jk1 + " res = " + res);
		return res;
	}
	
	public boolean k1(boolean cb, boolean sl, boolean jk1) {
		boolean res = ((cb && (!sl) && (!jk1)) || ((!cb)&&sl&&(!jk1)));
		//System.out.println("k1 = "+cb +" "+ sl + " " + jk1 + " res = " + res);
		return res;
	}
	
	
	
}
