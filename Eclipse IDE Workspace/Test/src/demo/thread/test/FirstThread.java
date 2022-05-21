//第一个线程类，第一种实现方法
//然而并不推荐用继承的方法，因为只能有1个父类

package demo.thread.test;

public class FirstThread extends Thread{
	//复写Thread中的run()代码
	public void run() {
		for(int i = 0 ; i<100; i++) {
			System.out.println("FirstThread  --> " + i);
		}
	}
}
