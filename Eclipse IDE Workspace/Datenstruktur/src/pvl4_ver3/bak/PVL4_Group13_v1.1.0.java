/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| PVL4_Group13.java:                                                           |
|      en_GB                                                                   |
|                                                                              |
| V1.0.0-Dongze Yang, Felix Vogel // (20200521/20200521)                       |
| (C)  574145, 591520                                                          |
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
| V1.0.0-Dongze Yang // (20200521/20200521):                                   |
| + made it work as it should and not only as it was coded                     |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.1.0-Dongze Yang, Felix Vogel // (20200522/20200522):                      |
| + adding Constructor                    									   |
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
package pvl4_ver3;
// .



/*SECTION**********************************************************************\
|                                                                              |
| Resources                                                                    |
|                                                                              |
\******************************************************************************/
import java.util.ArrayList;
// .



/*SECTION**********************************************************************\
|                                                                              |
| Class definition (I)                                                         |
|                                                                              |
\******************************************************************************/

/**
 * en_GB
 *
 * @author	574145
 * @version	V1.0.0-Dongze Yang // (20200521/20200521)
 */
public class PVL4_Group13
{



/*SECTION**********************************************************************\
|                                                                              |
| Instance variables                                                           |
|                                                                              |
\******************************************************************************/

	/** The following alphabet and probs are the default format for calling in encode (). 
	* In actual operation, its value should be determined by the "constructor", 
	* I am not very clear who is responsible for this part. --by Dongze Yang*/
	private char[] alphabet = new char[] {'a','b','c'};
	private float[] probs = new float[]{0.25f, 0.5f, 0.25f};
	HfmTree hfm = new HfmTree();


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

	public PVL4_Group13(char[] alphabet, float[] probabilities)
	{
		
		//Assigning values.
		this.alphabet = alphabet;
		this.probs = probabilities;
		
		
		
		//Creating the huffmann tree
		hfm = new HfmTree();
		hfm.createHfmTree(probabilities);
		
		
		
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

	/** Some more code here… */

	public String getCodes() {
		return null;
	}

	
	/**
   	 * @description: Create a Huffman tree according to probs, 
  	 *  thereby determining the Huffman code corresponding to each character
 	 * @param String plainText
 	 * @return: Huffman coding (Composed of 1 and 0)
 	 * @author: Dongze Yang
 	 * @ver: 20200521-2100
 	 */ 
 	public String encode(String plainText) {
		
		/**
  		 * @description: Create a Huffman tree according to probs, 
		 *  The function of output() is to check the code assigned by the letter
  		 * @param {type} 
  		 * @return: No return value
  		 */  
 		
 		/*
 		 * 
 		 * I would not create the huffmann tree in here, it has already been created in the constructor :). 
 		 * -Felix Vogel
 		 * 
 		 */
 		hfm.createHfmTree(probs);
		//hfm.output(); //check √
		
		/**
  		 * @description: Calculate Huffman encoding for plainText based on encoding and alphabetical order
 		 * @param {type} 
 		 * @return: 
 		 */  
 		return hfm.toHfmCode(plainText);
	}

	public String decode(String huffmanText) {
		
		return null;
	}


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
