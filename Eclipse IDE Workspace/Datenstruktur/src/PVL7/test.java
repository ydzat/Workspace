/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */ 
package PVL7;



public class test {

	public static void main(String[] args) {
		
		PVL7_Group13 graph = new PVL7_Group13(4);
		
		System.out.println(graph.setEdge(0, 1));
		System.out.println(graph.setEdge(0, 1));
		System.out.println(graph.setEdge(0, 0));
		System.out.println(graph.setEdge(0, 2));
		System.out.println(graph.setEdge(0, 3));
		System.out.println(graph.setEdge(0, 4));
		System.out.println(graph.setEdge(1, 3));
		System.out.println(graph.setEdge(2, 3));


		
		//graph.graph.DFS();
		//graph.hasFullCircle();
		
		System.out.println(graph.getEdges());

	}

}
