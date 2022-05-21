/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| Alphabet.java:                                                               |
|      A class in order to define some methods for lexical tests.              |
|                                                                              |
| V1.1.1-en_GB // (20200520/20200520)                                          |
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
| V1.0.0-en_GB // (20200513/20200515):                                         |
| + made it work as it should and not only as it was coded                     |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.1.0-en_GB // (20200516/20200516):                                         |
| + Now nullptrs could be assigned in a better way to the concerning fields.   |
| ! minor bugfixes                                                             |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.1.1-en_GB // (20200520/20200520):                                         |
| + new method in order to check just a single character                       |
| ! stylistic adjustments                                                      |
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
//package calculator_group_13;
package pvl3test;

//#endregion



//#region	Class definition: Alphabet.
/**
 * A class in order to define some methods for lexical tests.
 *
 * @author	Kevin Matthes
 * @version	V1.1.0-en_GB // (20200516/20200516)
 */
public class Alphabet
{
	//#region	Instance variables.
	/** All known letters by this alphabet unit. */
	private String letters	= null;

	/** The held string of this alphabet unit. */
	private String str		= null;
	//#endregion



	//#region	Constructors.
	//#region	Default constructor.
	/** The default constructor. */
	public Alphabet()	{return;};
	//#endregion

	//#region	Constructor from known letters.
	/** 
	 * Creating a new alphabet unit which knows a certain alphabet.
	 * 
	 * @param	letters	The letters which shall be known by this new alphabet unit.
	 * 
	 * @throws	NullPointerException	See also {@link #setLetters(String)}.
	 */
	public Alphabet(final String letters)
	{
		//#region	Invoking the default constructor.
		this();
		//#endregion



		//#region	Processing the assingment.
		this.setLetters(letters);
		//#endregion



		//#region	Quitting the constructor properly.
		return;
		//#endregion



	};
	//#endregion

	//#region	Constructor from known letters and held string.
	/**
	 * Creating a new alphabet unit which holds a certain string a knows certain letters.
	 * 
	 * @param	letters	The letter which shall be known by this new alphabet unit.
	 * @param	str		The string which shall be held by this new alphabet unit.
	 * 
	 * @throws	NullPointerException	See also {@link #setStr(String)}, {@link #Alphabet(String)}.
	 */
	public Alphabet(final String letters, final String str)
	{
		//#region	Invoking another constructor.
		this(letters);
		//#endregion



		//#region	Processing the assignment.
		this.setStr(str);
		//#endregion



		//#region	Quitting the constructor properly.
		return;
		//#endregion



	};
	//#endregion
	//#endregion



	//#region	Getters and setters.
	//#region	Field letters.
	//#region	Method dropLetters().
	/** 
	 * Assigning a {@code nullptr} to the field {@code letters}.
	 * 
	 * @since	V1.1.0-en_GB // (20200516/20200516)
	 */
	public void dropLetters()
	{
		//#region	Processing the assignment.
		this.letters = null;
		//#endregion



		//#region	Quitting the method properly.
		return;
		//#endregion



	};
	//#endregion

	//#region	Method getLetters().
	/**
	 * The default getter method for the field {@code letters}.
	 * 
	 * @return	{@code this.letters}
	 */
	public String getLetters()	{return this.letters;};
	//#endregion

	//#region	Method setLetters().
	/**
	 * The default setter method for the field {@code letters}.
	 * 
	 * @param	str	The new list of all known letters.
	 * 
	 * @throws	NullPointerException	if invoked with a {@code nullptr}. Please consider using {@link #dropLetters()} instead.
	 */
	public void setLetters(final String str)
	{
		//#region	Processing the assignment.
		if(str != null)
			this.letters = str;
		else
			throw new NullPointerException("Why do you try to assign a nullptr?");
		//#endregion



		//#region	Quitting the method properly.
		return;
		//#endregion



	};
	//#endregion
	//#endregion

