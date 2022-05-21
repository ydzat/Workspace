//一旦一个线程获得了一个对象的同步锁，那么这个对象的所有其他的同步的代码，都不能被其他代码执行

package demo.syn.test;

public class Test {

	public static void main(String[] args) {
		Service service = new Service();
		Thread t1 = new Thread(new MyThread1(service));
		Thread t2 = new Thread(new MyThread2(service));
		
		t1.start();
		t2.start();

	}

}
