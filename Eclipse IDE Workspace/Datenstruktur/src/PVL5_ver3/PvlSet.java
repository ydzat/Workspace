/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| PvlSet.java:                                                                 |
|      The iterator for a Set.												   |
|                                                                              |
| V1.0.0-en_GB // (20200603/20200603)                                          |
| (C) 2020 Kevin Matthes (590411)                                              |
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
| V1.0.0-en_GB // (20200603/20200603):                                         |
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



//#region	Package
package PVL5_ver3;
//#endregion

//#region	Resources.
import java.util.HashSet;
import java.util.Iterator;
//#endregion

//#region	Class definition: PvlSet.
/**
 * The iterator for a Set.
 *
 * @author	Kevin Matthes
 * @version	V1.0.0-en_GB // (20200603/20200603)
 */
public class PvlSet implements Iterator<Set>
{
	//#region	Instance variables.
	/** The result array. */
	private Integer[]			array	= null;

	/** A marker in order to store the information which array element is currently used. */
	private int					index	= 0;

	/** The values held by this unit. */
	private HashSet<Integer>	values	= null;
	//#endregion

	//#region	Constructors.
	//#region	The default constructor.
	/** The default constructor. */
	public PvlSet()	{return;};
	//#endregion

	//#region	Creating a new unit from consisting set.
	/**
	 * Creating a new unit from a given HashSet<Integer>.
	 * 
	 * @param	data	The set which shall be held.
	 */
	public PvlSet(final HashSet<Integer> data)
	{
		//#region	Invoking the default constructor.
		this();
		//#endregion



		//#region	Assigning variables.
		this.setValues(data);
		//#endregion
		
		
		
		//#region	Quitting the constructor properly.
		return;
		//#endregion
	
	
		
	};
	//#endregion
	//#endregion

	//#region	Getters and setters.
	//#region	Field array.
	//#region	Method getArray().
	/**
	 * The default getter method for {@code this.array}.
	 * 
	 * @return	{@code this.array}
	 */
	public Integer[] getArray()	{return	this.array;};
	//#endregion

	//#region	Method prepareArray().
	/** Creating an array from the held set. */
	public void prepareArray()
	{
		//#region	Processing the preparation.
		this.array = this.values.toArray(new Integer[0]);
		//#endregion



		//#region	Quitting the method properly.
		return;
		//#endregion



	};
	//#endregion
	//#endregion

	//#region	Field values.
	//#region	Method setValues().
	/** 
	 * The default setter method for {@code this.values}.
	 * 
	 * @param	data	The set which shall be held by this unit.
	 */
	public void setValues(final HashSet<Integer> data)
	{
		//#region	Processing the assignment.
		this.values = data;
		this.prepareArray();
		//#endregion



		//#region	Quitting the method properly.
		return;
		//#endregion



	};
	//#endregion
	//#endregion
	//#endregion

	//#region	Instance methods.
	//#region	Method hasNext().
	/** 
	 * The required method {@code hasNext()}.
	 * 
	 * @return	Either {@code true}, if there is still a following element, or {@code false}, else.
	 */
	public boolean hasNext()	{return this.index < this.array.length;};
	//#endregion

	//#region	Method next().
	/**
	 * The required method {@code next()}.
	 * 
	 * @return	The next element within the set as a set of only this element.
	 */
	public Set next()	{return new PVL5_Group13(this.array[this.index++]);};
	//#endregion
	//#endregion



};
//#endregion


/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/
