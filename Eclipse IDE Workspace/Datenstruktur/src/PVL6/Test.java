/*
 * @Author: Dongze Yang
 * @Date: 2020-06-05 20:03:53
 * @LastEditTime: 2020-06-06 20:44:16
 * @LastEditors: Dongze Yang
 * @Description: In User Settings Edit
 * @FilePath: \Workspace\Eclipse IDE Workspace\Datenstruktur\src\PVL6\Test.java
 */

package PVL6;

public class Test {

	public static void main(String[] args) {
		//
		PVL6_Group13 scheduler = new PVL6_Group13(2);
		for (int i = 0; i < 254; i++) {
			scheduler.createProcess(0, 3, 10);
		}
		System.out.println(scheduler.createProcess(0, 3, 10));
		System.out.println(scheduler.createProcess(0, 3, 10));
	}

}
