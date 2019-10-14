/*ENSC 251 - LAB1
*Authors: Saba Khangholi and Sharanjit Virdi
*September 25, 2019
*This is the main.cpp, which contains our driver code and manipulates the class objects
*The main function uses Object-Oriented Programming to read inputs from a Domestic Student file
*and an International Student file and outputs them.
*/

//Include all the necessary libraries
#include <iostream> //cin and cout
#include <fstream> //file processing
#include <sstream> //formatted string processing
#include <cstdlib> //atof and atoi
#include "student.hpp"//Include the header file

using namespace std;

int main() {

	/*========================================DOMESTIC STUDENTS=====================================*/
	//Read the domestic-stu.txt file and exit if failed
	string line;
	string line2;
	ifstream first_domesticFile("domestic-stu.txt");
	if (!first_domesticFile.is_open()) {
		cout << "Unable to open file domestic-stu.txt" << endl << endl;
		return -1;
	}

	int dom_num_lines = 0;
	while (getline(first_domesticFile, line2)) {
		dom_num_lines++;
	}
	cout << dom_num_lines << endl;

	//close the domestic student file
	first_domesticFile.close();

	////Read the first line of domestic-stu.txt, which specifies
	////the file format. And then print it out to the screen
	//getline(first_domesticFile, line);
	//cout << "File format: " << line << endl << endl;

	ifstream domesticFile("domestic-stu.txt");
	if (!domesticFile.is_open()) {
		cout << "Unable to open file domestic-stu.txt" << endl << endl;
		return -1;
	}


	//Read the first line of domestic-stu.txt, which specifies
	//the file format. And then print it out to the screen
	getline(domesticFile, line);
	cout << "File format: " << line << endl << endl;

	/*Keep reading the rest of the lines in domestic-stu.txt.
	 *Here we read each data separated
	 *by a comma, and then print it out to the screen.
	 *The read data to initialize our DomesticStudent object. Then
	 *get and set functions can be use to manipulate our object, and
	 *print the object content to the screen
	 */
	int stu_count = 1; //Counter that keeps track of the number of domestic students
	int student_number = 20200001; //Counter that keeps track of the student number that have been assigned to all students
									//(domestic and international)

	DomesticStudent dom_student[100] = {};
	DomesticStudent rejeceted_dom_student[100];//Assume worse case scenerio that all students are rejected

	string temp_line;

	//for (int i = 1; i < dom_num_lines-1; i++)
	for (int i = 0; i <= dom_num_lines - 2; i++)
		//while (getline(domesticFile, line))
	{
		//for (int i = 1; i < 3; i++)
			/*process each line, get each field separated by a comma.
			 *We use istringstream to handle it.
			 *Note in this example code here, we assume the file format
			 *is perfect and do NOT handle error cases. Error and exception handling of
			 *file format to be dealt in later labs
			 */

			 //Check through the student numbers if accepting another
			 //student would exceed our limit of student that can be admitted (less than 10000)
		if (student_number >= 202010000)
		{
			cout << "Sorry! Only less that 100000 students are admitted\n" << endl;
			exit(1);
		};
		//cout << student_number << endl;
		//istringstream ss(line); //Input stream class to operate on strings
		//domesticFile.ignore();
		getline(domesticFile, line);
		istringstream ss(line);
		//getline(domesticFile, line);
		//Declare variables used in the main function
		string firstName, lastName, province, s_cgpa, s_researchScore;
		float cgpa;
		int researchScore;

		//get firstName separated by comma
		getline(ss, firstName, ',');

		//get lastName separated by comma
		getline(ss, lastName, ',');

		//get province separated by comma
		getline(ss, province, ',');

		//get cpga separated by comma, and convert string to float using atof()
		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());

		//get researchScore separated by comma, and convert it to int using atoi()
		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());


		//mutator functions
		dom_student[i].setfirstName(firstName);
		dom_student[i].setlastName(lastName);
		dom_student[i].setcgpa(cgpa);
		dom_student[i].setresearchScore(researchScore);
		dom_student[i].setstudentID(student_number);
		dom_student[i].setprovince(province);


		stu_count++;
		student_number++;

		cout << dom_student[i] << endl;
		//cout << domestic_array[i];

	};


	for (int i = 0; i < 100; i++)
	{
		cout << dom_student[i] << endl;
		cout << "hello again" << endl;

	};

	string ans;
	cout << "We are now going to sort the arrays." << endl;
	cout << "Please enter 'd' or 'D' if you would like to sort the domestic student array" 
		<< " , enter 'i' or 'I' if you would like to sort the international student array."
		<< " and enter 'o' or 'O' if you would like an overall sort. "
		<< " You have 3 tries to enter a valid character "<< endl;
	cin >> ans;

	int tries=0;
	while ((ans != "d") || (ans != "D") || (ans != "i") || (ans != "I") || (ans != "o") || (ans != "O"))
	{
		
		
		if (tries == 2)
		{
			cout << "Sorry! You exceeded the maximum number of tries. Good luck next time" << endl;
			exit(1);
		}
		else if ((ans == "d") || (ans == "D"))
		{
			//cout << "y"<< endl;
			int tries2 = 0;
			string ans2;
			cout << "Please enter 'c' or 'C' if you would like to sort the domestic student array in terms of cpga"
				<< ", 'r' or 'R' to sort it in terms of research score" 
				<< ", 'f' or 'F' to sort it in terms of first name"
				<< ", 'l' or 'L' to sort it in terms of last name"
				<< " You have 3 tries to enter a valid character " << endl;
			cin >> ans2;

			while ((ans2 != "c") || (ans2 != "C") || (ans2 != "r") || (ans2 != "R") || (ans2 != "f") || (ans2 != "F") || (ans2 != "l") || (ans2 != "L"))
			{
				if (tries2 == 2)
				{
					cout << "Sorry! You exceeded the maximum number of tries. Good luck next time" << endl;
					exit(1);
				}
				else if ((ans2 == "c") || (ans2 == "C"))
				{
					sort_dom_CGPA(dom_student);
					cout << "hello!" << endl;
					for (int i = 0; i < 100; i++)
					{
						cout << dom_student[i] << endl;
						cout << "hello again"<< endl;
					};
					break;
				}
				else if ((ans2 == "r") || (ans2 == "R"))
				{
					sort_dom_ResearchScore(dom_student);
					break;
				}
				else if ((ans2 == "f") || (ans2 == "F"))
				{
					sort_dom_FirstName(dom_student);
					break;
				}
				else if ((ans2 == "l") || (ans2 == "L"))
				{
					sort_dom_LastName(dom_student);
					break;
				}

				cout << "Please enter 'c' or 'C' if you would like to sort the domestic student array in terms of cpga"
					<< ", 'r' or 'R' to sort it in terms of research score"
					<< ", 'f' or 'F' to sort it in terms of first name"
					<< ", 'l' or 'L' to sort it in terms of last name"
					<< " You have 3 tries to enter a valid character " << endl;
				cin >> ans2;

				tries2++;

			};


			
		}
		else if ((ans == "i") || (ans == "I"))
		{
			//cout << "n"<< endl;
					//cout << "y"<< endl;
			int tries2 = 0;
			string ans2;
			cout << "Please enter 'c' or 'C' if you would like to sort the international student array in terms of cpga"
				<< ", 'r' or 'R' to sort it in terms of research score"
				<< ", 'f' or 'F' to sort it in terms of first name"
				<< ", 'l' or 'L' to sort it in terms of last name"
				<< " You have 3 tries to enter a valid character " << endl;
			cin >> ans2;

			while ((ans2 != "c") || (ans2 != "C") || (ans2 != "r") || (ans2 != "R") || (ans2 != "f") || (ans2 != "F") || (ans2 != "l") || (ans2 != "L"))
			{
				/*if (tries == 2)
				{
					cout << "Sorry! You exceeded the maximum number of tries. Good luck next time" << endl;
					exit(1);
				}
				else if ((ans2 == "c") || (ans2 == "C"))
				{
					sort_int_CGPA(int_student);
					cout << "hello!" << endl;
					break;
				}
				else if ((ans2 == "r") || (ans2 == "R"))
				{
					sort_int_ResearchScore(int_student);
					break;
				}
				else if ((ans2 == "f") || (ans2 == "F"))
				{
					sort_int_FirstName(int_student);
					break;
				}
				else if ((ans2 == "l") || (ans2 == "L"))
				{
					sort_int_LastName(int_student);
					break;
				}*/

				cout << "Please enter 'c' or 'C' if you would like to sort the international student array in terms of cpga"
					<< ", 'r' or 'R' to sort it in terms of research score"
					<< ", 'f' or 'F' to sort it in terms of first name"
					<< ", 'l' or 'L' to sort it in terms of last name"
					<< " You have 3 tries to enter a valid character " << endl;
				cin >> ans2;

				tries2++;

			};
		}
		else if ((ans == "0") || (ans == "O"))
		{
			cout << "1";
		}

		cout << "Wrong input. Please try again. " << endl;
		cout << "Please enter 'd' or 'D' if you would like to sort the domestic student array"
			<< " and enter 'i' or 'I' if you would like to sort the international student array."
			<< " You have 3 tries to enter a valid character " << endl;
		cin >> ans;

		tries++;
	};

	domesticFile.close();

	/*========================================END DOMESTIC STUDENTS=====================================*/


	/*========================================INTERNATIONAL STUDENTS=====================================*/

	//Read the international-stu.txt file and exit if failed
	string newline2;

	ifstream first_internationalFile("international-stu.txt");
	if (!first_internationalFile.is_open()) {
		cout << "Unable to open file international-stu.txt" << endl << endl;
		return -1;
	}

	int int_num_lines = 0;
	while (getline(first_internationalFile, newline2)) {
		int_num_lines++;
	}
	//cout << int_num_lines << endl;

	//close the domestic student file
	first_domesticFile.close();
	//Read the international-stu.txt file and exit if failed


	string newline;
	ifstream internationalFile("international-stu.txt");
	if (!internationalFile.is_open()) {
		cout << "Unable to open file international-stu.txt" << endl;
		return -1;
	}
	//Read the first line of international-stu.txt, which specifies
	//the file format. And then print it out to the screen
	getline(internationalFile, newline);
	cout << endl << "File format: " << newline << endl << endl;

	/*Keep reading the rest of the lines in international-stu.txt.
	 *Here we read each data separated
	 *by a comma, and then print it out to the screen.
	 *The read data to initialize our InternationalStudent object. Then
	 *get and set functions can be use to manipulate our object, and
	 *print the object content to the screen
	 */

	int stu_count_int = 1;       //Counter to keep track of the number of international students     
	InternationalStudent int_student[100] = {};
	InternationalStudent rejeceted_int_student[100];//Assume worse case scenerio that all students are rejected


	//for (int i = 1; i < dom_num_lines-1; i++)
	for (int i = 0; i <= int_num_lines - 2; i++)
	{
	//while (getline(internationalFile, newline)) {
		/*process each line, get each field separated by a comma.
		 *We use istringstream to handle it.
		 *Note in this example code here, we assume the file format
		 *is perfect and do NOT handle error cases. Error and exception handling of
		 *file format to be dealt in later labs
		 */


		 //Check through the student numbers if accepting another
		 //student would exceed our limit of student that can be admitted (less than 10000)
		if (student_number >= 202010000)
		{
			cout << "Sorry! Only less that 100000 students\n" << endl;
			exit(1);
		};

		getline(internationalFile, newline);
		istringstream ss(newline);

		string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
		float cgpa;
		int reading;
		int listening;
		int speaking;
		int writing;
		int researchScore;

		//get firstName separated by comma
		getline(ss, firstName, ',');

		//get lastName separated by comma
		getline(ss, lastName, ',');

		//get country separated by comma
		getline(ss, country, ',');

		//get cpga separated by comma, and convert string to float
		getline(ss, s_cgpa, ',');
		cgpa = atof(s_cgpa.c_str());

		//get researchScore separated by comma, and convert it to int
		getline(ss, s_researchScore, ',');
		researchScore = atoi(s_researchScore.c_str());

		//get reading score separated by comma, and convert it to int
		getline(ss, s_reading, ',');
		reading = atoi(s_reading.c_str());

		//get reading score separated by comma, and convert it to int
		getline(ss, s_listening, ',');
		listening = atoi(s_listening.c_str());

		//get reading score separated by comma, and convert it to int
		getline(ss, s_speaking, ',');
		speaking = atoi(s_speaking.c_str());

		//get reading score separated by comma, and convert it to int
		getline(ss, s_writing, ',');
		writing = atoi(s_writing.c_str());

		//Call the constructors to initialize all the inputs from the file to the corresponding member variables
		ToeflScore current_TOEFL(reading, listening, speaking, writing);
		//Student student_person2(firstName, lastName, cgpa, researchScore, student_number);
		//InternationalStudent int_student(country, current_TOEFL);

		//mutator functions
		int_student[i].setfirstName(firstName);
		int_student[i].setlastName(lastName);
		int_student[i].setcgpa(cgpa);
		int_student[i].setresearchScore(researchScore);
		int_student[i].setstudentID(stu_count_int);
		int_student[i].setcountry(country);
		
		current_TOEFL.setreading(reading);
		current_TOEFL.setlistening(listening);
		current_TOEFL.setspeaking(speaking);
		current_TOEFL.setwriting(writing);

		//print the student info to the screen
		//cout << "International student # " << stu_count_int << " with student number "
		//	<< student_person2.getstudentID() << " : " << student_person2.getfirstName() << " "
		//	<< student_person2.getlastName() << " from " << int_student.getcountry() << " country has cgpa of "
		//	<< student_person2.getcgpa() << ", research score of " << student_person2.getresearchScore()
		//	<< ", a reading score of " << current_TOEFL.getreading() << ", a listening score of "
		//	<< current_TOEFL.getlistening() << ", a speaking score of "
		//	<< current_TOEFL.getspeaking() << ", and a writing score of " << current_TOEFL.getwriting()
		//	<< " which sums up to a total TOEFL Score of " << current_TOEFL.addTOEFLScore() << "." << endl << endl;

		stu_count_int++;
		student_number++;
	}

	//close the international student file file
	internationalFile.close();
	/*========================================END INTERNATIONAL STUDENTS=====================================*/
	return 0;

}//new

