/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| matriculation.java:                                                          |
|      A class which contains the method matriculate()                         |
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
| ! access error fixed														   |
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
 * A class which contains the method matriculate() 
 *
 * @author	Julian Nico Pielmaier
 * @version	V1.0.2-en_GB // (20200511/20200512)
 */
public class matriculation
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
	 * A method to matriculate students.
	 *
	 * @return	If the enrollment is successful the matriculation number is returned, otherwise -1;
	 */
	public Integer matriculate(String firstName, String lastName) 
	{
		//Variables
		boolean found = false;
		int ret = -1;
		
		
		
		//Sorting the list of students by their matriculation number
		Collections.sort(this.students, (s1, s2) -> s1.getMatriculationNumber().compareTo(s2.getMatriculationNumber()));
				
				
				
		//run through the list of all students
		for(int i = 0; i < students.size() && !found; i++) 
		{
			
			
			
			//find the next possible open matriculation number
			if(i != this.students.get(i).getMatriculationNumber()) 
			{
				//setting ret to matriculation number
				ret = ++ i;


			
				Student student = new Student(firstName, lastName, ret);
				students.add(student);
				found = true;
				
				

			};
			
			
			
		};
		
		
		
		return ret;
		
		
		
	};



};



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/
