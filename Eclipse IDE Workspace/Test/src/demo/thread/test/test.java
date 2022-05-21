//线程
//特点：没谱。
package demo.thread.test;

public class test {

	public static void main(String[] args) {
		// 生成线程类的对象。方法1
		FirstThread ft = new FirstThread();
		SecondThread st = new SecondThread();
		
		//生成一个Runnable接口实现类的对象。方法2
		RunnalbeImpl ri = new RunnalbeImpl();
		//生成一个Thread对象，并将Runnable接口实现类的对象作为参数传递给该Thread对象
		Thread t = new Thread(ri);
		

		//设置优先级。
		//最大优先级Thread.MAX_PRIORITY为10，最小优先级Thread.MIN_PRIORITY为1
		//优先级越大的程序被执行的概率越大。
		t.setPriority(Thread.MAX_PRIORITY);
		//获取优先级
		System.out.println(t.getPriority());
		
		//启动线程，start()是从Thread中继承而来的。运行此代码后，该程序进入就绪状态
		//ft.run()千万不能这么写，因为这意味着要求先执行run();这就不是多线程了。
		ft.start();
		st.start();
		//通知Thread对象，执行start方法
		t.start();
		
		
		
		for(int i=0; i <100; i++) {
			System.out.println("main -->" + i);
		}
		
	
		
		
	}

}