//SABA=============================================
/*if (select == 'o' || select == 'O')
	{
		sort_dom_CGPA(dom_student);
		if (compareCGPA_dom(dom[i], dom[i+1]) == 0)
		{
			sort_dom_ResearchScore(dom_student);
			if (compareResearchScore_dom(dom[i], dom[i+1]) == 0)
			{
				sort_dom_FirstName(dom_student);
				if ((compareFirstName_dom(dom[i], dom[i+1])) == 0)
				{
					sort_dom_LastName(dom_student);
				}
			}
		}
		sort_int_CGPA(int_student);
		if (compareCGPA_int(int1, int2) == 0)
		{
			sort_int_ResearchScore(int_student);
			if (compareResearchScore_int(int_s[i], int_s[i+1] == 0)
			{
				sort_dom_FirstName(int_student);
				if (compareFirstName_int(int_s[i], int_s[i+1]) == 0)
				{
					sort_dom_LastName(int_student);
				}
			}
		}
	}*/


//SABA==============================================================
/*if (select == 'o' || select == 'O')
	{
		sort_dom_CGPA(dom_student);
		if (compareCGPA_dom(dom1, dom2) == 0)
		{
			sort_dom_ResearchScore(dom_student);
			if (compareResearchScore_dom(dom1, dom2) == 0)
			{
				sort_dom_FirstName(dom_student);
				if ((compareFirstName_dom(dom1, dom2)) == 0)
				{
					sort_dom_LastName(dom_student);
				}
			}
		}
		sort_int_CGPA(int_student);
		if (compareCGPA_int(int1, int2) == 0)
		{
			sort_int_ResearchScore(int_student);
			if (compareResearchScore_int(int1, int2) == 0)
			{
				sort_dom_FirstName(int_student);
				if (compareFirstName_int(int1, int2) == 0)
				{
					sort_dom_LastName(int_student);
				}
			}
		}
	}*/
