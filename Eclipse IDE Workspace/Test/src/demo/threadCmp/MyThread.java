package demo.threadCmp;

public class MyThread implements Runnable{
	int i = 100;
	public void run() {
		while(true) {
			//线程同步代码块，this是同步锁。即当运行时，先由线程a运行，此时线程a就占有了这个锁，这个锁只能在其所在代码块完成后，才能给出此锁。
			//持有锁时，不代表会一直占有CPU，中间可能会有其他线程抢到CPU，但由于有此锁，抢到CPU的线程只能等待，让持有锁的线程继续运行
			//其他线程都不能执行这个对象上所有被同步的代码
			synchronized(this){
				//Thread.currentThread()返回一个Thread对象的引用，即正在运行此代码的线程
				System.out.println(Thread.currentThread().getName() + i);
				i--;
				Thread.yield();
				if(i < 0) {
					break;
				}
			}
		}
	}
}
