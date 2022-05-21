package demo.innerClass.test;

public class test {
	public static void main(String args []) {
		//生成内部类。
		A a = new A();
		A.B b = a.new B();		//A.B b = new A().new B();会有不同的结果
		a.i = 3;
		b.j = 1;
		int result = b.funB();
		System.out.println(result);
		
	}
}
