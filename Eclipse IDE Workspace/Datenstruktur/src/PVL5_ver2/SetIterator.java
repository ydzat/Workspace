/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| SetIterator.java:                                                            |
|      The iterator for a Set.												   |
|                                                                              |
| V1.0.0-en_GB // (20200528/20200528)                                          |
| (C) 2020 Felix Vogel (591520)                                                |
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
| V1.0.0-en_GB // (20200528/20200528):                                         |
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

package PVL5_ver2;



/*SECTION**********************************************************************\
|                                                                              |
| Resources                                                                    |
|                                                                              |
\******************************************************************************/

import java.util.HashSet;
import java.util.Iterator;



/*SECTION**********************************************************************\
|                                                                              |
| Class definition (I)                                                         |
|                                                                              |
\******************************************************************************/

/**
 * The iterator for a Set.
 *
 * @author	Felix Vogel
 * @version	V1.0.0-en_GB // (20200528/20200528)
 */
public class SetIterator implements Iterator<Set>
{



/*SECTION**********************************************************************\
|                                                                              |
| Instance variables                                                           |
|                                                                              |
\******************************************************************************/
	
	/** The current index of the iterator in the value-list. */
	private int position = 0;

	/** Contains all Integer values of the Set.*/
	private HashSet<Integer> values;



/*SECTION**********************************************************************\
|                                                                              |
| Constructors                                                                 |
|                                                                              |
\******************************************************************************/

	public SetIterator(HashSet<Integer> collection)
	{
		
		//Assigning variables.
		this.values = collection;
		
		
		
		//Quitting the constructor.
		return;
	
	
		
	};



/*SECTION**********************************************************************\
|                                                                              |
| Instance methods                                                             |
|                                                                              |
\******************************************************************************/

	/**
	 * Checks if there is a next element.
	 * @return	if there is a next element.
	 */
	@Override
	public boolean hasNext()
	{
		
		//Variables.
		boolean ret = false;
		
		
		
		//Check if position already reached the size of the list.
		if(position < values.size())
			{ret = true;};
		
		
		
		//returning the boolean value.
		return ret;
		
		
		
	};

	
	
	/**
	 * Iterates over the values of a Set.
	 * @return new Set with the next value of the original Set.
	 */
	@Override
	public Set next()
	{
		
		//Variables.
		int element = values.get(position++);
		PVL5_Group13 newSet = new PVL5_Group13(element);
		
		
		
		//returning the new Set.
		return newSet;
		
		
		
	};



};

/*
	//#region	Method iterator().
	/**
	 * Creates an Iterator which iterates over the values of the set.
	 * 
	 * @author 	Felix Vogel
	 * @return	instance of {@link SetIterator}
	 *
	@Override
	public Iterator<Set> iterator()	{return new SetIterator(this.values);};
	//#endregion
*/



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/
