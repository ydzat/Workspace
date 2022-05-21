/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| PVL7_Group13.java:                                                           |
|      PVL7                                                                    |
|                                                                              |
| V1.1.0-en_GB // (20200615/20200615)                                          |
| (C) 2020 Dongze Yang (574145), Felix Vogel (591520)						   |
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
| + Constructor, setEdge(), getEdges() have been finished                      |
| 	                                                                           |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.1.0-en_GB // (20200615/20200615):                                         |
| + getNGons() has been finished						                       |
| 	                                                                           |
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
package PVL10;
//#endregion

import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

//#region	Resources.

//#endregion

//#region	Class definition: PVL7_Group13.
/**
 * PVL7
 *
 * @author	Dongze Yang, Felix Vogel
 * @version	V1.1.0-en_GB // (20200615/20200615)
 */
public class PVL10_Group13 implements Graph_IV
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
	
	
	
	PVL10_Group13(int n){
		this.nVertex = n;
		this.graph = new Graph(n);
		
	};

	
	
	/*@description: Connect two nodes
	 * @return: "true" - if this edge has not been established
	 * 
	 * */
	public Boolean setEdge(int source, int destin, int weight) {
		return this.graph.addEdge(source, destin, weight);
	};
	
	
	
	/*@description: Geben Sie eine Liste von Listen zurück. 
	 * Diese i-te Liste soll dabei angeben, 
	 * welche Knoten zum i-ten Knoten adjazent (verbunden durch eine Kante) sind.
	 * */
	public List<List<Edge>> getEdges() {
		return this.graph.BFS();
	};



	@Override
	public Boolean setEdge(int source, int destin, int weight) {
		// TODO 自动生成的方法存根
		return null;
	}



	@Override
	public Boolean hasNegativeCycle() {
		// TODO 自动生成的方法存根
		return null;
	}



	@Override
	public List<Edge> shortestPath(int source, int destin) {
		// TODO 自动生成的方法存根
		return null;
	}



	@Override
	public Integer universalSink() {
		// TODO 自动生成的方法存根
		return null;
	}



	@Override
	public List<List<Edge>> maxEdgeDisjointPaths(int source, int destin) {
		// TODO 自动生成的方法存根
		return null;
	};
	//#endregion




};
//#endregion



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/