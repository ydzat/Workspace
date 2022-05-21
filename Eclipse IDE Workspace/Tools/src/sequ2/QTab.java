package sequ2;

public class QTab {
	public boolean cb;
	public boolean sl;
	public boolean q0;
	public boolean q1;
	
	public void set(boolean cb, boolean sl, boolean q0, boolean q1){
		this.cb = cb;
		this.sl = sl;
		this.q0 = q0;
		this.q1 = q1;
	}
	
	public void getdata() {
		int tcb = cb ? 1:0;
		int tsl = sl ? 1:0;
		int tq0 = q0 ? 1:0;
		int tq1 = q1 ? 1:0;
		
		//System.out.println(cb + " " + sl + " " + q0 + " " + q1);
		
		System.out.println(tcb + "    " + tsl + "    " + tq1 + "    " + tq0);
	}
	
	
}
