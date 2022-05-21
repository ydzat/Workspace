//因为其接口不能生成对象，因此需要一个实现类。

package demo.innerClass.test;

public class UICImpl implements UnknownInnerClass{
	public void doSomething() {
		System.out.println("doSomething");
	}
}