/*if (select == 'o' || select == 'O')
	{
		sort_dom_CGPA(dom_student);
		if (compareCGPA_dom(dom1, dom2) == 0)
		{
			sort_dom_ResearchScore(dom_student);
			if (compareResearchScore_dom(dom1, dom2) == 0)
			{
				sort_dom_FirstName(dom_student);
				if ((compareFirstName_dom(dom1, dom2)) == 0)
				{
					sort_dom_LastName(dom_student);
				}
			}
		}
		sort_int_CGPA(int_student);
		if (compareCGPA_int(int1, int2) == 0)
		{
			sort_int_ResearchScore(int_student);
			if (compareResearchScore_int(int1, int2) == 0)
			{
				sort_dom_FirstName(int_student);
				if (compareFirstName_int(int1, int2) == 0)
				{
					sort_dom_LastName(int_student);
				}
			}
		}
	}*/


//SABA=========================================================

	//for (int i = 1; i<dom_num_lines; i++)
	//{
	//	cout << dom_student[i];
	//};


	////delete [] dom_array;
	////dom_array = NULL;


	//================================================
	//for (int i=0; i < dom_num_lines; i++)
	//{
	//	cout << dom_array[i];
	//};


	//while (getline(domesticFile, line)) {
	//	/*process each line, get each field separated by a comma.
	//	 *We use istringstream to handle it.
	//	 *Note in this example code here, we assume the file format
	//	 *is perfect and do NOT handle error cases. Error and exception handling of
	//	 *file format to be dealt in later labs
	//	 */

	//	 //Check through the student numbers if accepting another
	//	 //student would exceed our limit of student that can be admitted (less than 10000)
	//	if (student_number >= 202010000)
	//	{
	//		cout << "Sorry! Only less that 100000 students are admitted\n" << endl;
	//		exit(1);
	//	};


	//	istringstream ss(line); //Input stream class to operate on strings

	//	//Declare variables used in the main function
	//	string firstName, lastName, province, s_cgpa, s_researchScore;
	//	float cgpa;
	//	int researchScore;

	//	//get firstName separated by comma
	//	getline(ss, firstName, ',');

	//	//get lastName separated by comma
	//	getline(ss, lastName, ',');

	//	//get province separated by comma
	//	getline(ss, province, ',');

	//	//get cpga separated by comma, and convert string to float using atof()
	//	getline(ss, s_cgpa, ',');
	//	cgpa = atof(s_cgpa.c_str());

	//	//get researchScore separated by comma, and convert it to int using atoi()
	//	getline(ss, s_researchScore, ',');
	//	researchScore = atoi(s_researchScore.c_str());

	//	//Call a constructor to initialize all the inputs from the file to the corresponding member variables
	//	Student student_person(firstName, lastName, cgpa, researchScore, student_number);
	//	DomesticStudent dom_student(province);

	//	//mutator functions
	//	student_person.setfirstName( firstName);
	//	student_person.setlastName( lastName);
	//	student_person.setcgpa( cgpa);
	//	student_person.setresearchScore( researchScore);
	//	student_person.setstudentID(stu_count);
	//	dom_student.setprovince(province);



	//	////=========================================
	//	//get and set funtions to be used later to 
	//	//student_person.setcgpa(cgpa);
	//	//student_person.setresearchScore(researchScore);
	//	////========================================


	//	//print the student info to the screen using the accessor functions 
	//	cout << "Domestic student # " << stu_count << " with student number " << student_person.getstudentID()
	//		<< " : " << student_person.getfirstName() << " "
	//		<< student_person.getlastName() << " from " << dom_student.getprovince() << " province has cgpa of "
	//		<< student_person.getcgpa() << ", and research score of " << student_person.getresearchScore() << endl << endl;

	//	//Counter to keep track of domestic students
	//	stu_count++;
	//	student_number++;
	//}

	//close the domestic student file



		/*//mutator functions
		dom_student.setfirstName(firstName);
		dom_student.setlastName(lastName);
		dom_student.setcgpa(cgpa);
		dom_student.setresearchScore(researchScore);
		dom_student.setstudentID(student_number);
		dom_student.setprovince(province);*/


		//dom_array[i] = dom_student;
		//domestic_array[i] = dom_student;

		//print the student info to the screen using the accessor functions 
		//cout << "Domestic student # " << stu_count << " with student number " << dom_student.getstudentID()
		//	<< " : " << dom_student.getfirstName() << " "
		//	<< dom_student.getlastName() << " from " << dom_student.getprovince() << " province has cgpa of "
		//	<< dom_student.getcgpa() << ", and research score of " << dom_student.getresearchScore() << endl << endl;

		//cout << dom_student[i].getstudentID();

		//Counter to keep track of domestic students]





