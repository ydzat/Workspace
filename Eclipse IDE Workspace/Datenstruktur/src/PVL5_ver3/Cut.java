/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| Cut.java:                                                                    |
|      A method that creates the difference set of A with B.                   |
|                                                                              |
| V1.0.1-en_GB // (20200605/20200604)                                          |
| (C) 2020 Julian Nico Pielmaier (591773)                                      |
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
| V1.0.1-en_GB // (20200605/20200604):                                         |
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

package PVL5_ver3;

import java.util.HashSet;
import java.util.Iterator;



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
 * A method that creates the difference set of A with B.
 *
 * @author	Julian Nico Pielmaier
 * @version	V1.0.0-en_GB // (20200604/20200604)
 */
public class Cut
{



/*SECTION**********************************************************************\
|                                                                              |
| Instance variables                                                           |
|                                                                              |
\******************************************************************************/

	private HashSet<Integer> values;



/*SECTION**********************************************************************\
|                                                                              |
| Class variables                                                              |
|                                                                              |
\******************************************************************************/

	/** Some more code here */



/*SECTION**********************************************************************\
|                                                                              |
| Constructors                                                                 |
|                                                                              |
\******************************************************************************/

	/** Some more code here */



/*SECTION**********************************************************************\
|                                                                              |
| Getters and setters                                                          |
|                                                                              |
\******************************************************************************/

	/** Some more code here */



/*SECTION**********************************************************************\
|                                                                              |
| Instance methods                                                             |
|                                                                              |
\******************************************************************************/

	/**
	 * A method that creates the difference set of A with B.
	 *
	 * @param   set B
	 * @return  difference set A
	 * @author	Julian Nico Pielmaier
	 * @version	V1.0.1-en_GB // (20200605/20200604)
	 */
	public Set cut(Set toCutWith)
	{
		
		
		
		for(int k: this.values)
		{
			boolean found = false;
			Iterator<Set> iter = toCutWith.iterator();
			int pos = 0;
			
			
			
			while(iter.hasNext() && !found)
			{
				
				
				
				if(toCutWith.asIntList().get(pos) == k) 
				{
					this.values.remove(k);
					found = true;
					iter = toCutWith.iterator();					
					
					
					
				};
				
				
				
				pos++;
				
				
				
			};
			
			
			
		};
		
		
		
		return (Set) this;
		
		
		
	};



/*SECTION**********************************************************************\
|                                                                              |
| Class methods                                                                |
|                                                                              |
\******************************************************************************/

	/** Some more code here */



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