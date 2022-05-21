/*
 * @Author: Dongze Yang
 * @Date: 2020-06-04 19:47:33
 * @LastEditTime: 2020-06-04 20:22:47
 * @Description: In User Settings Edit
 * Wie auch immer, es wird zum Testen verwendet. Sie können diese Datei jederzeit ändern
 */ 
package proj;

import java.util.Iterator;

public class Test {

	public static void main(String[] args) {
		// TODO 
		PVL5_Group13 set1 = new PVL5_Group13(1);
		PVL5_Group13 set2 = new PVL5_Group13(2);
		PVL5_Group13 set3 = new PVL5_Group13(3);
		PVL5_Group13 set4 = new PVL5_Group13(4);
		PVL5_Group13 set5 = new PVL5_Group13(5);
		PVL5_Group13 set6 = new PVL5_Group13(6);
		
		
		
		/*union and relativeComplementWith lauft richtig.
		 * @author Dongze Yang
		 * 
		 * */
		
		set1.union(set2).union(set4).union(set5);
		set3.union(set4).union(set5).union(set6);

		//set1.relativeComplementWith(set3);
		
		set1.cut(set3);
		
		Iterator<Set> it = set1.iterator();
		while(it.hasNext()) {
			System.out.println(it.next().asIntList());
		};
		
		
		
	}

}
