/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| FelixVogel.java:                                                             |
|      Top-Level Class.														   |
|                                                                              |
| V1.2.0-en_GB // (20200603/20200603)                                          |
| (C) 2020 Felix Vogel (591520), Dongze Yang (574145), Kevin Matthes (590411)  |
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
| + union() and relativeComplementWith()                                       |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.2.0-en_GB // (20200603/20200603):                                         |
| ! code simplification                                                        |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.3.0-en_GB // (20200604/20200604):                                         |
| ! rewrite the function "union" and "relativeComplementWith"                                                        |
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
package PVL5_ver2;
//#endregion

//#region	Resources.
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.List;
//#endregion

//#region	Class definition: PVL5_Group13.
/**
 * Top-Level Class.
 *
 * @author	Felix Vogel
 * @version	V1.0.0-en_GB // (20200528/20200528)
 */
public class PVL5_Group13 implements Set
{
	//#region	Instance variables.
	/** The list which contains the Integer values of the set. */
	private final HashSet<Integer> values = new HashSet<>(0);
	//#endregion

	//#region	Constructors.
	//#region	The default constructor.
	/**
	 * The default constructor.
	 * 
	 * @author	Kevin Matthes
	 * @version	V1.0.0-en_GB // (20200603/20200603)
	 */
	public PVL5_Group13()	{return;};
	//#endregion

	//#region	Creating a new set from a specific item.
	/**
	 * Creates a new set.
	 * 
	 * @param element	the first element of the set.
	 * 
	 * @author	Felix Vogel
	 * @author	Kevin Matthes
	 * @version	V1.1.0-en_GB // (20200603/20200603)
	 */
	public PVL5_Group13(int element)
	{
		//#region	Invoking the default constructor.
		this();
		//#endregion



		//#region	Adding the element to the list.
		this.values.add((Integer) element);
		//#endregion
	
		
		
		//#region	Quitting the constructor properly.
		return;
		//#endregion
		
		
		
	};
	//#endregion
	//#endregion

	//#region	Getters and setters.
	//#region	Field values.
	/**
	 * The default getter method for {@code this.values}.
	 * 
	 * @return	{@code this.values}
	 */
	public HashSet<Integer> getValues()	{return this.values;};
	//#endregion
	//#endregion

	//#region	Instance methods.
	//#region	Method asIntList().
	@Override
	public List<Integer> asIntList()
	{
		// TODO Auto-generated method stub
		
		return null;
	};
	//#endregion
	
	//#region	Method cut().
	@Override
	public Set cut(Set toCutWith)
	{
		// TODO Auto-generated method stub
		return null;
	};
	//#endregion

	//#region	Method isSubsetOf().
	@Override
	public boolean isSubsetOf(Set sampleSet)
	{
		// TODO Auto-generated method stub
		return false;
	};
	//#endregion

	//#region	Method equals().
	@Override
	public boolean equals(Set sampleSet)
	{
		// TODO Auto-generated method stub
		return false;
	};
	//#endregion

	//#region	Method iterator().
	/**
	 * Creating an iterator for the held set.
	 * 
	 * @author 	Kevin Matthes
	 * @return	instance of {@link SetIterator}
	 */
	@Override
	public Iterator<Set> iterator()	{return new SetIterator(this.values);};
	//#endregion

	//#region	Method relativeComplementWith().
	/**
	 * relative Complement with
	 * 
	 * @author 	Dongze Yang
	 * @return	this
	 * @version 20200604
	 */
	@Override
	public Set relativeComplementWith(Set sampleSet)
	{
		
		Set temp1 = new PVL5_Group13();
		ArrayList<Integer> temp2 = new ArrayList<Integer>();

		temp1.union(this);
		
		this.values.clear();
		
		temp1.union(sampleSet);
		
		while(sampleSet.iterator().hasNext()) {
			temp2.add(Integer.parseInt(sampleSet.iterator().next().toString()));
		};
		
		while(temp1.iterator().hasNext()) {
			Integer temp3 = Integer.parseInt(temp1.iterator().next().toString());
			if( ! temp2.contains(temp3)) {
				this.values.add(temp3);
			};
		};
		
		
		return this;
	};
	//#endregion

	//#region	Method union().
	/**
	 * Union
	 * 
	 * @author 	Dongze Yang
	 * @return	this
	 * @version 20200604
	 */
	@Override
	public Set union(Set toInsert)
	{
		while( toInsert.iterator().hasNext()  ) {
			
			Integer temp =   Integer.parseInt(toInsert.iterator().next().toString());
			
			this.values.add(temp);
		};
		
		
		return this;
	};
	//#endregion
	//#endregion



};
//#endregion



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/
