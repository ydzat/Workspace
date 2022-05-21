package PVL8;

import java.util.Arrays;

public class test {

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		Graph_II graph = new PVL8_Group13(6);
		
		graph.setEdge(0,1); //true 
		graph.setEdge(0,1); //false 
		graph.setEdge(0,2); //true 
		graph.setEdge(1,2); //true
		graph.setEdge(2,3); //true
		graph.setEdge(3,4); //true 
		graph.setEdge(3,5); //true 
		graph.setEdge(4,5); //true
		
		graph.getEdges();
		
		System.out.println(graph.hasWay(1, 5));
		System.out.println(graph.isConnected(Arrays.asList(0,1,3)));
		
	}

}
