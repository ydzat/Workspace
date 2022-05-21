/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| PVL5_Group13.java:                                                           |
|      Top-Level Class.														   |
|                                                                              |
| V1.3.0-en_GB // (20200604/20200604)                                          |
| (C) 2020 Felix Vogel (591520), Dongze Yang (574145), Kevin Matthes (590411), |
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
| ! rewrite the function "union" and "relativeComplementWith"                  |
| + cut() and asIntList()                                                      |
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
| Testing by Dongze Yang.                                                      |
|                                                                              |
\******************************************************************************/



//#region	Package.
package proj;
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
	public PVL5_Group13(final int element)
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
	//#region	Method getValues().
	/**
	 * The default getter method for {@code this.values}.
	 * 
	 * @return	{@code this.values}
	 * 
	 * @author	Kevin Matthes
	 * @version	V1.0.0-en_GB // (20200603/20200603)
	 */
	public HashSet<Integer> getValues()	{return this.values;};
	//#endregion
	//#endregion
	//#endregion

	//#region	Instance methods.
	//#region	Method asIntList().
	/**
	 * A method that shows all elements of a set in a list.
	 *
	 * @return  set in the form of a list
	 * @author	Julian Nico Pielmaier
	 * @version	V1.0.0-en_GB // (20200603/20200603)
	 */
	@Override
	public List<Integer> asIntList() 
	{
		//#region	Variables.
		final List<Integer> temp = new ArrayList<Integer>();
		//#endregion
		
		
		
		//#region	Processing the assignment.
		for(final int k : this.values)
			temp.add(k);
		//#endregion
		
		
		
		//#region	Returning results.
		return temp;
		//#endregion
		
		
		
	};
	//#endregion
	
	//#region	Method cut().
	/**
	 * A method that creates the difference set of A with B.
	 *
	 * @param   toCutWith	set B
	 * @return  difference set A
	 * 
	 * @author	Julian Nico Pielmaier
	 * @version	V1.0.0-en_GB // (20200604/20200604)
	 */
	@Override
	public Set cut(final Set toCutWith)
	{
		//#region	Processing the cut operation.
		for(final int k : this.asIntList())
		{
			boolean			found	= false;
			Iterator<Set>	iter	= toCutWith.iterator();
			
			while(iter.hasNext() && !found)
			{
				if(iter.next().asIntList().get(0) == k) 
				{
					this.values.remove(k);
					found = true;
					iter = toCutWith.iterator();					
								
					
				};
				
				
			};

			
		};
		//#endregion
		
		
		
		//#region	Returning results.
		return this;
		//#endregion
		
		
		
	};
	//#endregion

	//#region	Method isSubsetOf().
	/**
	 * Testing if a given set may be the superset of this one.
	 * 
	 * @return	Either {@code true}, if so, or {@code false}, else.
	 * 
	 * @author	Kevin Matthes
	 * @version	V1.0.0-en_GB // (20200604/20200604)
	 */
	@Override
	public boolean isSubsetOf(final Set sampleSet)
	{
		//#region	Variables.
		boolean	abort	= false;
		boolean	ret		= false;
		//#endregion



		//#region	Abbreviating the test: If both sets are equal, they are subset of each other.
		if(this.equals(sampleSet))
			ret = true;
		//#endregion



		//#region	If both sets are not equal, this further test must be passed.
		if(!ret)
		{
			final PvlSet	setUnit	= new PvlSet(this.values);
			final Integer[]	array	= setUnit.getArray();

			for(int i = 0; !abort && i < array.length; i++)
				if(!((PVL5_Group13) sampleSet).getValues().contains(array[i]))
					abort = true;

			if(!abort)
				ret = true;



		};
		//#endregion



		//#region	Returning results.
		return ret;
		//#endregion



	};
	//#endregion

	//#region	Method equals().
	/**
	 * Checking if the given set equals this one.
	 * 
	 * @param	sampleSet	The set to test against this one.
	 * @return	Either {@code true}, if they are equal, or {@code false}, else.
	 * 
	 * @author	Kevin Matthes
	 * @version	V1.0.0-en_GB // (20200604/20200604)
	 */
	@Override
	public boolean equals(final Set sampleSet)	{return this.values.equals(((PVL5_Group13) sampleSet).getValues());};
	//#endregion

	//#region	Method iterator().
	/**
	 * Creating an iterator for the held set.
	 * 
	 * @author 	Kevin Matthes
	 * @return	instance of {@link SetIterator}
	 */
	@Override
	public Iterator<Set> iterator()	{return new PvlSet(this.values);};
	//#endregion

	//#region	Method relativeComplementWith().
	/**
	 * relative Complement with
	 * 
	 * @return	this
	 * 
	 * @author 	Dongze Yang
	 * @version	V1.1.0-en_GB // (20200604/20200604)
	 */
	@Override
	public Set relativeComplementWith(final Set sampleSet)
	{
		//#region	Variables.
		final Set					temp1 = new PVL5_Group13();
		final ArrayList<Integer>	temp2 = new ArrayList<Integer>();
		//#endregion

		//#region	Processing the complement.
		temp1.union(this);
		
		this.values.clear();
		
		temp1.union(sampleSet);
		
		Iterator<Set> it1 = sampleSet.iterator();
		
		while(it1.hasNext()) {
			temp2.add(it1.next().asIntList().get(0));
		};
		
		Iterator<Set> it2 = temp1.iterator();
		
		while(it2.hasNext())
		{
			final Integer temp3 = it2.next().asIntList().get(0);

			if(!temp2.contains(temp3))
				this.values.add(temp3);

		};
		//#endregion
		
		

		//#region	Returning results.
		return this;
		//#endregion



	};
	//#endregion

	//#region	Method union().
	/**
	 * Union
	 * 
	 * @return	this
	 * 
	 * @author 	Dongze Yang
	 * @author	Kevin Matthes
	 * @version	V1.2.0-en_GB // (20200604/20200604)
	 */
	@Override
	public Set union(final Set toInsert)
	{
		//#region	Variables.
		final Integer[] array = ((PVL5_Group13) toInsert).getValues().toArray(new Integer[0]);
		//#endregion



		//#region	Preparations.
		//#endregion



		//#region	Processing the unification.
		for(int i = 0; i < array.length; i++)
			this.values.add(array[i]);
		//#endregion
		
		

		//#region	Returning results.
		return this;
		//#endregion



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