	//#region	Field str.
	//#region	Method dropStr().
	/** 
	 * Assigning a {@code nullptr} to the field {@code str}.
	 * 
	 * @since	V1.1.0-en_GB // (20200516/20200516)
	 */
	public void dropStr()
	{
		//#region	Processing the assignment.
		this.str = null;
		//#endregion



		//#region	Quitting the method properly.
		return;
		//#endregion



	};
	//#endregion

	//#region	Method getStr().
	/**
	 * The default getter method for the field {@code str}.
	 * 
	 * @return	{@code this.str}
	 */
	public String getStr()	{return this.str;};
	//#endregion

	//#region	Method setStr().
	/**
	 * The default setter method for the field {@code str}.
	 * 
	 * @param	str	The new string to hold by this alphabet unit.
	 * 
	 * @throws	NullPointerException	if invoked with a {@code nullptr}. Please consider using {@link #dropStr()} instead.
	 */
	public void setStr(final String str)
	{
		//#region	Processing the assignment.
		if(str != null)
			this.str = str;
		else
			throw new NullPointerException("Why do you try to assign a nullptr?");
		//#endregion



		//#region	Quitting the method properly.
		return;
		//#endregion



	};
	//#endregion
	//#endregion
	//#endregion



	//#region	Instance methods.
	//#region	Method extractInvalid().
	/**
	 * Searching for all characters which are not part of the defined alphabet.
	 *
	 * @return	All characters from the held string which are not part of this alphabet unit.
	 * 
	 * @throws	NullPointerException	if a no string is held at the moment.
	 */
	public String extractInvalid()
	{
		//#region	Variables.
		final StringBuilder ret = new StringBuilder();
		//#endregion



		//#region	Processing the extraction.
		if(this.str != null)
		{
			for(int i = 0; i < this.str.length(); ret.append(this.str.charAt(i++)));
			for(int i = this.str.length() - 1; i >= 0; i--)
				for(int j = 0; j < this.letters.length(); j++)
					if(this.str.charAt(i) == this.letters.charAt(j))
						ret.deleteCharAt(i);



		}
		else
			throw new NullPointerException("Characters cannot be extracted from a nullptr!");
		//#endregion



		//#region	Returning results.
		return ret.toString();
		//#endregion



	};
	//#endregion

	//#region	Method extractValid().
	/**
	 * Searching for all characters which are part of the defined alphabet.
	 *
	 * @return	All characters from the held string which are part of this alphabet unit.
	 * 
	 * @throws	NullPointerException	if a no string is held at the moment.
	 */
	public String extractValid()
	{
		//#region	Variables.
		final StringBuilder ret = new StringBuilder();
		//#endregion



		//#region	Processing the extraction.
		if(this.str != null)
		{
			for(int i = 0; i < this.str.length(); i++)
				for(int j = 0; j < this.letters.length(); j++)
					if(this.str.charAt(i) == this.letters.charAt(j))
						ret.append(this.str.charAt(i));



		}
		else
			throw new NullPointerException("Characters cannot be extracted from a nullptr!");
		//#endregion



		//#region	Returning results.
		return ret.toString();
		//#endregion



	};
	//#endregion

	//#region	Method getLeftNeighbour().
	/**
	 * Determining the left neighbouring character.
	 *
	 * @param	idx	The indexposition of the concerning letter.
	 * @return	Either the concerning character or a nullptr if there is no one.
	 * 
	 * @throws	NullPointerException		if invoked with a {@code nullptr} of {@code this.str} does not hold a string.
	 * @throws	IllegalArgumentException	if a {@code StringIndexOutOfBoundsException} would be caused.
	 * @throws	IllegalArgumentException	if both of the other failures happened.
	 */
	public Character getLeftNeighbour(final Integer idx)
	{
		//#region	Variables.
		Character ret = null;
		//#endregion



		//#region	Processing the selection.
		if(this.str != null && idx != null && idx > 0 && idx < this.str.length())
			ret = this.str.charAt(idx - 1);
		else if(this.str == null && (idx <= 0 || idx >= this.str.length()))
			throw new IllegalArgumentException("Please check your parameters again!");
		else if(this.str == null || idx == null)
			throw new NullPointerException("At least one parameter is a nullptr!");
		else if(idx <= 0 || idx >= this.str.length())
			throw new IllegalArgumentException("You are going to invoke a StringIndexOutOfBoundsException!");
		//#endregion



		//#region	Returning results.
		return ret;
		//#endregion



	};
	//#endregion

