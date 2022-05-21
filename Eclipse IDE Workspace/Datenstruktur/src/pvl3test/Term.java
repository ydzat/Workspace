/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| Term.java:                                                                   |
|      Class to describe a math term.                                          |
|                                                                              |
| V1.0.0-en_GB // (20200518/20200518)                                          |                        
| (C) 2020 Felix Vogel (591520), Julian Nico Pielmaier (591773),               |
|          Kevin Matthes (590411)                                              |
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
| V1.0.0-en_GB // (20200518/20200518)                                          |
| + made it work as it should and not only as it was coded                     |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.1.0-en_GB // (20200520/20200520)                                          |
| ! minor adjustments                                                          |
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

//package calculator_group_13;
package pvl3test;


/*SECTION**********************************************************************\
|                                                                              |
| Class definition (I)                                                         |
|                                                                              |
\******************************************************************************/

/**
 * {@summary	<br>Class to describe a math term.<p>}
 * @author	Felix Vogel
 * @author	Julian Nico Pielmaier
 * @author	Kevin Matthes
 * @version	V1.1.0-en_GB // (20200520/20200520)
 */
public class Term
{



/*SECTION**********************************************************************\
|                                                                              |
| Instance variables                                                           |
|                                                                              |
\******************************************************************************/

	/** The term's string */
	private String termString = null;
	// private String termString = "";

	

/*SECTION**********************************************************************\
|                                                                              |
| Constructors                                                                 |
|                                                                              |
\******************************************************************************/

	/**
	 * {@summary	<br>Creates a new term.<p>}
	 * @param str 	the terms string
	 */
	public Term(String str)
	{
		// Processing the assignment.
		this.termString = str;



		// Quitting the constructor properly.
		return;
	
	
	
	};	



/*SECTION**********************************************************************\
|                                                                              |
| Getters and setters                                                          |
|                                                                              |
\******************************************************************************/

	/**
	 * {@summary	<br>Gets the term string.<p>}
	 * @return the term's string
	 */
	public String GetTermString()	{return termString;};
	
	
	
	/**
	 * {@summary	<br>Sets the new term string.<p>}
	 * @param val	new term string
	 */
	public void SetTermString(String val)	{this.termString = val;};
	
	

/*SECTION**********************************************************************\
|                                                                              |
| Instance methods                                                             |
|                                                                              |
\******************************************************************************/

	/**
	 * {@summary	<br>Top-level method to calculate the term.<p>}
	 * @return	null, when termString is empty. Otherwise term result as string.
	 */
	public String CalculateTerm()
	{
		
		//Variables.
		String ret = null;
		
		
		
		if(termString.isEmpty())
			ret = null;
		else
		{
			ret = termString;
			
			
			
			//First, substitute all brace terms.
			while(ContainsBraceTerm(ret))
				{ret = TermCalculateUtil.SubstituteBraces(ret);};
			
			//Second, substitute all multiplication terms.
			while(ContainsMultiplicationTerm(ret))
				{ret = TermCalculateUtil.SubstituteMultiplication(ret);};
			
			//Third, substitute all addition terms.
			ret = TermCalculateUtil.CalculateAddition(ret);
		};
		
		
		
		return ret;
		
		
		
	};
	
	
	/**
	 * {@summary	<br> Checks if the term contains brace terms.<p>}
	 * @param str the term's string
	 * @return If term contains one or more brace terms.
	 */
	public boolean ContainsBraceTerm(String str)	{return (str.contains("(")) && (str.contains(")"));};
		
	
		
	/**
	 * {@summary	<br> Checks if the term contains multiplication terms.<p>}
	 * @param	str	the term's string
	 * @return If term contains one or more multiplication terms.
	 */
	public boolean ContainsMultiplicationTerm(String str)	{return (str.contains("*"));};



};



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/
