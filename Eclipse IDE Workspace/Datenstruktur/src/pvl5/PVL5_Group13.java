/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| FelixVogel.java:                                                             |
|      Top-Level Class.														   |
|                                                                              |
| V1.1.0-en_GB // (20200528/20200528)                                          |
| (C) 2020 Felix Vogel (591520), Dongze Yang (574145)                                                |
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
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.1.0-en_GB // (20200528/20200528):                                         |
| + union() and relativeComplementWith()                     |
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

package PVL5_Group13;



/*SECTION**********************************************************************\
|                                                                              |
| Resources                                                                    |
|                                                                              |
\******************************************************************************/

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;



/*SECTION**********************************************************************\
|                                                                              |
| Class definition (I)                                                         |
|                                                                              |
\******************************************************************************/

/**
 * Top-Level Class.
 *
 * @author	Felix Vogel
 * @version	V1.0.0-en_GB // (20200528/20200528)
 */
public class PVL5_Group13 implements Set
{



/*SECTION**********************************************************************\
|                                                                              |
| Instance variables                                                           |
|                                                                              |
\******************************************************************************/

	/** The list which contains the Integer values of the set. */
	private ArrayList<Integer> values;



/*SECTION**********************************************************************\
|                                                                              |
| Class variables                                                              |
|                                                                              |
\******************************************************************************/

	/** Some more code here… */



/*SECTION**********************************************************************\
|                                                                              |
| Constructors                                                                 |
|                                                                              |
\******************************************************************************/

	/**
	 * Creates a new set.
	 * @param element	the first element of the set.
	 */
	public PVL5_Group13(int element)
	{
		
		//Creating an empty list.
		values = new ArrayList<Integer>();
		//Adding the element to the list.
		values.add((Integer) element);
	
		
		
		//Quitting the constructor.
		return;
		
		
		
	};

	

/*SECTION**********************************************************************\
|                                                                              |
| Getters and setters                                                          |
|                                                                              |
\******************************************************************************/

	/** Some more code here… */



/*SECTION**********************************************************************\
|                                                                              |
| Instance methods                                                             |
|                                                                              |
\******************************************************************************/

	/**
	 * Creates an Iterator which iterates over the values of the set.
	 * 
	 * @author 	Felix Vogel
	 * @return	instance of {@link SetIterator}
	 */
	@Override
	public Iterator<Set> iterator()	{return new SetIterator(this.values);};


	/**
	 * Union
	 * 
	 * @author 	Dongze Yang
	 * @return	this
	 */
	@Override
	public Set union(Set toInsert)
	{
		for(int i = 0; i < toInsert.asIntList().size() ; i++) {
			if( ! this.asIntList().contains((toInsert.asIntList().get(i)))) {
				this.values.add((Integer) toInsert.asIntList().get(i));
			};
		};
		return this;
	};


	@Override
	public Set cut(Set toCutWith)
	{
		// TODO Auto-generated method stub
		return null;
	};


	/**
	 * relative Complement with
	 * 
	 * @author 	Dongze Yang
	 * @return	this
	 */
	@Override
	public Set relativeComplementWith(Set sampleSet)
	{
		Set temp = new Set(); //leer Menge
		
		for(int i = 0 ; i < this.asIntList().size(); i++) {
			temp.union(this);  
		};
		
		this.asIntList().clear();
		
		temp.union(sampleSet);
		
		for(int i = 0; i < temp.asIntList().size(); i++) {
			if(! sampleSet.asIntList().contains(temp.asIntList().get(i))) {
				this.values.add((Integer) sampleSet.asIntList().get(i));
			};
		};
		
		return this;
	};



	@Override
	public boolean isSubsetOf(Set sampleSet)
	{
		// TODO Auto-generated method stub
		return false;
	};



	@Override
	public boolean equals(Set sampleSet)
	{
		// TODO Auto-generated method stub
		return false;
	};



	@Override
	public List<Integer> asIntList()
	{
		// TODO Auto-generated method stub
		return null;
	};



/*SECTION**********************************************************************\
|                                                                              |
| Class methods                                                                |
|                                                                              |
\******************************************************************************/

	/** Some more code here… */



/*SECTION**********************************************************************\
|                                                                              |
| Class definition (II)                                                        |
|                                                                              |
\******************************************************************************/

};



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/