	//#region	Method getRightNeighbour().
	/**
	 * Determining the right neighbouring character.
	 *
	 * @param	idx	The indexposition of the concerning letter.
	 * @return	Either the concerning character or a nullptr if there is no one.
	 * 
	 * @throws	NullPointerException		if invoked with a {@code nullptr} of {@code this.str} does not hold a string.
	 * @throws	IllegalArgumentException	if a {@code StringIndexOutOfBoundsException} would be caused.
	 * @throws	IllegalArgumentException	if both of the other failures happened.
	 */
	public Character getRightNeighbour(final Integer idx)
	{
		//#region	Variables.
		Character ret = null;
		//#endregion



		//#region	Processing the selection.
		if(this.str != null && idx != null && idx >= 0 && idx < this.str.length() - 1)
			ret = this.str.charAt(idx + 1);
		else if(this.str == null && (idx < 0 || idx >= this.str.length() - 1))
			throw new IllegalArgumentException("Please check your parameters again!");
		else if(this.str == null || idx == null)
			throw new NullPointerException("At least one parameter is a nullptr!");
		else if(idx < 0 || idx >= this.str.length() - 1)
			throw new IllegalArgumentException("You are going to invoke a StringIndexOutOfBoundsException!");
		//#endregion



		//#region	Returning results.
		return ret;
		//#endregion



	};
	//#endregion

	//#region	Method isValidLetter().
	/**
	 * Checking if the letter is part of the defined alphabet.
	 *
	 * @param	chr	The character to test.
	 * @return	Either true if so or false, else.
	 * 
	 * @throws	NullPointerException		if invoked with a {@code nullptr}.
	 * 
	 * @since	V1.1.1-en_GB // (20200520/20200520)
	 */
	public Boolean isValidLetter(final Character chr)
	{
		//#region	Variables.
		Boolean ret = false;
		//#endregion



		//#region	Checking the parameter.
		if(chr == null)
			throw new NullPointerException("A nullptr could not be used to address an index!");
		//#endregion



		//#region	Processing the test.
		for(int i = 0; !ret && i < this.letters.length(); i++)
			if(chr == this.letters.charAt(i))
				ret = true;
		//#endregion



		//#region	Returning results.
		return ret;
		//#endregion



	};
	//#endregion

	//#region	Method isValidLetter().
	/**
	 * Checking if the letter at a certain index of the held string is part of the defined alphabet.
	 *
	 * @param	idx	The index whose corresponding letter shall be tested.
	 * @return	Either true if so or false, else.
	 * 
	 * @throws	NullPointerException		if invoked with a {@code nullptr}.
	 * @throws	IllegalArgumentException	if a {@code StringIndexOutOfBoundsException} would be caused.
	 */
	public Boolean isValidLetter(final Integer idx)
	{
		//#region	Variables.
		Boolean ret = false;
		//#endregion



		//#region	Checking the parameter.
		if(idx == null)
			throw new NullPointerException("A nullptr could not be used to address an index!");
		else if(idx < 0 || idx >= this.str.length())
			throw new IllegalArgumentException("You are going to invoke a StringIndexOutOfBoundsException!");
		//#endregion



		//#region	Processing the test.
		for(int i = 0; !ret && i < this.letters.length(); i++)
			if(this.str.charAt(idx) == this.letters.charAt(i))
				ret = true;
		//#endregion



		//#region	Returning results.
		return ret;
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
