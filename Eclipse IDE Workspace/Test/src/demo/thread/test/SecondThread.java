

package demo.thread.test;


public class SecondThread extends Thread{
	//复写Thread中的run()代码
	public void run() {
		for(int i =0 ; i<100; i++) {
			System.out.println("SecondThread  --> " + i);
		}
	}
}