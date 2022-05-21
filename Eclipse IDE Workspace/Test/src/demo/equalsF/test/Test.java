//equals是用于比较连个对象的内容是否相等
//相等时一般符合两个条件：
//1.对象的类型相同（可以使用instanceof操作符进行比较）；
//2.两个对象的成员变量的值完全相同

package demo.equalsF.test;

import java.util.*;

public class Test {

	public static void main(String[] args) {
		User u1 = new User();
		User u2 = new User();
		
		u1.name = "张三";
		u1.age = 18;
		u2.name = "李四";
		u2.age = 20;
		
		User u3 = u1;
		/*
		//用==判断堆内存中地址是否相同，==的优先级比=高
		boolean b1 = u1 == u2;
		boolean b2 = u1 == u3;
		
		System.out.println(b1);
		System.out.println(b2);
		*/
		
		//原始equals的功能就是==的功能，因此当使用时，一般都需要复写
		boolean b1 = u1.equals(u2);
		boolean b2 = u1.equals(u3);
		System.out.println(b1);
		System.out.println(b2);
		
		

	}

}
