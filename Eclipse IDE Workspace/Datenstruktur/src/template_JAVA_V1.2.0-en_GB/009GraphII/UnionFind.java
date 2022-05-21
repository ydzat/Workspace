/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| UnionFind.java:                                                              |
|      UnionFindSet                                                            |
|                                                                              |
| V1.0.0-en_GB // (20200621/20200621)                                          |
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
| V1.0.0-en_GB // (20200621/20200621):                                         |
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
//#endregion

//#region	Resources.
import java.util.List;
//#endregion

//#region	Class definition: UnionFind.
/**
 * UnionFindSet
 *
 * @author	Dongze Yang
 * @version	V1.0.0-en_GB // (20200621/20200621)
 */
public class UnionFind
{
	//#region	Instance variables.
	/**
  	* @description: Array id[] als Speicherstruktur des Baums, Der Index gibt den Wert des Knotens an, und der Wert von id [x] gibt den übergeordneten Knoten des Knotens an
  	* @param id[]
  	*/
	private int []id;
	//#endregion

	//#region	Class variables.
	/** Some more code here… */
	//#endregion

	//#region	Constructors.
	public UnionFind(int n) {
		id = new int[n];
		for(int i = 0; i < n; i++) {
			id[i] = i;
		};
	};
	//#endregion


	//#region	Instance methods.
	private int root(int i) {
		while(i != id[i]) {
			i = id[i];
		};
		return i;
	};
	
	
	public boolean hasWay(int source, int destin) {
		return root(source) == root(destin);
	};
	
	//Verbind zwei Knoten
	public void union(int source, int destin) {
		int sourceRoot = root(source);
		int destinRoot = root(destin);
		id[sourceRoot] = destinRoot;
	};
	
	
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