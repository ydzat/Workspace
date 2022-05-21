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
package PVL9;
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
public class PVL9_Group13 implements Graph_III
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
	
	
	
	PVL9_Group13(int n){
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
	public Boolean hasCircle() {
		// TODO 
		return null;
	}



	@Override
	public List<Integer> topSort() {
		// TODO 
		return null;
	}



	@Override
	public List<List<Integer>> getStronglyConnectedComponents() {
		// TODO 
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