///Saba sortted fuctniona
/*void sort_dom_firstName(DomesticStudent* Dom_Stu_Array)
{
	int arr_len = sizeof(Dom_Stu_Array);
	
	int result;
	
	for (int i = 0; i < (arr_len - 1); i++)
	{
		for (int j = 0; j < (arr_len - 1); j++)
		{
			result = dom_comparefirstName(Dom_Stu_Array[j], Dom_Stu_Array[j + 1]);
			if (result == -1)
			{
				swap_int_student(&Dom_Stu_Array[j], &Dom_Stu_Array[j + 1]);
			}
		};
	};
};

void sort_int_firstName(InternationalStudent* Int_Stu_Array)
{
	int arr_len = sizeof(Int_Stu_Array);

	int result;

	for (int i = 0; i < (arr_len - 1); i++)
	{
		for (int j = 0; j < (arr_len - 1); j++)
		{
			result = int_comparefirstName(Int_Stu_Array[j], Int_Stu_Array[j + 1]);
			if (result == -1)
			{
				swap_int_student(&Int_Stu_Array[j], &Int_Stu_Array[j + 1]);
			}
		};
	};
};

void sort_dom_lastName(DomesticStudent* Dom_Stu_Array)
{
	int arr_len = sizeof(Dom_Stu_Array);

	int result;

	for (int i = 0; i < (arr_len - 1); i++)
	{
		for (int j = 0; j < (arr_len - 1); j++)
		{
			result = dom_comparelastName(Dom_Stu_Array[j], Dom_Stu_Array[j + 1]);
			if (result == -1)
			{
				swap_int_student(&Dom_Stu_Array[j], &Dom_Stu_Array[j + 1]);
			}
		};
	};
};

void sort_int_lastName(InternationalStudent* Int_Stu_Array)
{
	int arr_len = sizeof(Int_Stu_Array);

	int result;

	for (int i = 0; i < (arr_len - 1); i++)
	{
		for (int j = 0; j < (arr_len - 1); j++)
		{
			result = int_comparelastName(Int_Stu_Array[j], Int_Stu_Array[j + 1]);
			if (result == -1)
			{
				swap_int_student(&Int_Stu_Array[j], &Int_Stu_Array[j + 1]);
			}
		};
	};
};*/\


