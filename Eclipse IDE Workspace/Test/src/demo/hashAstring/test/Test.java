package demo.hashAstring.test;

import java.util.*;

public class Test {

	public static void main(String[] args) {
		User u = new User("zhangsan", 12);
		
		HashMap<User, String> map = new HashMap<User, String>();
		//建立映射关系，u和abc作为键
		map.put(u, "abc");
		
		/*建立一个新的User对象，这个对象的值与前面建立的对象u相同。
		通过get()方法来获取这个新的对象的值。
		此时这个新的对象并没有通过put函数来建立映射关系，只有值是与u相同。
		返回的值s等于null。
		因为这个get()是通过哈希code来判断这个对象的
		而每一个对象的哈希code都不同，这时通过新对象的哈希值找到的对象并非u，尽管他们的值相同
		注：此时所用的get()方法中所调用的哈希方法是原始（自带的）的，并没有复写过。
		*/
		String s = map.get(new User("zhangsan",12));
		System.out.println(s);
		/*↑现在已经在User对象中覆写了hashCode()
		覆写的hashCode是根据值生成哈希值，于是上面这个输出的结果是
		abc
		
		*/
		
		User u1= new User("lisi" , 23);
		//toString()是Object中的函数。因此可直接使用
		//其功能是使对象的内容强制转换为字符串
		//目的是增强检查时数据可读性
		//不过一般需要覆写，原始输出的数据挺傻吊的
		//注：此处已经过覆写。
		System.out.println(u1);		
		
		
		
	}

}
