/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| TermCalculateUtil.java:                                                      |
|      Splits the string into single terms which can then be calculated 	   |
|	   seperately. 															   |
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
 * {@summary	<br>Splits the string into single terms which can then be calculated seperately.<p>}
 * @author	Felix Vogel
 * @author	Julian Nico Pielmaier
 * @author	Kevin Matthes
 * @version	V1.1.0-en_GB // (20200520/20200520)
 */
public abstract class TermCalculateUtil
{



/*SECTION**********************************************************************\
|                                                                              |
| Class methods                                                                |
|                                                                              |
\******************************************************************************/

	/**
	 * {@summary	<br>Substitutes the term inside braces with it's result.<p>}
	 * Example: <br> {@code "(13 + 10) * 10" -> "23 * 10"}
	 * @param str	the term string
	 * @return	a string where the braces term is replaced with the calculation of that term
	 */
	public static String SubstituteBraces(String str)
	{
		
		//Variables.
		Term t = null;
		String bracesTerm = null;
		String replacement = null;
		String ret = null;
		
		
		
		//Check if term contains braces
		if((!str.contains("(")) || (!str.contains(")")))
			{ret =  str;}
		
		
		
		else 	
		{
			
			
			//Variables.
			int openBracesIndex = -1;
			int closedBracesIndex = -1;
			boolean found = false;
			
			
			//Searching for inner term
			for (int i = 0; i < str.length() && !found; i++)
			{		
				if(str.charAt(i) == '(')
				{
					openBracesIndex = i;
				}	
				else if(str.charAt(i) == ')')
				{
					closedBracesIndex = i;
					found = true;
				};	
			};
			
			
			
			//Getting the braces term
			bracesTerm = str.substring(openBracesIndex, closedBracesIndex + 1);
			
		
			
			//Creating the Term from inside the braces
			t = new Term(bracesTerm);
		
		
		
			//get rid of the braces
			Alphabet c = new Alphabet("()", t.GetTermString());
			replacement = c.extractInvalid();
		
			
		
			//calculate the multiplication term if exists
			while(replacement.contains("*"))
				{replacement = SubstituteMultiplication(replacement);};
			//calculate addition if exists
			while(replacement.contains("+"))
				{replacement = CalculateAddition(replacement);};
		
	
			
			//replace the braces term with its result
			ret = str.replace(bracesTerm, replacement);
			
			
			
		};
		
		
		
		return ret;
	
		
		
	};
	
	
	
	/**
	 * {@summary	<br>Substitutes the multiplication term with it's result inside the term.<p>}
	 * 
	 * One call for every multiplication term! <br>
	 * Example: <br> {@code "13 + 10 * 10" -> "13 + 100"}
	 * @param str	the term string
	 * @return	A string where the multiplication term is replaced with the calculation of that term
	 */
	public static String SubstituteMultiplication(String str)
	{
		
		//Variables.
		String ret = null;
		String[] strArray = str.split(" ");
		int idx = -1;

		
		
		//Search for the operator.
		for (int i = 0; i < strArray.length; i++)
		{
			if(strArray[i].equals("*"))
			{
				idx = i;
				break;
			};
		};

		
		
		//Determine the 2 operands.
		Integer leftOperand = Integer.parseInt(strArray[idx-1]);
		Integer rightOperand = Integer.parseInt(strArray[idx+1]);
		
		
		
		//Calculate the result.
		int result = leftOperand * rightOperand;
		
		
		
		//Replace the term with it's result
		String toReplace = leftOperand + " * " + rightOperand;
		ret = str.replace(toReplace, String.valueOf(result));
		
		
		
		return ret;
		
		
		
	};
	
	
	
	/**
	 * {@summary	<br>Calculates a String with only summands.<p>}
	 * @param str 	format: [op(1)] + [op(2)] + ... + [op(n-1)] + [op(n)]
	 * @return	the result of the addition as a String.
	 */
	public static String CalculateAddition(String str)
	{
		//Variables
		String ret = null;
		int acc = 0;
		
		
		
		//Make sure there are operators in the string
		if(!str.contains("+"))
			{ret = str;}
		
		
		
		else 
		{
			//Split the string into its operators.
			String[] splitStr = str.split(" ");
			
			
			
			//calculate the result.
			for (String s : splitStr)
			{
				try
				{
					Integer operand = Integer.valueOf(s);
					acc += operand;
				}
				catch (NumberFormatException e) 
				{
					
				};
			};
		
			
			
			ret = String.valueOf(acc);
			
			
			
		};
		
		
		
		//returning the result
		return ret;
		
		
		
	};



};



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/
