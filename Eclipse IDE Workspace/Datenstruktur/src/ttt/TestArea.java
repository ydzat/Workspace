/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| TestArea.java:                                                               |
|      Test Area.                                                              |
|                                                                              |
| V1.0.0-en_GB // (20200513/20200513)                                          |
| (C) 2020 Felix Vogel (591520)                                                |
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
| V1.0.0-en_GB // (20200513/20200513):                                         |
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
 * Test Area.
 *
 * @author	Felix Vogel
 * @version	V1.0.0-en_GB // (20200513/20200513)
 */
public class TestArea
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
		for(int i = 0; i <= students.size() && !found; i++) 
		{
			
			
			
			try 
			{
				
				
				
				//find the next possible open matriculation number
				if(i != this.students.get(i).getMatriculationNumber() - 1) 
				{				
					//setting ret to matriculation number
					ret = ++ i;


				
					Student student = new Student(firstName, lastName, ret);
					students.add(student);
					found = true;
					
					

				};
				
				
				
			} 
			
			
			
			catch (IndexOutOfBoundsException e) 
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

	
	
	/** 
	 * A method to find students.
	 *
	 * @return If the search is successful, it returns the student data (name, course), otherwise "null"
	 */
	public String find(Integer matriculationNumber)
	{
		//Variables
		int low = 0;
		int high = students.size();
		int middle = 0;
		
		//Confirm whether the matriculation number is "registered"
		if(matriculationNumber < students.get(low).getMatriculationNumber() || matriculationNumber > students.get(low).getMatriculationNumber() || low>high) {
			//Find failed
			return "null";
		}
		
		//Binary search
		while(low <=high) {
			middle = (low + high) / 2;
			if(students.get(middle).getMatriculationNumber() > matriculationNumber) {
				high = middle - 1;
			}
			else if(students.get(middle).getMatriculationNumber() < matriculationNumber) {
				low = middle + 1;
			}
			else {
				//Find success
				StringBuilder ret = new StringBuilder();

				ret.append(students.get(middle).getSurname() + "\t" + students.get(middle).getForename() + "\t" + students.get(middle).getCourses());
				
				return ret.toString();
				
			}
		}
		
		//Find failed
		return "null";
		
		
	};
	
	
	
	public String takeExam(Integer matriculationNumber, String courseID, Boolean passed)
		{return null;};
		
		
	
/*SECTION**********************************************************************\
|                                                                              |
| Class methods                                                                |
|                                                                              |
\******************************************************************************/

	/**
	 * The main method.
	 * 
	 * @param args
	*/
	public static void main(String[] args)
	{
		
		TestArea testArea = new TestArea();
		
		
		//print out empty database
		System.out.println(testArea.dataBase());
		
		
		//matriculationNumber = 1?
		Integer matricJon = testArea.matriculate("Jon", "Doe");
		 //matriculationNumber = 2?
		Integer matricMax = testArea.matriculate("Max", "Mustermann");
		//print out database
		System.out.println(testArea.dataBase());
		
		
		//Jon Doe passes a course
		testArea.takeExam(matricJon, "0", true);
		
		
		//print out Jon Doe's data
		System.out.println(testArea.find(matricJon));
		//print out Max Mustermann's data
		System.out.println(testArea.find(matricMax));
		
		
		
		//print out database
		System.out.println(testArea.dataBase());
		
		
		
		//Max Mustermann fails the course three times
		for (int i = 0; i < 3; i++)
			{testArea.takeExam(matricMax, "0", false);};
			
			
			
		//print out database
		System.out.println(testArea.dataBase());
		
		
		
		//Jon Doe leaves the university
		testArea.deregister(matricJon);
		
		
		
		//print out database
		System.out.println(testArea.dataBase());
		
		
		
		return;
		
		
		
	};


	
};



/*GENERAL INFORMATION**********************************************************\
|                                                                              |
| EOF                                                                          |
|                                                                              |
\******************************************************************************/