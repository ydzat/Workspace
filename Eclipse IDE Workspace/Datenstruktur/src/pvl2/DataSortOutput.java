/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| DataSortOutput.java:                                                         |
|      A class which contains the method dataBase()                            |
|                                                                              |
| V1.0.0-en_GB // (20200508/20200509)                                          |
| (C)  Felix Vogel (591520)                                                    |
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
| V1.0.0-en_GB // (20200508/20200509):                                         |
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

//import g13.KevinMatthes590411.Student;
import java.util.ArrayList;
import java.util.Collections;



/*SECTION**********************************************************************\
|                                                                              |
| Class definition (I)                                                         |
|                                                                              |
\******************************************************************************/

/**
 * A class which contains the method dataBase()
 *
 * @author	Felix Vogel
 * @version	V1.0.0-en_GB // (20200508/20200509)
 */
public class DataSortOutput
{
	


/*SECTION**********************************************************************\
|                                                                              |
| Instance variables                                                           |
|                                                                              |
\******************************************************************************/

	/** Use the one in {@link PVL2_studentAdministration_Group13}*/
	private ArrayList<Student> students;

	
	
/*SECTION**********************************************************************\
|                                                                              |
| Instance methods                                                             |
|                                                                              |
\******************************************************************************/

	/**
	 * Returning all stored information about the students of this administration unit.
	 *
	 * @return	All known students, sorted by their matriculation numbers.
	 */
	public String dataBase()
	{
		
		//Sorting the list of students by their matriculation number
		Collections.sort(this.students, (s1, s2) -> s1.getMatriculationNumber().compareTo(s2.getMatriculationNumber()));
		
		
		
		//Creating the output string
		StringBuilder str = new StringBuilder();
		
		for (var student : students)
		{
			str.append(student.getForename() + "\n" + student.getSurname() + "\n" + student.getMatriculationNumber() + "\n");
			str.append(student.getCourses());
			str.append("\n");
		};
		
		
		
		//returning the string
		return str.toString();
		
		
		
	};


	
};