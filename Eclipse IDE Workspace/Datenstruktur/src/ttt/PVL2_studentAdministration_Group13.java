/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| PVL2_studentAdministration_Group13.java:                                     |
|      The required top level class.                                           |
|                                                                              |
| V1.1.0-en_GB // (20200513/20200513)                                          |
| (C) 2020 Kevin Matthes (590411), Felix Vogel (591520),                       |
|          Julian Nico Pielmaier (591773), Dongze Yang (574145)                |
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
| V1.0.0-en_GB // (20200505/20200513):                                         |
| + made it work as it should and not only as it was coded                     |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.0.1-en_GB // (20200508/20200508):                                         |
| ! minor adjustments                                                          |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.0.2-en_GB // (20200509/20200509):                                         |
| + included dataBase() by Felix Vogel                                         |
| ! minor adjustments                                                          |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.1.0-en_GB // (20200513/20200513):                                         |
| ! improved strucure concept for this project                                 |
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

package ttt;



/*SECTION**********************************************************************\
|                                                                              |
| Resources                                                                    |
|                                                                              |
\******************************************************************************/

import java.util.ArrayList;
import java.util.Collections;



/*SECTION**********************************************************************\
|                                                                              |
| Class definition (I)                                                         |
|                                                                              |
\******************************************************************************/

/**
 * The required top level class.
 *
 * @author	Kevin Matthes
 * @version	V1.1.0-en_GB // (20200513/20200513)
 */
public class PVL2_studentAdministration_Group13 implements StudentAdministration
{



/*SECTION**********************************************************************\
|                                                                              |
| Instance variables                                                           |
|                                                                              |
\******************************************************************************/

	/** The students known by this administration unit. */
	private ArrayList<Student>	students	= new ArrayList<>(999);

	/** The courses held by this administration unit. */
	private ArrayList<Course>	courses		= new ArrayList<>();



/*SECTION**********************************************************************\
|                                                                              |
| Constructors                                                                 |
|                                                                              |
\******************************************************************************/

	/** The default constructor in order to create a new administration unit. */
	public PVL2_studentAdministration_Group13()	{return;};



/*SECTION**********************************************************************\
|                                                                              |
| Getters and setters                                                          |
|                                                                              |
\******************************************************************************/

	/**
	 * The default getter method for all known students.
	 *
	 * @return	All known students.
	 */
	public String getStudents()	{return dataBase();};



/*SECTION**********************************************************************\
|                                                                              |
| Instance methods                                                             |
|                                                                              |
\******************************************************************************/

	/**
	 * Returning all stored information about the students of this administration unit.
	 *
	 * @return	All known students, sorted by their matriculation numbers.
	 *
	 * @author	Felix Vogel
	 * @version	V1.1.0-en_GB // (20200513/20200513)
	 */
	@Override
	public String dataBase()
	{
		// Variables.
		StringBuilder str = new StringBuilder();



		// Sorting the list of students by their matriculation number.
		Collections.sort(this.students, (s1, s2) -> s1.getMatriculationNumber().compareTo(s2.getMatriculationNumber()));



		// Creating the output string.
		for (var student : students)
		{
			str.append(student.getForename() + "\n" + student.getSurname() + "\n" + student.getMatriculationNumber() + "\n");
			str.append(student.getCourses());
			str.append("\n");



		};



		// Returning the string.
		return str.toString();



	};



	/**
	 * Deregistering a student of this administration unit.
	 *
	 * @param	matriculationNumber	The student's identifier.
	 * @return	Either true if succeeded or false if there is no such student.
	 *
	 * @author	Julian Nico Pielmaier
	 * @version	V1.1.0-en_GB // (20200513/20200513)
	 */
	@Override
	public Boolean deregister(Integer matriculationNumber)
	{
		// Variables.
		Boolean found = false;



		//checking for null pointer
		if(matriculationNumber == null)
			found = null;
		else
		{
			// Running through the list of all students.
			for(int i = 0; i < students.size() && !found; i++)
			{
				//find the matriculation number to be deregister
				if(this.students.get(i).getMatriculationNumber() == matriculationNumber)
				{
					this.students.remove(i);
					found = true;



				};



			};



		};



		// Returning results.
		return found;



	};



