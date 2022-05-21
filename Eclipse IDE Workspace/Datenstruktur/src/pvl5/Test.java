package pvl5;

public class Test {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		PVL5_Group13 set1 = new PVL5_Group13(1);
		PVL5_Group13 set2 = new PVL5_Group13(2);
		PVL5_Group13 set3 = new PVL5_Group13(3);
		PVL5_Group13 set4 = new PVL5_Group13(4);
		PVL5_Group13 set5 = new PVL5_Group13(5);
		PVL5_Group13 set6 = new PVL5_Group13(6);
		
		set1.union(set2).union(set4).union(set5);
		set3.union(set4).union(set5).union(set6);
		
		set1.iterator();
		
		
	}

}
