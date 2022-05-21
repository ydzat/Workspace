/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| Main.java:                                                                   |
|      A simple main for testing purposes.                                     |
|                                                                              |
| V1.0.0-en_GB // (20200514/20200515)                                          |
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
| V1.0.0-en_GB // (20200514/20200515):                                         |
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
/*SECTION**********************************************************************\
|                                                                              |
| Package                                                                      |
|                                                                              |
\******************************************************************************/

// .
//#endregion



//#region	Resources.
/*SECTION**********************************************************************\
|                                                                              |
| Resources                                                                    |
|                                                                              |
\******************************************************************************/

//import calculator_group_13.Alphabet;
//import calculator_group_13.Calculator_Group13;

package pvl3test;
import static java.lang.System.out;
//#endregion



//#region	This file's top level class.
/*SECTION**********************************************************************\
|                                                                              |
| Class definition (I)                                                         |
|                                                                              |
\******************************************************************************/

/**
 * A simple main for testing purposes.
 *
 * @author	Kevin Matthes
 * @version	V1.0.0-en_GB // (20200514/20200515)
 */
public class Main
{



/*SECTION**********************************************************************\
|                                                                              |
| Class methods                                                                |
|                                                                              |
\******************************************************************************/

	//#region	Method main().
	/** 
	 * The main method.
	 * 
	 * @param	args	The command line options (unrevealed).
	 */
	public static void main(final String[] args) {
		//#region	Variables.
		final Alphabet a = new Alphabet("*+");
		final Calculator_Group13 calc = new Calculator_Group13();
		//#endregion



		//#region	Processing the test.
		a.setStr("+*()/*87641345461315634685*+*+*+*");
		out.println(a.extractValid());
		out.println(a.extractInvalid());
		out.println(calc.isValidExpression("+*()/*87641345461315634685*+*+*+*"));
		//#endregion



		//#region	Quitting the application properly.
		return;
		//#endregion



	};
	//#endregion



/*SECTION**********************************************************************\
|                                                                              |
| Class definition (II)                                                        |
|                                                                              |
\******************************************************************************/

};
//#endregion



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/
