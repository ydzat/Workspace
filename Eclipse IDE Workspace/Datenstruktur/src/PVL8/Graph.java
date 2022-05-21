/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| Graph.java:                                                                  |
|      Graph class                                                             |
|                                                                              |
| V1.0.0-en_GB // (20200611/20200611)                                          |
| (C) 2020 Dongze Yang (574145)                                                |
|                                                                              |
\******************************************************************************/

/*CHANGELOG********************************************************************\
|                                                                              |
|                                                                              |
|                                                                              |
|                                    CAPTION                                   |
|                                                                              |
| + feature added                                                              |
| - feature removed                                                            |
| > feature imported                                                           |
| ! bugfix                                                                     |
| ? feature idea left for future version                                       |
| * information                                                                |
|   (editing periods in brackets behind version                                |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.0.0-en_GB // (20200611/20200611):                                         |
| + made it work as it should and not only as it was coded                     |
|                                                                              |
|                                                                              |
|                                                                              |
\******************************************************************************/

/*TODO*************************************************************************\
|                                                                              |
| Nothing left to do!                                                          |
|                                                                              |
\******************************************************************************/

/*TESTING INFORMATION**********************************************************\
|                                                                              |
|                                                                              |
|                                                                              |
\******************************************************************************/



//#region	Package.
// package ;
package PVL8;
//#endregion

//#region	Resources.
import java.util.LinkedList;
import java.util.List;
//#endregion

//#region	Class definition: Graph.
/**
 * Graph class
 *
 * @author	Dongze Yang
 * @version	V1.0.0-en_GB // (20200611/20200611)
 */
public class Graph
{
	//#region	Instance variables.
	private int MAX_VERTS;					//Maximum number of nodes
	private Vertex vertexList[];			//Node list
	private int adjMat[][];					//Edge list: if node 0 und 2 was connected, than it has "adjMat[0][2] == adjMat[2][0] == 1", otherwise == 0
	private int nVerts;						//number of nodes
	private dfsStack theStack;				//Stack for DFS operation
	
	private UnionFind UF;				//+++
	//#endregion

	//#region	Class variables.
	/** Some more code here… */
	//#endregion

	//#region	Constructors.
	/** Some more code here… */
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
		
		UF = new UnionFind(n);			//+++
		
	};
	//#endregion

	//#region	Getters and setters.
	/** Some more code here… */
	//#endregion

	//#region	Instance methods.
	
	public void addVertex(int label) {
		vertexList[nVerts++] = new Vertex(label);
	};

	/**
  	* @description: Complete the work of setEdge().
  	* @param: "label" is the value of the node 
	* @return: false -> when this edge is exist. otherwise return true.
	*/
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
			UF.union(i, j);			// +++
			return true;
		}
	};
	
	/**
	* @description: Depth-first traversal. But I actually didn't use it. 
	*	But maybe you need it, so I did not delete it.
  	*/
	public void DFS() {
		vertexList[0].wasVisited = true;
		
		
		theStack.push(0);
		
		while(!theStack.isEmpty()) {
			int i = getAdjUnvisitedVertex(theStack.getThis());
			if(i == -1) {
				theStack.pop();
			}
			else {
				vertexList[i].wasVisited = true;
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
	
	/**
  	* @description: finish the job of getEdges(). Actually, there is no traversal~
  	*/
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
	
	//TODO: hasFullCircle() should be writed here. 
	public Boolean DFS_1() {
		
		return false;
	};
	//#endregion

	//===================================================================
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	public boolean hasWay(int source, int destin) {
		return UF.hasWay(source, destin);
	};
	
	public boolean isConnected(List<Integer> nodes) {
		int n = nodes.size();
		Graph_II temp = new PVL8_Group13(n);
		
		for(int i = 0; i < n/2; i++) {
			for(int j = i+1; j <n; j++) {
				if(adjMat[nodes.get(i)][nodes.get(j)] == 1) {
					temp.setEdge(nodes.get(i), nodes.get(j));
				};
			};
		};
		
		return temp.isConnected();
	};
	
	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	//===================================================================


};
//#endregion



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/