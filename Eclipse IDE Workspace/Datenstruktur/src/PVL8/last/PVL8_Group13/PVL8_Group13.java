/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| PVL8_Group13.java:                                                           |
|      PVL8                                                                    |
|                                                                              |
| V1.1.0-en_GB // (20200627/20200627)                                          |
| (C) 2020 Dongze Yang (574145), Felix Vogel (591520), Kevin Matthes (590411), |
|          Julian Nico Pielmaier (591773)                                      |
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
| V1.0.0-en_GB // (20200621/20200621):                                         |
| + made it work as it should and not only as it was coded                     |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.1.0-en_GB // (20200627/20200627):                                         |
| + getNGons() has been finished                                               |
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
| Testing by Kevin Matthes.                                                    |
|                                                                              |
\******************************************************************************/



//#region	Package.
package pvl8_group13;
//#endregion

import java.util.Collections;
//#region	Resources.
import java.util.LinkedList;
import java.util.List;
//#endregion

//#region	Class definition: PVL8_Group13.
/**
 * PVL8
 *
 * @author	Dongze Yang
 * @author	Felix Vogel
 * @author	Kevin Matthes
 * @author	Julian Nico Pielmaier
 * @version	V1.1.0-en_GB // (20200627/20200627)
 */
public class PVL8_Group13 implements Graph_II
{
	//#region	Instance variables.
	/** The held graph. */
	Graph	graph;

	/** The number of nodes. */
	int		nVertex;
	//#endregion

	//#region	Constructors.
	//#region	The default constructor.
	/** Some more code here… */
	public PVL8_Group13()	{return;};
	//#endregion

	//#region	Creating a new graph unit from the amount of vertices to hold.
	/**
	 * Creating a new graph unit from the amount of vertices to hold.
	 *
	 * @param	n	The amount of vertices to hold.
	 */
	public PVL8_Group13(int n)
	{
		//#region	Invoking the default constructor.
		this();
		//#endregion

		//#region	Processing the assignments.
		this.nVertex = n;
		this.graph = new Graph(n);
		//#endregion

		//#region	Quitting the constructor properly.
		return;
		//#endregion



	};
	//#endregion
	//#endregion

	//#region	Instance methods.
	//#region	getArticulations().
	/**
	 * Determing all articulations of this graph.
	 *
	 * @return	A list of all articulations.
	 */
	@Override
	public List<Integer> getArticulations()
	{
		//Variables.
		//#region	Variables.
		List<Integer>		ret		= new LinkedList<Integer>();
		List<List<Integer>>	edges	= getEdges();
		int					size	= edges.size();
		//#endregion


		//#region	Going through each vertex.
		for (int i = 0; i < nVertex; i++)
		{
			edges = getEdges();
			edges.get(i).clear();



			//#region	Going through each edge and delete the vertex there.
			for(int j = 0; j < size; j++)
			{
				List<Integer> edge = edges.get(j);

				for (int k = 0; k < edge.size(); k++)
				{
					//Removing the vertex.
					if(edge.get(k) == i)
						edge.remove(k);
				};

			};
			//#endregion



			if(!connectedExceptOfArticulationPoint(edges, i))
				{ret.add(i);};

		};
		//#endregion

		//#region	Returning results.
		return ret;
		//#endregion



	};
	//#endregion

	//#region	getBridges().
	/**
	 * Determing all bridges of this graph.
	 *
	 * @return	A list of all bridges.
	 */
	@Override
	public List<List<Integer>> getBridges()
	{
		//#region	Variables.
		List<List<Integer>> ret = new LinkedList<List<Integer>>();
		//#endregion

		//#region	Processing the determination.
		for(int i = 0; i < nVertex; i++)
		{
			for (int j = 0; j < nVertex; j++)
			{
				//#region	Variables.
				boolean vertexesAreConnected = false;
				//#endregion

				//#region	Checking for vertex connection.
				if(i != j && graph.getAdjMat()[i][j] == 1)
				{
					graph.getAdjMat()[i][j] = 0;
					graph.getAdjMat()[j][i] = 0;
					vertexesAreConnected = true;



				};
				//#endregion

				//#region	Checking for a connected graph.
				if(!connected(getEdges()))
				{
					List<Integer> edge = new LinkedList<Integer>();
					edge.add(i);
					edge.add(j);
					ret.add(edge);



				};
				//#endregion

				//#region	Adding connection back again.
				if(vertexesAreConnected)
					graph.getAdjMat()[i][j] = graph.getAdjMat()[j][i] = 1;
				//#endregion



			};



		};
		//#endregion



		List<List<Integer>> ret_sorted = new LinkedList<List<Integer>>();
		for (List<Integer> list : ret)
		{
			// Sorting the list.
			Collections.sort(list);



			// Adding all except dublicates.
			if(!ret_sorted.contains(list))
				ret_sorted.add(list);



		};



		//#region	Returning results.
		return ret_sorted;
		//#endregion



	};
	//#endregion

