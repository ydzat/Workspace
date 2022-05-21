/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| PVL7_Group13.java:                                                           |
|      PVL7                                                                    |
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
package PVL7;
//#endregion

import java.util.List;

//#region	Resources.

//#endregion

//#region	Class definition: PVL7_Group13.
/**
 * PVL7
 *
 * @author	Dongze Yang
 * @version	V1.0.0-en_GB // (20200611/20200611)
 */
public class PVL7_Group13 implements Graph_I
{
	//#region	Instance variables.
	/** Some more code here… */
	
	Graph graph;			
	int nVertex;				//Number of nodes
	
	
	//#endregion
	//#region	Class variables.
	/** Some more code here… */
	//#endregion
	
	//#region	Constructors.
	/** Some more code here… */
	
	/*
	 * initialization
	 * */
	PVL7_Group13(int n){
		this.nVertex = n;
		this.graph = new Graph(n);
		
	};

	/*@description: Connect two nodes
	 * @return: "true" - if this edge has not been established
	 * 
	 * */
	public Boolean setEdge(int from, int to) {
		return this.graph.addEdge(from, to);
	};
	
	/*@description: Geben Sie eine Liste von Listen zurück. 
	 * Diese i-te Liste soll dabei angeben, 
	 * welche Knoten zum i-ten Knoten adjazent (verbunden durch eine Kante) sind.
	 * */
	public List<List<Integer>> getEdges() {
		return this.graph.BFS();
	};

	@Override
	public List<List<Integer>> getNGons(int n) {
		// TODO 
		return null;
	};

	@Override
	public List<Integer> getLongestPath(int from, int to) {
		// TODO
		return null;
	};

	
	/*TODO: Did not implement this function, just provide an idea
	 * 
	 * */
	public Boolean hasFullCircle() {
		
		return this.graph.DFS_1();
	};
	//#endregion

	//#region	Getters and setters.
	/** Some more code here… */
	//#endregion

	//#region	Instance methods.
	/** Some more code here… */
	//#endregion

	//#region	Class methods.
	/** Some more code here… */
	//#endregion



};
//#endregion



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/