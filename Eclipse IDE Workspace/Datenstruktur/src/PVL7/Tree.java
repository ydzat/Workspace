package PVL7;

import java.util.ArrayList;

public class Tree {
	private int root;
	private int nNodes;
	private Vertex vertexList[];
	private int adjMat[][];
	private ArrayList<Integer> edges;
	
	Tree(int root, Vertex vertexList[]){
		this.root = root;
		
		this.vertexList = vertexList;
		
		Vertex mid = new Vertex(this.vertexList[0].label);
		
		this.vertexList[0] = this.vertexList[root];
		this.vertexList[root] = mid;
		
		this.nNodes = vertexList.length;
		
		adjMat = new int[nNodes][nNodes];
		
		edges = new ArrayList<Integer>();
	};
	
	public void createTree(int n, int adjMat[][], int flag) {
		this.nNodes = n;
		
		this.adjMat = adjMat;
		
		int mid1[] = new int[n];
		
		mid1 = this.adjMat[0];
		this.adjMat[0] = this.adjMat[root];
		this.adjMat[root] = mid1;
		
		for(int i = 0; i < n; i++) {
			int mid2 = this.adjMat[i][0];
			this.adjMat[i][0] = this.adjMat[i][root];
			this.adjMat[i][root] = mid2;
		};
		
		if(flag == 0) {
			DFS();
		}
		if(flag == 1) {
			BFS();
		}
		
	};
	
	//Feedback -- find the deepest node
	public void DFS() {
		
	};
	
	//
	public void BFS() {
		
	};
	
	public ArrayList<Integer> getEdges(){
		return this.edges;
	};
	
}
