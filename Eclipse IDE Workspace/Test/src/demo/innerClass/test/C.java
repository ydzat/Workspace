//这个类的一个成员函数接收接口的一个对象

package demo.innerClass.test;

public class C {
	public void fun(UnknownInnerClass a) {
		System.out.println("C类的fun函数");
		a.doSomething();
	}
}
