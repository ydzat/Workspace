/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| PVL4_13.java:                                                                |
|      The class in order to solve the fourth graded task.                     |
|                                                                              |
| V1.2.1-en_GB // (20200528/20200528)                                          |
| (C)  Dongze Yang (574145), Felix Vogel (591520), Kevin Matthes (590411)      |
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
| ? feature udea left for future version                                       |
| * information                                                                |
|   (editing periods in brackets behind version                                |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.0.0-en_GB // (20200521/20200521):                                         |
| + made it work as it should and not only as it was coded                     |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.1.0-en_GB  // (20200522/20200522):                                        |
| + adding Constructor                                                         |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.2.0-en_GB  // (20200527/20200527):                                        |
| ! adjustments                                                                |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.2.1-en_GB  // (20200528/20200528):                                        |
| ! HfmTree.java bug fix                                                       |
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
package PVL4_Group13;
//#endregion



//#region	Resources.
import java.util.ArrayList;
//#endregion



//#region	Class definition: PVL4_13.
/**
 * The class in order to solve the fourth graded task.
 *
 * @author	Dongze Yang
 * @author	Kevin Matthes
 * @version	V1.2.1-en_GB // (20200528/20200528)
 */
public class PVL4_Group13
{
	//#region	Instance variables.
	/** The held alphabet. */
	private	char[]	alphabet	= null;

	/** The propabilities of each letter of this unit's alphabet. */
	private	float[]	probs		= null;

	/** The Huffman tree held by this unit. */
	private	HfmTree	hfm			= new HfmTree();
	//#endregion

	//#region	Constructors.
	//#region	The default constructor.
	/**
	 * The default constructor.
	 * 
	 * @param	alphabet		The alphabet which shall be encoded by this unit's huffman tree.
	 * @param	probabilities	The occurence probabilities for each letter of the held alphabet.
	 * 
	 * @author	Felix Vogel
	 * @author	Kevin Matthes
	 * @version	V1.0.1-en_GB // (20200527/20200527)
	 */
	public PVL4_Group13(char[] alphabet, float[] probabilities)
	{
		// Assigning values.
		this.alphabet = alphabet;
		this.probs = probabilities;
		
		
		
		// Creating the huffmann tree.
		// ! Add the variable "alphabet" (20200528)
		this.hfm.createHfmTree(this.probs, this.alphabet);
		
		
		
		// Quitting the constructor properly.
		return;
		
		
		
	};
	//#endregion
	//#endregion

	//#region	Instance methods.
	//#region	Method decode().
	/**
	 * The coding a given plain text.
	 * 
	 * @param	huffmanText	The text which shall be decoded using this unit's Huffman tree.
	 * @return	The decoded text.
	 * 
	 * @author	Julian Nico Pielmaier
	 * @version	V0.0.0-en_GB(¿¿¿¿¿¿¿¿/????????)
	 */
	public String decode(String huffmanText)
	{
		//#error
		return null;


		
	};
	//#endregion

	//#region	Method encode().
	/**
	 * Encoding the given plain text using this unit's Huffman tree.
	 * 
 	 * @param	plainText	The text to encode.
	 * @return	Huffman coding (composed of 1 and 0) of the given text.
	 * 
 	 * @author	Dongze Yang
 	 * @version	V1.0.0-en_GB // (20200521/20200521)
 	 */ 
	public String encode(String plainText)	{return hfm.toHfmCode(plainText);};
	  //#endregion
  
	//#region	Method getCodes().
	/** 
	 * Returning all stored encodings of this unit's Huffman tree as a string.
	 * 
	 * @return	All by this unit's Huffman tree available encodings.
	 */
	public String getCodes()
	{
		//#error
		return null;



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
