//装饰者设计模式
//AWorker是装饰者，而Plumber和Carpenter的对象是被装饰者
//被装饰者是用于实现具体功能。而装饰者是用于被装饰者的基础上，添加新的功能。


package demo.IObuffered.test;

public class Test2 {

	public static void main(String[] args) {
		//生成一个A公司水管工对象
		Plumber plumber = new Plumber();
		AWorker aWorker = new AWorker(plumber);
		aWorker.work();

		
		Carpenter carpenter = new Carpenter();
		AWorker aWorker2 = new AWorker(carpenter);
		aWorker2.work();
	}

}
