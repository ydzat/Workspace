package demo.syn.test;

public class MyThread2 implements Runnable{
	private Service service;
	public MyThread2(Service service) {
		this.service = service;
	}
	public void run() {
		service.fun2();
	}
}