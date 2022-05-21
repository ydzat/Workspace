/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| Course.java:                                                                 |
|      Class for the courses a student is able to take.                        |
|                                                                              |
| V1.0.3-en_GB // (20200510/20200510)                                          |
| (C) 2020 Felix Vogel (591520), Kevin Matthes (590411)                        |
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
| V1.0.0-en_GB // (20200507/20200507):                                         |
| + made it work as it should and not only as it was coded                     |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.0.1-en_GB // (20200507/20200509)                                          |
| + adding JavaDocs                                                            |
| ! adjusting the code to match the CIG                                        |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.0.2-en_GB // (20200510/20200510)                                          |
| ! minor adjustments                                                          |
|                                                                              |
|                                                                              |
|                                                                              |
|==============================================================================|
|                                                                              |
|                                                                              |
|                                                                              |
| V1.0.3-en_GB // (20200510/20200510)                                          |
| + a copy constructor                                                         |
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

/*SECTION**********************************************************************\
|                                                                              |
| Package                                                                      |
|                                                                              |
\******************************************************************************/

package tesssst;



/*SECTION**********************************************************************\
|                                                                              |
| Class definition (I)                                                         |
|                                                                              |
\******************************************************************************/

/**
 * Class for the Course a student is able to take
 *
 * @author	Felix Vogel
 * @author	Kevin Matthes
 * @version	V1.0.2-en_GB // (20200510/20200510)
 */
public class Course
{



/*SECTION**********************************************************************\
|                                                                              |
| Instance variables                                                           |
|                                                                              |
\******************************************************************************/

	/** The ID of the course. */
	private String courseID		= "";

	/** The name of the course. */
	private String courseName	= "";

	/** Number of tries for the course. */
	private int numberOfTries	= 0;

	/** Passed or not? */
	private boolean passed		= false;



/*SECTION**********************************************************************\
|                                                                              |
| Constructors                                                                 |
|                                                                              |
\******************************************************************************/

	/**
	 * Creating a new Course from their courseID and courseName.
	 *
	 * @param	courseID	The new course's courseID.
	 * @param	courseName	The new course's courseName.
	 */
	public Course(String courseID, String courseName)
	{
		// Configurating this course.
		this.courseID	= courseID;
		this.courseName	= courseName;



		// Quitting the constructor properly.
		return;



	};



	/**
	 * This is the Copy-Constructor.
	 *
	 * @param	courseToCopy	The course to copy
	 * @since	V1.0.3-en_GB // (20200510 / 20200510)
	 */
	public Course(Course courseToCopy)
	{
		// Copying the attributes
		this.courseID		= new String(courseToCopy.courseID);
		this.courseName		= new String(courseToCopy.courseName);
		this.numberOfTries	= courseToCopy.numberOfTries;
		this.passed			= courseToCopy.passed;



		// Quitting the constructor properly.
		return;



	};



/*SECTION**********************************************************************\
|                                                                              |
| Getters and setters                                                          |
|                                                                              |
\******************************************************************************/

	/**
	 * Returning the number of tries for the course
	 *
	 *@return 	number of tries for the course
	 */
	public int getNumberOfTries()	{return numberOfTries;};



	/**
	 * Returning the name of the course
	 *
	 *@return	number of tries for the course
	 */
	public String getCourseName()	{return courseName;};



	/**
	 * Returning the ID of the course
	 *
	 *@return	ID of the course
	 */
	public String getCourseID()		{return courseID;};



	/**
	 * Has the student succesfully passed the course?
	 *
	 *@return 	passed variable
	 */
	public boolean isPassed()		{return passed;};



/*SECTION**********************************************************************\
|                                                                              |
| Instance methods                                                             |
|                                                                              |
\******************************************************************************/

	/**
	 * Sets passed and increases numberOfTries
	 * @param 	b	passed or not?
	 */
	public void pass(boolean b)
	{
		// Processing the counter increment.
		if(!this.passed)
		{
			passed = b;
			numberOfTries++;



		};



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
