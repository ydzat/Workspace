/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| Node.java:                                                                   |
|      PVL4_Group13                                                            |
|                                                                              |
| V1.0.0-en_GB // (20200521/20200521)                                                          |
| (C)  Dongze Yang (574145)                                                    |
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
| ? feature udea left for future version                                       |
| * information                                                                |
|   (editing periods in brackets behind version                                |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.0.0-en_GB // (20200521/20200521):                                                         |
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



/*SECTION**********************************************************************\
|                                                                              |
| Package                                                                      |
|                                                                              |
\******************************************************************************/
package PVL4_Group13;
// .



/*SECTION**********************************************************************\
|                                                                              |
| Resources                                                                    |
|                                                                              |
\******************************************************************************/

// .



/*SECTION**********************************************************************\
|                                                                              |
| Class definition (I)                                                         |
|                                                                              |
\******************************************************************************/

/**
 * PVL4_Group13
 *
 * @author	Dongze Yang
 * @version	V1.0.0-en_GB // (20200521/20200521)
 */
public class Node
{



/*SECTION**********************************************************************\
|                                                                              |
| Instance variables                                                           |
|                                                                              |
\******************************************************************************/

	
	public float prob;			//probability of a node
	public Node lChild;			//the left child of this node
	public Node rChild;			//the right child of this node
	public String code = "";	//Huffman code
	public String data = "";	//letter

/*SECTION**********************************************************************\
|                                                                              |
| Instance methods                                                             |
|                                                                              |
\******************************************************************************/

	
	/**
  	 * @description: Will be used when constructing the Huffman tree
  	 * @param prob, data, lChild, rChild 
  	 * @return: no return value
     */ 
 	/* public Node(float prob) { 
		this.prob = prob;
	} */
	
	public Node(String data, float prob) {
        this.data = data;
        this.prob = prob;
    }
	
	public Node(float prob, Node lChild, Node rChild) {
		this.prob = prob;
	    this.lChild = lChild;
	    this.rChild = rChild;
	 }

};



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/
