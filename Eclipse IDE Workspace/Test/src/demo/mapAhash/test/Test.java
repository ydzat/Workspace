package demo.mapAhash.test;

import java.util.Map;
import java.util.HashMap;

public abstract class Test {

	public static void main(String[] args) {
		//因为键值对是两个对象，因此需要声明键和值的类型
		HashMap<String,String> hashMap = new HashMap<String, String>();
		//向上转型为Map，以此使用put()方法。
		Map<String,String> map = hashMap;
		
		map.put("1", "a");
		map.put("2", "b");
		map.put("3", "c");
		map.put("4", "d");
		map.put("5", "e");
		
		int i = map.size();
		System.out.println(i);
		
		String temp = map.get("3");
		System.out.println(temp);
		
	}

}
