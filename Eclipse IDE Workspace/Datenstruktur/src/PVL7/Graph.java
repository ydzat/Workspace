package PVL7;

import java.util.LinkedList;
import java.util.List;

public class Graph {
	private int MAX_VERTS;
	private Vertex vertexList[];
	private int adjMat[][];
	private int nVerts;
	private dfsStack theStack;
	
	public Graph(int n) {
		this.MAX_VERTS = n;
		vertexList = new Vertex[MAX_VERTS];
		adjMat = new int[MAX_VERTS][MAX_VERTS];
		nVerts = 0;
		
		for(int i = 0; i < MAX_VERTS; i++) {
			for(int j = 0 ; j < MAX_VERTS; j++) {
				adjMat[i][j] = 0;
			};
			addVertex(i);
		};
		
		theStack = new dfsStack(MAX_VERTS);
		
	};
	
	public void addVertex(int label) {
		vertexList[nVerts++] = new Vertex(label);
	};
	
	public boolean addEdge(int i, int j) {
		if( (i < 0 || i >=MAX_VERTS) ||  (j < 0 || j >=MAX_VERTS) ) {
			return false;
		}
		if(i == j) {
			return false;
		}
		if(adjMat[i][j] == 1) {
			return false;
		}
		else {
			adjMat[i][j] = 1;
			adjMat[j][i] = 1;
			return true;
		}
	};
	
	public void displayVertex(int v) {
		System.out.println(vertexList[v].label);
	};
	
	public void DFS() {
		vertexList[0].wasVisited = true;
		
		displayVertex(0);
		
		theStack.push(0);
		
		while(!theStack.isEmpty()) {
			int i = getAdjUnvisitedVertex(theStack.getThis());
			if(i == -1) {
				theStack.pop();
			}
			else {
				vertexList[i].wasVisited = true;
				displayVertex(i);
				theStack.push(i);
			};
		};
		
		for(int i = 0; i < nVerts; i++) {
			vertexList[i].wasVisited = false;
		};
	};
	
	public int getAdjUnvisitedVertex(int n) {
		for(int i = 0; i < nVerts; i++) {
			if(adjMat[n][i] == 1 && vertexList[i].wasVisited == false) {
				return i;
			}
		};
		return -1;
	};
	
	//hasFullCircle
	public Boolean spanningTreeDFS(int root) {
		
		
		return false;
	};
	
	public Boolean spanningTreeBFS(int root) {
		Tree tree = new Tree(root, vertexList);
		tree.createTree(MAX_VERTS, adjMat, 1);
		
		return false;
	};
	
	public List<List<Integer>> BFS(){
		List<List<Integer>> edgeList = new LinkedList<List<Integer>>();

		for(int i = 0; i < this.MAX_VERTS; i++) {
			List<Integer> temp = new LinkedList<Integer>();
			for(int j = 0 ; j < this.MAX_VERTS; j++) {
				if(this.adjMat[i][j] == 1) {
					temp.add(j);
				};
			};
			edgeList.add(temp);
		};

		return edgeList;
	};
	
	//TODO: hasFullCircle()
	public Boolean DFS_1() {
		
		return false;
	};
	
	
}
