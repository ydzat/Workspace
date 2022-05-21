/*
 * @Author: your name
 * @Date: 2020-06-05 17:59:23
 * @LastEditTime: 2020-06-05 19:32:36
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: \Workspace\Datenstrukturen\PVL5_ver3\proj\Test1.java
 */ 
package PVL5_ver3;

import java.util.Iterator;
//import PVL5_Group13.PVL5_Group13;
//import PVL5_Group13.Set;


public class Test1 {

	public static void main(final String[] args) {
		// #region Variables.
		final PVL5_Group13 set1 = new PVL5_Group13(1);
		final PVL5_Group13 set2 = new PVL5_Group13(2);
		final PVL5_Group13 set3 = new PVL5_Group13(3);
		final PVL5_Group13 set4 = new PVL5_Group13(4);
		final PVL5_Group13 set5 = new PVL5_Group13(5);
		final PVL5_Group13 set6 = new PVL5_Group13(6);
		//#endregion
		


		//#region	Processing the test.
		set1.union(set2).union(set4).union(set5);
		set3.union(set4).union(set5).union(set6);
		Iterator<Set> i = set1.iterator();
		while(i.hasNext())
			System.out.print(((PVL5_Group13) i.next()).getValues());
		System.out.println();
		i = set3.iterator();
		while(i.hasNext())
			System.out.print(((PVL5_Group13) i.next()).getValues());
		System.out.println("\n");

		set1.union(set3);
		i = set1.iterator();
		while(i.hasNext())
			System.out.print(((PVL5_Group13) i.next()).getValues());
		System.out.println("\n");
		
		// set1.cut(set3);
		// i = set1.iterator();
		// while(i.hasNext())
		// 	System.out.print(((PVL5_Group13) i.next()).getValues());
		// System.out.println("\n");

		System.out.println(set1.isSubsetOf(set3));
		System.out.println(set2.isSubsetOf(set1));
		System.out.println(set1.isSubsetOf(set1));
		System.out.println();

		set1.relativeComplementWith(set3);
		i = set1.iterator();
		while(i.hasNext())
			System.out.print(((PVL5_Group13) i.next()).getValues());
		System.out.println("\n");

		System.out.println(set1.equals(set3));
		System.out.println(set2.equals(set1));
		System.out.println(set1.equals(set1));
		System.out.println();

		i = set1.iterator();
		while(i.hasNext())
			System.out.print(((PVL5_Group13) i.next()).getValues());
		System.out.println("\n");
		
		/*
		// Iterator<Set> it = set1.iterator();
		// while(it.hasNext()) {
		// 	System.out.print(((PVL5_Group13) it.next()).getValues());
		// };
		// System.out.println();
		// set1.union(set2);
		// it = set1.iterator();
		// while(it.hasNext()) {
		// 	System.out.print(((PVL5_Group13) it.next()).getValues());
		// };
		// System.out.println();
		// for(var i : set1.asIntList())
		// 	System.out.println(i);
		// System.out.println(set2.isSubsetOf(set1));
		// System.out.println(set1.equals(set1) + "; " + set3.equals(set4));
		// System.out.println(((PVL5_Group13) set1.relativeComplementWith(set2)).getValues());
		*/
		//#endregion



		//#region	Quitting the application properly.
		return;
		//#endregion



	};



};
