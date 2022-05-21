package demo.syn.test;

public class MyThread1 implements Runnable{
	private Service service;
	public MyThread1(Service service) {
		this.service = service;
	}
	public void run() {
		service.fun1();
	}
}
