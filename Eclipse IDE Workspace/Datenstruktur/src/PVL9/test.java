package PVL9;

public class test {

	public static void main(String[] args) {
		
		Graph_III graph_1 = new PVL9_Group13(7);
		
		System.out.println(graph_1.setEdge(0, 1));
		System.out.println(graph_1.setEdge(1,2));
		System.out.println(graph_1.setEdge(2,3));
		System.out.println(graph_1.setEdge(3,4));
		System.out.println(graph_1.setEdge(0,5));
		System.out.println(graph_1.setEdge(1,5));
		System.out.println(graph_1.setEdge(5,6));
		System.out.println(graph_1.setEdge(6,3));
		System.out.println(graph_1.getEdges());
		

	}

}
