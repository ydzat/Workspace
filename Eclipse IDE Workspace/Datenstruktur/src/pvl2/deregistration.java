/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| deregistration.java:                                                         |
|      A class which contains the method deregister()                        |
|                                                                              |
| V1.0.2-en_GB // (20200511/20200512)                                          |
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
| V1.0.2-en_GB // (20200511/20200512):                                         |
| + made it work as it should and not only as it was coded                     |
| + adjustments to CIG                                                         |
| + minor adjustments                                                          |
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

package pvl2;



/*SECTION**********************************************************************\
|                                                                              |
| Resources                                                                    |
|                                                                              |
\******************************************************************************/

//import g13.KevinMatthes590411.*;
import java.util.ArrayList;
import java.util.Collections;



/*SECTION**********************************************************************\
|                                                                              |
| Class definition (I)                                                         |
|                                                                              |
\******************************************************************************/

/**
 * A class which contains the method deregister()
 *
 * @author	Julian Nico Pielmaier
 * @version	V1.0.2-en_GB // (20200511/20200512)
 */
public class deregistration
{



/*SECTION**********************************************************************\
|                                                                              |
| Instance variables                                                           |
|                                                                              |
\******************************************************************************/

	/** Use the one in {@link PVL2_studentAdministration_Group13}*/
	private ArrayList<Student>	students;



/*SECTION**********************************************************************\
|                                                                              |
| Instance methods                                                             |
|                                                                              |
\******************************************************************************/

	/**
	 * A method to deregister students.
	 *
	 * @return	returns true if the student was deregistered, otherwise false
	 */
	public Boolean deregister(Integer matriculationNumber)
	{
		//Variables
		boolean found = false;
		
		
		
		//run through the list of all students
		for(int i = 0; i < students.size() && !found; i++)
		{
			
			
			
			//find the matriculation number to be deregister
			if(this.students.get(i).getMatriculationNumber() == matriculationNumber)
			{
				this.students.remove(i);
				found = true;
				
				
				
			};
			
			
			
		};
		
		
		
		//returning an error
		return found;
		
		
		
	};



};



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/
