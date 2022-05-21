package demo.syn.test;

public class Service {
	public void fun1() {
		//注：此处原有一个同步代码块，用于演示同步代码块究竟锁住了什么。答：对象。
		try {
			Thread.sleep(3 * 1000);
		}
		catch(Exception e) {
			System.out.println(e);
		}
		System.out.println("fun1");
		
	}
	
	
	//这个是“同步方法”，锁住的是this。当一个线程去调用一个对象的同步方法时，这个对象的其他同步方法也不能被其他线程使用。
	public synchronized void fun2() {
		//注：此处原有一个同步代码块，用于演示究竟锁住了什么。
		
		System.out.println("fun2");
		
	}
	
	
}
