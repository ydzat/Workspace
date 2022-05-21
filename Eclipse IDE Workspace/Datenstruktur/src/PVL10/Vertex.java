/*
 * @Author: Dongze Yang
 * @LastEditors: Dongze Yang
 */ 
/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| Vertex.java:                                                                 |
|      Node class                                                              |
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
package PVL10;
//#endregion

//#region	Resources.

//#endregion

//#region	Class definition: Vertex.
/**
 * Node class
 *
 * @author	Dongze Yang
 * @version	V1.0.0-en_GB // (20200611/20200611)
 */
public class Vertex
{
	//#region	Instance variables.
	public int label;					//the value of the node
	public boolean wasVisited;			//If you want to traverse, record the traversal status
	//#endregion

	//#region	Constructors.
	/**
  	* @description: The default is "not visited"
  	* @param {type} 
  	* @return: 
  	*/
	public Vertex(int label) {
		this.label = label;
		this.wasVisited = false;
	}
	//#endregion


};
//#endregion



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/