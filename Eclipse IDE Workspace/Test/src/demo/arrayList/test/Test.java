package demo.arrayList.test;

import java.util.ArrayList;

public class Test {

	public static void main(String[] args) {
		/*这种写法JDK1.5之后会收到警告。这个对象的长度是动态的
		ArrayList arrayList = new ArrayList();*/
		//JDK1.5之后要求书写对象
		ArrayList<String> arrayList = new ArrayList<String>();
		
		//向表中添加数据
		arrayList.add("a");
		arrayList.add("b");
		arrayList.add("c");
		
		//取出对象，此时输出b
		String s = arrayList.get(1);
		System.out.println(s);
		
		
		//移除表中元素
		arrayList.remove(1);
		
		
		
		//获取表的长度
		int a = arrayList.size();
		for(int i = 0; i < a; i++) {
			String s1 = arrayList.get(i);
			System.out.println(s1);
		}

	}

}
