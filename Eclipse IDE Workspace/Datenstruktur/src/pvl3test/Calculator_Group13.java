/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| Calculator_Group13.java:                                                     |
|      The required class in order to solve the third task.                    |
|                                                                              |
| V1.0.1-en_GB // (20200520/20200520)                                          |
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
| V1.0.0-en_GB // (20200515/20200516):                                         |
| + made it work as it should and not only as it was coded                     |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.0.1-en_GB // (20200520/20200520):                                         |
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
//package calculator_group_13;
package pvl3test;
//#endregion



//#region	Resources.
import java.util.ArrayList;
//#endregion



//#region	Class definition: Calculator_Group13
/**
 * The required class in order to solve the third task.
 *
 * @author	Kevin Matthes
 * @version	V1.0.1-en_GB // (20200520/20200520)
 */
public class Calculator_Group13 implements Calculator
{
	//#region	Instance methods.
	//#region	Method calculate().
	/**
	 * Calculating a valid expression.
	 * 
	 * @param	expression	The expression to calculate.
	 * @return	The value which is described by the given expression.
	 * 
	 * @author	Felix Vogel
	 * @author	Julian Nico Pielmaier
	 * @version	V1.1.0-en_GB // (20200520/20200520)
	*/
	public int calculate(final String expression)
	{
		//#region	Variables.
		int ret = 0;
		//#endregion



		//#region	Creating a term from the given expression.
		Term t = new Term(expression);
		//#endregion
		
		
		
		//#region	Calculate the expression.
		String res = t.CalculateTerm();
		ret = Integer.parseInt(res);
		//#endregion



		//#region	Returning results.
		return ret;
		//#endregion



	};
	//#endregion

	//#region	Method isValidExpression().
	/**
	 * Checking if an expression is valid. This test is designed like a graphics pipeline, so easier tests are per-
	 * formed before the more resource intensive and also more complex ones.
	 * 
	 * @param	expression	The expression to validate.
	 * @return	Either {@code true} if it is valid or {@code false}, otherwise.
	 * 
	 * @author	Kevin Matthes
	 * @version	V1.0.0-en_GB // (20200515/20200516)
	 */
	public boolean isValidExpression(final String expression)
	{
		//#region	Variables.
		final Alphabet	a		= new Alphabet("+*"),
						b		= new Alphabet("0123456789"),
						c		= new Alphabet("()"),
						sign	= new Alphabet("-"),
						space	= new Alphabet(" ");

		final ArrayList<String>	strList	= new ArrayList<>();

		boolean	bracketCheckFailed					= false,
				grammaticallyValid					= false,
				isNotEmpty							= false,
				isNotANullptr						= false,
				lexicallyValid						= false,
				mathematicallyValid					= false,
				parentheticallyMatching				= false,
				parentheticallySufficient			= false,
				parentheticallyValid				= false,
				ret									= false,
				separatedDetailedSufficient			= false,
				separatedSuperficiallySufficient	= false,
				separatedValid						= false,
				separationCheckFailed				= false;

		char	nextCharacter		= 222,
				previousCharacter	= 222,
				thisCharacter		= 222;

		String	brackets	= null;
		//#endregion



		//#region	1. The simplest tests: Is expression an empty string or null?
		if(expression != null)
			isNotANullptr = true;

		if(isNotANullptr && expression.length() != 0)
			isNotEmpty = true;
		//#endregion



		//#region	2. Checking superficially for valid separation with spaces at first.
		if(isNotEmpty)
		{
			space.setStr(expression);
			if(space.extractValid().length() != 0 && expression.charAt(0) != ' ' && expression.charAt(expression.length() - 1) != ' ')
				separatedSuperficiallySufficient = true;



		};
		//#endregion



		//#region	3. Checking for invalid characters within expression, next.
		if(separatedSuperficiallySufficient)
		{
			//#region	3.1. Preparing the alphabet units.
			space.dropStr();
			//#endregion



			//#region	3.2. Reducing the expression successively to theoretical invalid characters,
			a.setStr(expression);
			b.setStr(a.extractInvalid());
			c.setStr(b.extractInvalid());
			space.setStr(c.extractInvalid());
			//#endregion



			//#region	3.3. Interpreting the recent test results.
			if(space.getStr().isEmpty())
				lexicallyValid = true;
			//#endregion



		};
		//#endregion



		//#region	4. Now, checking for the parenthetical validity of the expression.
		if(lexicallyValid)
		{
			//#region	4.1. At first, the alphabet units will be prepared for their next usages.
			a.dropStr();
			b.dropStr();
			c.dropStr();
			space.dropStr();

			c.setStr(expression);
			//#endregion



			//#region	4.2. The next step is to check, if there are enough brackets.
			brackets = c.extractValid();
			if(brackets.length() % 2 == 0)
				parentheticallySufficient = true;
			//#endregion



			//#region	4.3. Now, checking if the brackets are matching using a stack.
			if(brackets.length() > 0 && parentheticallySufficient)
			{
				for(int i = 0; !bracketCheckFailed && i < brackets.length() - 1; i++)
					if(brackets.charAt(i) == '(')
						strList.add("(");
					else if(strList.size() > 0 && brackets.charAt(i) == ')')
						strList.remove(strList.size() - 1);
					else
						bracketCheckFailed = true;



			}
			else if(brackets.length() == 0 && parentheticallySufficient)
				parentheticallyMatching = true;
			else
				bracketCheckFailed = true;
			//#endregion



			//#region	4.4. Finally, if there are both enough AND matching brackets, this test is passed successfully.
			if(!bracketCheckFailed && parentheticallyMatching && parentheticallySufficient)
				parentheticallyValid = true;
			//#endregion



		};
		//#endregion



		//#region	5. Next, checking if really each token is separated by a space.
		if(parentheticallyValid)
		{
			//#region	5.1. Preparing the alphabet units.
			c.dropStr();

			space.setStr(expression);
			//#endregion



			//#region	5.2. Checking for space separation.
			for(int i = 0; !separationCheckFailed && i < expression.length() - 1; i++)
			{
				thisCharacter = space.getStr().charAt(i);
				nextCharacter = space.getRightNeighbour(i);

				//#error

				if
				(
					(!b.isValidLetter(previousCharacter) && thisCharacter == previousCharacter)
					// || ()
					
					
					
				)
					separationCheckFailed = true;
				else
					previousCharacter = thisCharacter;



			};
			//#endregion



			//#region	5.9. Interpreting the results of the previous tests.
			if(!separationCheckFailed && separatedDetailedSufficient && separatedSuperficiallySufficient)
				separatedValid = true;
			//#endregion



		};
		//#endregion
		


		//#region	6. Interpreting the test results.
		if
		(
			isNotEmpty
			&& isNotANullptr
			&& grammaticallyValid
			&& lexicallyValid
			&& mathematicallyValid
			&& parentheticallyValid
			&& separatedValid
			
			
			
		)
			ret = true;
		//#endregion



		//#region	Tidying up.
		a.dropLetters();
		b.dropLetters();
		c.dropLetters();
		sign.dropLetters();
		space.dropLetters();
		
		a.dropStr();
		b.dropStr();
		c.dropStr();
		sign.dropStr();
		space.dropStr();
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
