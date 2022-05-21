//第二个线程，第二种方法。
//用Runnable接口，即实现这个接口，这个接口中只有run()方法。
//这种方法更常用。


package demo.thread.test;

public class RunnalbeImpl implements Runnable{
	public void run() {
		for(int i = 0; i<100; i++) {
			System.out.println("Runnable -->" + i);
			//中断线程sleep()，在执行时，在符合某条件时，休眠。其参数为毫秒。
			//yield()方法。在运行时让出CPU，但让出后也会再去抢CPU。
			if(i == 50) {
				try {
					Thread.sleep(2000);
				}
				catch(Exception e){
					System.out.println(e);
				}
			}
		}
	}
}
