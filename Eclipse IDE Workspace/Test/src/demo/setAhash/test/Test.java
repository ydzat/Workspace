//集合中不允许有重复元素
package demo.setAhash.test;

import java.util.Set;
import java.util.HashSet;
import java.util.Iterator;

public class Test {

	public static void main(String[] args) {
		
///////////////////////////////////////////////////////////////////////////////////
		HashSet<String> hashSet = new HashSet<String>();
		//向上转型为Set类型。在开发时经常会预见需要Set对象的程序
		Set<String> set = hashSet;
		
		boolean b1 = set.isEmpty();
		System.out.println("b1: " + b1);
		
		//添加元素
		set.add("a");
		set.add("b");
		set.add("c");
		set.add("d");
		set.add("c");	//因为集合中不允许有重复元素，因此这条会被忽略掉
		
		boolean b2 = set.isEmpty();
		System.out.println("b2: " + b2);
		
		//获取大小
		int i = set.size();
		System.out.println("remove之前" + i);
		//移除元素a
		set.remove("a");
		i = set.size();
		System.out.println("remove之后clear之前" + i);
		//清除元素
		set.clear();
		int j = set.size();
		System.out.println("clear之后" + j);
////////////////////////////////////////////////////////////////////////////////////
		//迭代器Iterator是一个接口<--Collection<--Set<--HashSet。迭代Iterate
		//                                                         <--List<--ArrayList
		//Iterator有两个方法↓
		//hasNext()的返回值是布尔值，表示这个游标后边还有没有元素，若无，则null。
		//next()返回游标所指向元素的下一个元素
	
		set.add("a");
		set.add("b");
		set.add("c");
		set.add("d");
		//调用Set对象的Iterator方法，会生成一个迭代器对象，该对象用于遍历整个Set。即游标。
		//游标初始指向表头，即位于第0个元素之前
		Iterator<String> it = set.iterator();
		
		b1 = it.hasNext();
		
		if(b1) {
			//取得游标下一个元素的值，之后使游标向后移动一位。
			String s = it.next();
			System.out.println("重新加入abcd后，下一个元素不为空，则打印出游标所在下一个元素：" + s);
		}
		b2 = it.hasNext();
		if(b2) {
			String s = it.next();
			System.out.println("重新加入abcd后，下一个元素不为空，则打印出游标所在下一个元素：" + s);
		}
		
		
	}

}