	//#region	getEdges().
	/**
	 * Determining all adjacent vertices.
	 *
	 * @return	The adjacence matrix of this graph.
	 */
	@Override
	public List<List<Integer>> getEdges()	{return this.graph.BFS();};
	//#endregion

	//#region	hasWay().
	@Override
	/**
	 * Determining if there is a path from {@code source} to {@code destin}.
	 *
	 * @param	source	The vertex where to begin.
	 * @param	destin	The vertex where to end.
	 * @return	Either {@code true}, if so, or {@code false}, else.
	 */
	public Boolean hasWay(int source, int destin)	{return source < this.nVertex && destin < this.nVertex ? this.graph.hasWay(source, destin) : false;};
	//#endregion

	//#region	isConnected().
	/**
	 * Determining if this graph as a whole is connected.
	 *
	 * @return	Either {@code true}, if so, or {@code false}, else.
	 */
	@Override
	public Boolean isConnected()
	{
		//#region	Variables.
		Boolean connected = true;
		//#endregion

		//#region	Checks every connection node by node.
		for(int i = 0; connected && i < nVertex; i++)
			if(!hasWay(0, i))
				connected = false;
		//#endregion

		//#region	Returning results.
		return connected;
		//#endregion



	};
	//#endregion

	//#region	isConnected(List<Integer>).
	/**
	 * Determing if the given list of vertices is connected.
	 *
	 * @param	nodes	The list of vertices to check.
	 * @return	Either {@code true}, if so, or {@code false}, else.
	 */
	@Override
	public Boolean isConnected(List<Integer> nodes)	{return graph.isConnected(nodes);};
	//#endregion

	//#region	setEdge(int, int).
	/**
	 * Connecting two vertices.
	 *
	 * @param	from	The vertex where to start.
	 * @param	to		The vertex to connect the first one with.
	 * @return	Either {@code true}, if succeeded, or {@code false}, else.
	 */
	@Override
	public Boolean setEdge(int from, int to)	{return this.graph.addEdge(from, to);};
	//#endregion

	/**
	 * Finds all ways from one point to another point.
	 * @param startPoint	The starting vertex.
	 * @param dest			The destination vertex.
	 * @param edges			The edges list of the graph.
	 * @return				A list with all ways.
	 */
	private List<List<Integer>> findWays(int startPoint, int dest, List<List<Integer>> edges)
	{
		List<List<Integer>> ret = new LinkedList<List<Integer>>();
		findWaysHelper(startPoint, dest, startPoint, edges, new LinkedList<Integer>(), ret);
		return ret;
	};



	/**
	 * Helps to find all ways from one point to another recursively. Manipulates the ret-list of findWays().
	 * @param currentPoint	The vertex of the current recursion level.
	 * @param dest			The destination vertex.
	 * @param startPoint	The starting vertex.
	 * @param edges			The edges list of the graph.
	 * @param currentPath	The current path.
	 * @param result		The ret-list of findWays().
	 */
	private void findWaysHelper(int currentPoint, int dest, int startPoint, List<List<Integer>> edges, List<Integer> currentPath, List<List<Integer>> result)
	{

		currentPath.add(currentPoint);


		if(currentPoint == dest)
		{
			result.add(currentPath);
		}
		else
		{

			List<Integer> edgesOfCurrentPoint = edges.get(currentPoint);

			for (int i = 0; i < edgesOfCurrentPoint.size(); i++)
			{

				Integer nextPoint = edgesOfCurrentPoint.get(i);

				if(!currentPath.contains(nextPoint))
				{
					List<Integer> currentPathCopy = new LinkedList<Integer>();
					currentPathCopy.addAll(currentPath);
					findWaysHelper(nextPoint, dest, startPoint, edges, currentPathCopy, result);
				};
			};


		};



		//Quitting the method.
		return;
	};



	/**
	 * My own isConnected() function using getEdges().
	 * @param 	edges	The edges list.
	 * @return			if the graph is connected.
	 */
	public boolean connected(List<List<Integer>> edges)
	{

		//Variables.
		Boolean connected = true;

		for(int i = 1; i < nVertex; i++)
		{
			if(findWays(0, i, edges).isEmpty())
			connected = false;
		}

		return connected;

	}



	/**
	 * My own isConnected() function using getEdges(). It ignores the artPoint in the graph.
	 * @param 	edges		The edges list
	 * @param 	artPoint	The supposed articulation point.
	 * @return 				if the graph is connected.
	 */
	public boolean connectedExceptOfArticulationPoint(List<List<Integer>> edges, int artPoint)
	{

		//Variables.
		Boolean connected = true;
		int startVertex = 0;



		if(artPoint == 0)
			{startVertex = 1;}



		for(int i = 1; i < nVertex; i++)
		{
			if((i != artPoint) && (findWays(startVertex, i, edges).isEmpty()))
				{connected = false;};
		}

		return connected;

	};
	//#endregion



};
//#endregion



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/
