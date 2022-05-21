/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| dfsStack.java:                                                               |
|      Stack structor                                                          |
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
//#endregion
package PVL8;

//#region	Resources.

//#endregion

//#region	Class definition: dfsStack.
/**
 * Stack structor
 *
 * @author	Dongze Yang
 * @version	V1.0.0-en_GB // (20200611/20200611)
 */
public class dfsStack
{
	//#region	Instance variables.
	private int size;				//The size of the stack, ie the number of nodes
	private int[] st;				//Stack
	private int top;				//Subscript of the top element of the stack
	//#endregion

	//#region	Class variables.
	/** Some more code here… */
	//#endregion

	//#region	Constructors.
	public dfsStack(int size) {
		this.size = size;
		st = new int[size];
		top = -1;
	};
	//#endregion


	//#region	Instance methods.
	public void push(int i) {
		st[++top] = i;
	};
	
	public int pop() {
		return st[top--];
	};
	
	public int getThis() {
		return st[top];
	};
	
	public boolean isEmpty() {
		return (top == -1);
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