/*char select;
	cout << "Please select sorting method of Student applicants: Overall [o], Domestic Students [d], International Students [i]";
	cin >> select;
	cout << "You selected" << select;

	if (select == 'o' || select == 'O')
	{
		sort_dom_CGPA(dom_student);
		sort_int_CGPA(int_student);
	}*/


	////Call a constructor to initialize all the inputs from the file to the corresponding member variables
	//Student student_person(firstName, lastName, cgpa, researchScore, student_number);
	//DomesticStudent dom_student( province);

	////mutator functions
	//student_person.setfirstName(firstName);
	//student_person.setlastName(lastName);
	//student_person.setcgpa(cgpa);
	//student_person.setresearchScore(researchScore);
	//student_person.setstudentID(stu_count);
	//dom_student.setprovince(province);

	////dom_array[i] = dom_student;

	////print the student info to the screen using the accessor functions 
	//cout << "Domestic student # " << stu_count << " with student number " << student_person.getstudentID()
	//	<< " : " << student_person.getfirstName() << " "
	//	<< student_person.getlastName() << " from " << dom_student.getprovince() << " province has cgpa of "
	//	<< student_person.getcgpa() << ", and research score of " << student_person.getresearchScore() << endl << endl;



	//Student student_person(firstName, lastName, cgpa, researchScore, student_number);
	//DomesticStudent dom_student(firstName, lastName, cgpa, researchScore, student_number, province);
	//DomesticStudent dom_student;


	//if ((dom_student.checkcgpa() == false) || (dom_student->checkresearchScore() == false))
	//{
	//	cout << "NO!" << endl;
	//	rejeceted_dom_student[i].setfirstName(firstName);
	//	rejeceted_dom_student[i].setlastName(lastName);
	//	rejeceted_dom_student[i].setcgpa(cgpa);
	//	rejeceted_dom_student[i].setresearchScore(researchScore);
	//	rejeceted_dom_student[i].setstudentID(student_number);
	//	rejeceted_dom_student[i].setprovince(province);
	//}
	//else
	//{
	//	//mutator functions
	//	dom_student[i].setfirstName(firstName);
	//	dom_student[i].setlastName(lastName);
	//	dom_student[i].setcgpa(cgpa);
	//	dom_student[i].setresearchScore(researchScore);
	//	dom_student[i].setstudentID(student_number);
	//	dom_student[i].setprovince(province);
	//};

		//DomesticStudent* dom_array;
	//dom_array = new DomesticStudent[dom_num_lines + 1];

	//DomesticStudent domestic_array[100];

