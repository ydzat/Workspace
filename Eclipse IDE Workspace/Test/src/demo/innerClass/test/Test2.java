package demo.innerClass.test;

public class Test2 {

	public static void main(String[] args) {
		//生成一个实现类
		UICImpl al = new UICImpl();
		//将实现类向上转型为接口的对象
		UnknownInnerClass a = al;
		//生成一个需要接口对象的C类对象
		C c = new C();
		//将由接口的实现类UICImpl的对象向上转型为接口的对象后，将此对象传递给需要接口对象的C类
		c.fun(a);
		

		/*匿名内部类实现方法：
		 
		 C c = new C();
		 c.fun(new A(){			从这开始的程序块就是一个匿名内部类，且没有名字，这个内部类实现了接口，因此可以得到接口对象
		 	public void doSomethin(){
		 		System.out.println("匿名内部类");
		 	}
		 })
		  
		  
		  
		 */
		
		
		
		

	}

}
