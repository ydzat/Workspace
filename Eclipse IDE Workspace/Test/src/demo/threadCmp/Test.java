//线程a b 应该轮流运行
//多线程同步错误：
/*
	多线程共用同一份数据时会产生这种错误。
 	解决方法：同步代码块synchronized(this){}



*/


package demo.threadCmp;

public class Test {

	public static void main(String[] args) {

		MyThread myThread = new MyThread();
		//生成两个Thread对象，但是这两个Thread对象共用同一个线程体
		Thread t1 = new Thread(myThread);
		Thread t2 = new Thread(myThread);
		//每一个线程都有名字，可以通过Thread对象的setName()方法设置现成名字，也可以使用getName方法获取线程名字；
		t1.setName("线程a");
		t2.setName("线程b");
		
		
		//分别启动两个线程
		t1.start();
		t2.start();

	}

}