//
///*
//	/*
//	//while (getline(internationalFile, newline)) {
//		/*process each line, get each field separated by a comma.
//		 *We use istringstream to handle it.
//		 *Note in this example code here, we assume the file format
//		 *is perfect and do NOT handle error cases. Error and exception handling of
//		 *file format to be dealt in later labs
//		 */
//
//
//		 //Check through the student numbers if accepting another
//		 //student would exceed our limit of student that can be admitted (less than 10000)
//	if (student_number >= 202010000)
//	{
//		cout << "Sorry! Only less that 100000 students\n" << endl;
//		exit(1);
//	};
//
//getline(internationalFile, newline);
//istringstream ss(newline);
//
//string firstName, lastName, country, s_cgpa, s_researchScore, s_reading, s_listening, s_speaking, s_writing;
//float cgpa;
//int reading;
//int listening;
//int speaking;
//int writing;
//int researchScore;
//
////get firstName separated by comma
//getline(ss, firstName, ',');
//
////get lastName separated by comma
//getline(ss, lastName, ',');
//
////get country separated by comma
//getline(ss, country, ',');
//
////get cpga separated by comma, and convert string to float
//getline(ss, s_cgpa, ',');
//cgpa = atof(s_cgpa.c_str());
//
////get researchScore separated by comma, and convert it to int
//getline(ss, s_researchScore, ',');
//researchScore = atoi(s_researchScore.c_str());
//
////get reading score separated by comma, and convert it to int
//getline(ss, s_reading, ',');
//reading = atoi(s_reading.c_str());
//
////get reading score separated by comma, and convert it to int
//getline(ss, s_listening, ',');
//listening = atoi(s_listening.c_str());
//
////get reading score separated by comma, and convert it to int
//getline(ss, s_speaking, ',');
//speaking = atoi(s_speaking.c_str());
//
////get reading score separated by comma, and convert it to int
//getline(ss, s_writing, ',');
//writing = atoi(s_writing.c_str());
//
////Call the constructors to initialize all the inputs from the file to the corresponding member variables
//ToeflScore current_TOEFL(reading, listening, speaking, writing);
////Student student_person2(firstName, lastName, cgpa, researchScore, student_number);
////InternationalStudent int_student(country, current_TOEFL);
//
////mutator functions
//int_student[i].setfirstName(firstName);
//int_student[i].setlastName(lastName);
//int_student[i].setcgpa(cgpa);
//int_student[i].setresearchScore(researchScore);
//int_student[i].setstudentID(stu_count_int);
//int_student[i].setcountry(country);
//
//current_TOEFL.setreading(reading);
//current_TOEFL.setlistening(listening);
//current_TOEFL.setspeaking(speaking);
//current_TOEFL.setwriting(writing);
//
////print the student info to the screen
////cout << "International student # " << stu_count_int << " with student number "
////	<< student_person2.getstudentID() << " : " << student_person2.getfirstName() << " "
////	<< student_person2.getlastName() << " from " << int_student.getcountry() << " country has cgpa of "
////	<< student_person2.getcgpa() << ", research score of " << student_person2.getresearchScore()
////	<< ", a reading score of " << current_TOEFL.getreading() << ", a listening score of "
////	<< current_TOEFL.getlistening() << ", a speaking score of "
////	<< current_TOEFL.getspeaking() << ", and a writing score of " << current_TOEFL.getwriting()
////	<< " which sums up to a total TOEFL Score of " << current_TOEFL.addTOEFLScore() << "." << endl << endl;
//
//stu_count_int++;
//student_number++;
//	}
//
//	//close the international student file file
//	internationalFile.close();
//	/*================================*/*/