	/**
	 * Returning all information about a certain student of this administration unit.
	 *
	 * @param	matriculationNumber The student's identifier.
	 * @return	All information the student with this matriculation number.
	 *
	 * @author	Dongze Yang
	 * @version	V1.2.0-en_GB // (20200513/20200514)
	 */
	@Override
	public String find(Integer matriculationNumber)
	{
		// Variables.
		boolean			found	= false,				wrong = false;
		int				low		= 0;
		int				high	= students.size() - 1;
		int				middle	= 0;
		StringBuilder	ret		= new StringBuilder();

		// Confirming whether the matriculation number is "registered". And prevent out of bounds in the next else if.
		if((high < 0) || (students.size() == 0)) 
		{
			wrong = true;
		}
		else if((matriculationNumber < students.get(low).getMatriculationNumber()) || (matriculationNumber > students.get(high).getMatriculationNumber()) || (low > high))
		{
			wrong = true;
		};



		// Binary search the students.
		while(!wrong && !found && low <= high)
		{
			middle = (low + high) / 2;
			if(students.get(middle).getMatriculationNumber() > matriculationNumber)
			{
				high = middle - 1;



			}
			else if(students.get(middle).getMatriculationNumber() < matriculationNumber)
			{
				low = middle + 1;



			}
			else
			{
				ret.append(students.get(middle).getForename() + "\n" + students.get(middle).getSurname() + "\n" + students.get(middle).getMatriculationNumber() + "\n" + students.get(middle).getCourses() );
				found = true;



			};



		};



		// No student was found.
		if(!wrong && !found)
			return null;

		// Returning results.
		return ret.toString();



	};



	/**
	 * Adding a new student to this administration unit.
	 *
	 * @param	firstName	The new student's forename.
	 * @param	lastName	The new student's surname.
	 * @return	The new student's identifier.
	 *
	 * @author	Julian Nico Pielmaier
	 * @version	V1.1.0-en_GB // (20200513/20200513)
	 */
	@Override
	public Integer matriculate(String firstName, String lastName)
	{
		// Variables.
		boolean found = false;
		Integer ret = -1;



		if(firstName == null || lastName == null)
			ret = null;
		else
		{
			// Sorting the list of students by their matriculation number.
			Collections.sort(this.students, (s1, s2) -> s1.getMatriculationNumber().compareTo(s2.getMatriculationNumber()));



			// Running through the list of all students.
			for(int i = 0; i <= students.size() && !found; i++)
			{
				try
				{
					// Finding the next possible open matriculation number.
					if(i != this.students.get(i).getMatriculationNumber() - 1)
					{
						// Setting ret to matriculation number.
						ret = ++i;
						Student student = new Student(firstName, lastName, ret);
						students.add(student);
						found = true;



					};



				}
				catch (IndexOutOfBoundsException e)
				{
					// Setting ret to matriculation number.
					ret = ++i;
					Student student = new Student(firstName, lastName, ret);
					students.add(student);
					found = true;



				};



			};



		};



		// Returning results.
		return ret;



	};



	/**
	 * Adding a course to a certain student of this administration unit.
	 *
	 * @param	matriculationNumber	The student's identifier.
	 * @param	courseID			The course which shall be added to the student.
	 * @param	passed				Did the student succeed this course?
	 *
	 * @author	Kevin Matthes
	 * @version	V1.0.0-en_GB // (20200513/20200513)
	 */
	@Override
	public String takeExam(Integer matriculationNumber, String courseID, Boolean passed)
	{
		// Variables.
		int 	crs	= -1,		idx = -1;
		String	ret	= "initial";



		// Checking the input parameters.
		if(matriculationNumber == null || courseID == null || passed == null)
			ret = null;



		// Processing the exam.
		if(ret != null)
		{
			// Searching the intended student.
			boolean found = false;

			for(int i = 0; i < this.students.size() && !found; i++)
				if(this.students.get(i).getMatriculationNumber() == matriculationNumber)
				{
					idx		= i;
					found	= true;



				};

			if(!found)
			{
				ret = "";



			};



			// Searching for the student's courses.
			if(ret.equals("initial"))
			{
				ArrayList<Course>	list = this.students.get(idx).getCourses(true);
				int					here = 0;

				found = false;

				for(int i = 0; i < list.size() && !found; i++)
				{
					if(list.get(i).getCourseID().equals(courseID))
					{
						list.get(i).pass(passed);

						if(list.get(i).getNumberOfTries() >= 3 && !list.get(i).isPassed())
						{
							deregister(this.students.get(idx).getMatriculationNumber());



						};

						crs = i;

						found = true;



					};



				};

				if(!found)
				{
					list.add(new Course(courseID, courseID, passed));



				};

				here = (crs == -1) ? list.size() - 1 : crs;
				ret = list.get(here).getCourseName() + "\t" + list.get(here).getNumberOfTries() + "\t" + list.get(here).isPassed();



			};



		};



		// Returning results.
		

		return ret;


	};



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
