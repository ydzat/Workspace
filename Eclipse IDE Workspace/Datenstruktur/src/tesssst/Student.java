/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| Student.java:                                                                |
|      A simple class in order to describe a student.                          |
|                                                                              |
| V1.0.2-en_GB // (20200510/20200510)                                          |
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

package tesssst;


//import g13.FelixVogel591520;
import java.util.ArrayList;
import java.util.Collections;


public class Student
{


	private ArrayList<Course> courses	= new ArrayList<>();
	private String forename				= "John";
	private Integer matriculationNumber	= 0;
	private String surname				= "Doe";
	
	public Student()	{return;};

	public Student(String forename, String surname){
		this.forename	= forename;
		this.surname	= surname;
		return;
	};


	public Student(String forename, String surname, Integer matriculationNumber){
		this.forename			= forename;
		this.matriculationNumber= matriculationNumber;
		this.surname			= surname;
		return;
	};


	public Student(Student student){
		// Processing the copying.
		this.forename			= new String(student.forename);
		this.matriculationNumber= new Integer(student.matriculationNumber);
		this.surname			= new String(student.surname);

		for(var c : student.courses)
			this.courses.add(new Course(c));
		return;
	};


	

		public String getCourses()
		{
			// Variables.
			StringBuilder ret = new StringBuilder();



			// Processing the output.
			Collections.sort(this.courses, (c1, c2) -> c1.getCourseID().compareTo(c2.getCourseID()));

			for(var c : this.courses)
				ret.append(c.getCourseName() + "\t" + c.getNumberOfTries() + "\t" + c.isPassed() + "\n");


			return ret.toString();



		};


		public void setCourses(ArrayList<Course> data)
		{

			this.courses = data;

			return;



		};



	


	

		public String getForename()	{return this.forename;};

		public void setForename(String data)
		{

			this.forename = data;

			return;



		};



	


	

		public Integer getMatriculationNumber()	{return this.matriculationNumber;};


		public void setMatriculationNumber(Integer data)
		{
			this.matriculationNumber = data;

			return;

		};



	


	

		public String getSurname()	{return this.surname;};

		public void setSurname(String data)
		{
			this.surname = data;

			return;



		};



	

};

