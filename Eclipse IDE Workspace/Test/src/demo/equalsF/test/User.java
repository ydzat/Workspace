package demo.equalsF.test;

public class User {
	String name;
	int age;
	
	public User() {
		
	}
	
	public User(String name, int age) {
		this.name = name;
		this.age = age;
		
	}
	
	
	//复写equals
	public boolean equals(Object obj) {
		//这个this是User类型的
		//首先判断这个this和obj是不是指向堆内存中的同一个对象
		if(this == obj) {
			System.out.println("this和obj是同一个对象");
			return true;
		}
		
		//instanceof用于判断对象的类型是否是特定类的一个实例
		//判断obj是否是User类型
		//如果是属于User类型，则返回true。
		boolean b = obj instanceof User;
		
		if(b) {
			System.out.println("obj是User的对象");
			//如果obj是User类型
			//把obj向下转型为User类型
			User u = (User)obj;
			
			//判断u这个对象和this这个对象的值是否相等
			//此处之所以需要用equals进行比较，是因为String是属于引用数据类型
			//引用数据类型不能通过==进行比较，即并非判断地址
			//equals判断的是值是否相等
			if(this.age == u.age && this.name.equals(u.name)) {
				return true;
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
}
