/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| Student.java:                                                                |
|      A simple class in order to describe a student.                          |
|                                                                              |
| V1.1.0-en_GB // (20200513/20200513)                                          |
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
| V1.0.0-en_GB // (20200505/20200508):                                         |
| + made it work as it should and not only as it was coded                     |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.0.1-en_GB // (20200509/20200509):                                         |
| ! major adjustments                                                          |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.0.2-en_GB // (20200510/20200510):                                         |
| ! major adjustments                                                          |
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
 * A simple class in order to describe a student.
 *
 * @author	Kevin Matthes
 * @version	V1.1.0-en_GB // (20200513/20200513)
 */
public class Student
{



/*SECTION**********************************************************************\
|                                                                              |
| Instance variables                                                           |
|                                                                              |
\******************************************************************************/

	/** This student's list of all courses. */
	private ArrayList<Course> courses	= new ArrayList<>();

	/** This student's forename. */
	private String forename				= null;

	/** This student's internal identifier. */
	private Integer matriculationNumber	= 0;

	/** This student's surname. */
	private String surname				= null;



/*SECTION**********************************************************************\
|                                                                              |
| Constructors                                                                 |
|                                                                              |
\******************************************************************************/

	/** The default constructor for this class. */
	public Student()	{return;};



	/**
	 * Creating a new student from their forename and surname.
	 *
	 * @param	forename	The new student's forename.
	 * @param	surname		The new student's surname.
	 */
	public Student(String forename, String surname)
	{
		// Processing the configuration of the student.
		this.forename	= forename;
		this.surname	= surname;



		// Quitting the constructor properly.
		return;



	};



	/**
	 * Creating a new student from their forename, surname and matriculation number.
	 *
	 * @param	forename			The new student's forename.
	 * @param	surname				The new student's surname.
	 * @param	matriculationNumber	The new student's identifier.
	 */
	public Student(String forename, String surname, Integer matriculationNumber)
	{
		// Processing the configuration of the student.
		this.forename			= forename;
		this.matriculationNumber= matriculationNumber;
		this.surname			= surname;



		// Quitting the constructor properly.
		return;



	};



	/**
	 * The default copy constructor.
	 *
	 * @param	student	The student to copy.
	 */
	public Student(Student student)
	{
		// Processing the copying.
		this.forename			= new String(student.forename);
		this.matriculationNumber= new Integer(student.matriculationNumber);
		this.surname			= new String(student.surname);

		for(var c : student.courses)
			this.courses.add(new Course(c));



		// Quitting the constructor properly.
		return;



	};



/*SECTION**********************************************************************\
|                                                                              |
| Getters and setters                                                          |
|                                                                              |
\******************************************************************************/

	// Field courses.
		/**
		 * Querying this student's courses.
		 *
		 * @return	this.courses using a certain string format
		 */
		public String getCourses()
		{
			// Variables.
			StringBuilder ret = new StringBuilder();



			// Processing the output.
			Collections.sort(this.courses, (c1, c2) -> c1.getCourseID().compareTo(c2.getCourseID()));

			for(var c : this.courses)
				ret.append(c.getCourseName() + "\t" + c.getNumberOfTries() + "\t" + c.isPassed() + "\n");




			// Returning results.
			return ret.toString();



		};

		/**
		 * Querying this student's courses.
		 *
		 * @param	parameter	A parameter in order make this method compilable.
		 * @return	this.courses as ArrayList
		 *
		 * @since	V1.1.0-en_GB // (20200513/20200513)
		 */
		public ArrayList<Course> getCourses(boolean parameter) {return this.courses;};



		/**
		 * Changing this student's courses.
		 *
		 * @param	data	This student's new collection of courses.
		 */
		public void setCourses(ArrayList<Course> data)
		{
			// Processing the field transaction.
			this.courses = data;



			// Quitting the method properly.
			return;



		};



	// Field forename.
		/**
		 * Querying this student's forename.
		 *
		 * @return	this.forename
		 */
		public String getForename()	{return this.forename;};



		/**
		 * Changing this student's forename.
		 *
		 * @param	data	This student's new forename.
		 */
		public void setForename(String data)
		{
			// Processing the field transaction.
			this.forename = data;



			// Quitting the method properly.
			return;



		};



	// Field matriculationNumber.
		/**
		 * Querying this student's matriculation number.
		 *
		 * @return	this.matriculationNumber
		 */
		public Integer getMatriculationNumber()	{return this.matriculationNumber;};



		/**
		 * Changing this student's matriculationNumber.
		 *
		 * @param	data	This student's new matriculation number.
		 */
		public void setMatriculationNumber(Integer data)
		{
			// Processing the field transaction.
			this.matriculationNumber = data;



			// Quitting the method properly.
			return;



		};



	// Field surname.
		/**
		 * Querying this student's surname.
		 *
		 * @return	this.forename
		 */
		public String getSurname()	{return this.surname;};



		/**
		 * Changing this student's surname.
		 *
		 * @param	data	This student's new surname.
		 */
		public void setSurname(String data)
		{
			// Processing the field transaction.
			this.surname = data;



			// Quitting the method properly.
			return;



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
