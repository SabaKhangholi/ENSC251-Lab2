/*ENSC 251 - LAB1
*Authors: Saba Khangholi and Sharanjit Virdi
*September 25, 2019
*/

/* This program is the framework for SFU's Graduate Student Admissions Program.
We have created a parent class: Student, two child classes of the parent class Student:
DomesticStudent and InternationalStudent, as well as a fourth class, ToeflScore.
DomesticStudent and InternationalStudent inherit all the members of Student and
also define members specific to their properties. An object of ToeflScore class is used as
the member variable for the InternationalStudent class. */

//student.cpp to implement our classes

#include "student.hpp"
#include<string>
#include <iostream>
using namespace std;

//Constructor Definition
Student::Student() {}; 	      //Default constructor declaration for Student
ToeflScore::ToeflScore() {};  //Default constructor declaration for ToeflScore
InternationalStudent::InternationalStudent() {};
DomesticStudent::DomesticStudent() {};


/* Here, we are defining the Student class constructor with all of the parameters in the class.
Within the function body, the set functions are initialized with each parameter. */
Student::Student(string _firstName, string _lastName, float _cgpa, int _researchScore, int _studentID)
{
	setfirstName(_firstName);
	setlastName(_lastName);
	setcgpa(_cgpa);
	setresearchScore(_researchScore);
	setstudentID(_studentID);

	checkcgpa();
	checkresearchScore();
};
/*This is the DomesticStudent constructor. Child classDomesticStudent inherits all members
from parent class Student using the single colon. Within the funciton body, we are using our
mutator member function, to set the _province name to our province member variable.*/
DomesticStudent::DomesticStudent(string _province) : Student()
{
	setprovince(_province);
};

/*This is the ToeflScore constructor. Within the function body, all mutator member functions are used
to set each name to its respective member variable.*/
ToeflScore::ToeflScore(int _reading, int _listening, int _speaking, int _writing)
{
	setreading(_reading);
	setlistening(_listening);
	setspeaking(_speaking);
	setwriting(_writing);

	checkreading();
	checkwriting();
	checklistening();
	checkspeaking();
};


/*This is the InternationalStudent constructor. Within the function body, all mutator member functions are used
to set each name to its respective member variable.*/
InternationalStudent::InternationalStudent(string _country, ToeflScore TOEFL) :Student()
{
	setcountry(_country);
};

//addScore Function
/*This function adds all four components of the TOEFL test and returns the sum as an int.*/
int ToeflScore::addTOEFLScore()
{
	totalScore = reading + listening + speaking + writing;
	return totalScore;
};


//accessor/get functions: implementation/definition
/*These are the definitions of the public accessor member functions of each one of the four classes.
We use the scope resolution operator "::" to specify the class in which the member function is used.
These accessor functions allow access to the private member variables of each class.*/

//get functions definiton for the student clas
string Student::getfirstName()
{
	return firstName;
};

string Student::getlastName()
{
	return lastName;
};

float Student::getcgpa()
{
	return cgpa;
};

int Student::getresearchScore()
{
	return researchScore;
};

int Student::getstudentID()
{
	return studentID;
};


//get function definiton for the domestic student class
string DomesticStudent::getprovince()
{
	return province;
};


//get function definiton for the international student class
string InternationalStudent::getcountry()
{
	return country;
};


//get functions definiton for the ToeflScore class
int ToeflScore::getreading()
{
	return reading;
};

int ToeflScore::getlistening()
{
	return listening;
};

int ToeflScore::getspeaking()
{
	return speaking;
};

int ToeflScore::getwriting()
{
	return writing;
};

int ToeflScore::gettotalScore()
{
	return totalScore;
};

ToeflScore InternationalStudent::getTOEFL()
{
	return TOEFL;
};

//set function implementation/definition
/*These are the definitions of the public mutator member functions of each one of the four classes. We use the
scope resolution operator "::" to specify the class in which the member function is used. These mutator functions
allow for modification of the private member variables of each class.*/

//set functions definitions for hte student class
void Student::setfirstName(string first_Name)
{
	firstName = first_Name;
};

void Student::setlastName(string last_Name)
{
	lastName = last_Name;
};

void Student::setcgpa(float in_cgpa)
{
	cgpa = in_cgpa;
};

void Student::setresearchScore(int research_Score)
{
	researchScore = research_Score;
};

void Student::setstudentID(int student_ID)
{
	studentID = student_ID;
};

//set function deinitions for the domestic student class
void DomesticStudent::setprovince(string in_province)
{
	province = in_province;
};

//set function deinitions for the domestic student class
void InternationalStudent::setcountry(string in_country)
{
	country = in_country;
};

//set function deinitions for the ToeflScore class
void ToeflScore::setreading(int in_reading)
{
	reading = in_reading;
};

void ToeflScore::setlistening(int in_listening)
{
	listening = in_listening;
};

void ToeflScore::setspeaking(int in_speaking)
{
	speaking = in_speaking;
};

void ToeflScore::setwriting(int in_writing)
{
	writing = in_writing;
};

void ToeflScore::settotalScore(int _totalScore)
{
	writing = _totalScore;
};



// new check functions for the cgpa and research score 
/*This is the check function for the CGPA. The bounds are from 0 to 4.33 inclusive.*/
bool Student::checkcgpa() //make sure to prototype
{
	bool flag = true;
	if (cgpa < 0 || cgpa>4.33)
	{
		flag = false;
	};
	return flag;
};

/*This is the check function for the research score. The bounds are from 0 to 100, inclusive.*/
bool Student::checkresearchScore() // make sure to protype
{
	bool flag = true;
	if (researchScore < 0 || researchScore>100)
	{
		flag = false;
	}
	return flag;
};

//check funcitions for toefl scores
bool ToeflScore::checkreading() // make sure to prototype
{
	bool flag = true;
	if (reading < 20 || reading>30)
	{
		flag = false;
	};
	return flag;
};
bool ToeflScore::checklistening() // make sure to prototype
{
	bool flag = true;
	if (listening < 20 || listening>30)
	{
		flag = false;
	};
	return flag;
};
bool ToeflScore::checkspeaking() // make sure to prototype
{
	bool flag = true;
	if (speaking < 20 || speaking>30)
	{
		flag = false;
	};
	return flag;
};
bool ToeflScore::checkwriting() // make sure to prototype
{
	bool flag = true;
	if (writing < 20 || writing>30)
	{
		flag = false;
	};
	return flag;
};
bool ToeflScore::checktotalScore()//make sure to prototype
{
	bool flag = true;
	if (totalScore < 93 || totalScore>120)
	{
		flag = false;
	};
	return flag;
};

//Destructor definition
Student::~Student()
{

}



//Swap fucntion definitions
void swap_int(int* first, int* second)
{
	int temp;
	temp = *first;
	*first = *second;
	*second = temp;
};

void swap_float(float* first, float* second)
{
	float temp;
	temp = *first;
	*first = *second;
	*second = temp;
};

void swap_string(string* first, string* second)
{
	string temp;
	temp = *first;
	*first = *second;
	*second = temp;
};

//ostream operator from Sharanjit's code
ostream& operator <<(ostream& outs, DomesticStudent& dom_student) //not sure if we should include const -- bc then can't modify
{
	outs << dom_student.getfirstName();
	outs << dom_student.getlastName();
	outs << dom_student.getcgpa();
	outs << dom_student.getresearchScore();
	outs << dom_student.getstudentID();
	outs << dom_student.getprovince();
	return outs;
}

ostream& operator <<(ostream& outs, InternationalStudent& int_student)//not sure if we should include const -- bc then can't modify?
{
	outs << int_student.getfirstName();
	outs << int_student.getlastName();
	outs << int_student.getcgpa();
	outs << int_student.getresearchScore();
	outs << int_student.getstudentID();
	outs << int_student.getcountry();

	return outs;
}

ostream& operator <<(ostream& outs, ToeflScore& _currentToefl)//not sure if we should include const -- bc then can't modify?
{
	outs << _currentToefl.getreading();
	outs << _currentToefl.getlistening();
	outs << _currentToefl.getspeaking();
	outs << _currentToefl.getwriting();
	outs << _currentToefl.gettotalScore();
};


//sort fuctnion definitions

////This is a Sort function that sorts the domestic students by their First Name Score
//void sort_dom_CGPA(DomesticStudent Dom_Stu_Array)
//{
//	int arr_len = sizeof(Dom_Stu_Array);
//	int i, j;
//	int result;
//	for (i = 0; i < (arr_len - 1); i++)
//	{
//		result = compareCGPA(Dom_Stu_Array[i].getcgpa(), Dom_Stu_Array[i + 1].getcgpa());
//		if (result == -1)
//		{
//			swap_float(&Dom_Stu_Array[i], &Dom_Stu_Array[i + 1]);
//		}
//
//		//for (j = 0; j < (arr_len - 1); j++)
//		//{
//		//	result = compareCGPA(Dom_Stu_Array[j].getcgpa(), Dom_Stu_Array[j + 1].getcgpa());
//		//	if (result == -1)
//		//	{
//		//		swap_float(&Dom_Stu_Array[j], &Dom_Stu_Array[j + 1]);
//		//	}
//		//};
//
//	};
//};
//
////This is a Sort function that sorts the domestic students by their First Name Score
//void sort_int_CGPA(InternationalStudent Int_Stu_Array)
//{
//	int arr_len = sizeof(Int_Stu_Array);
//	int i, j;
//	int result;
//	for (i = 0; i < (arr_len - 1); i++)
//	{
//		result = compareCGPA(Int_Stu_Array[i].getcgpa(), Int_Stu_Array[i + 1].getcgpa());
//		if (result == -1)
//		{
//			swap_float(&Int_Stu_Array[i], &Int_Stu_Array[i + 1]);
//		}
//
//		/*for (j = 0; j < arr_len - 1; j++)
//		{
//			result = compareCGPA(Int_Stu_Array[j].getcgpa(), Int_Stu_Array[j + 1].getcgpa());
//			if (result == -1)
//			{
//				swap_float(&Int_Stu_Array[j], &Int_Stu_Array[j + 1]);
//			}
//		};*/
//
//	};
//};






//============================================================================================



//friend function definitons
int compareCGPA(float cgpa1, float cgpa2)
{
	if (cgpa1 > cgpa2)
	{
		return 1;
	}
	else if (cgpa1 = cgpa2)
	{
		return 0;
	}
	else if (cgpa1 < cgpa2)
	{
		return -1;
	};
};

int compareresearchScore(int researchScore1, int researchScore2)
{

	if (researchScore1 > researchScore2)
	{
		return 1;
	}
	else if (researchScore1 = researchScore2)
	{
		return 0;
	}
	else if (researchScore1 < researchScore2)
	{
		return -1;
	};

};
//
//int compareFirstName(string firstName1, string firstName2)
//{
//	int result;
//	int count = 30;
//	int len_FN1 = firstName1.size();
//	int len_FN2 = firstName2.size();
//	int max_value;
//
//
//	char str1[len_FN1 + 1] = firstName1;
//	char str2[len_FN2 + 1] = firstName2;
//
//	if (len_FN1 > len_FN2)
//	{
//		max_value = len_FN2;
//	}
//	else if (len_FN1 > len_FN2)
//	{
//		max_value = len_FN2;
//	};
//
//
//	if (len_FN1 == len_FN2)
//	{
//		for (int i = 0; i < (len_FN1 - 1); i++)
//		{
//			result = strcmp(const char *str1[i], const char *str2[i]);
//		};
//	}
//	else
//	{
//		for (int i = 0; i < max_value - 1; i++) {};
//	};
//
//	
//	result = strncmp(const char firstName1, const char firstName2, size_t count) //count: number of characters we allow
//	return result; // not sure if this syntax works --seems cleaner
//}
//
//friend int compareLastName(string lastName1 lastName2)
//{
//	int count = 30;
//	result = strncmp(const char lastName1, const char lastName2, size_t count) //count: number of characters we allow
//		return result; // not sure if this syntax works --seems cleaner	
//}



//friend function definitons
friend int compareCGPA(float cgpa1 cgpa2)
{
	if (cgpa1> cgpa2)
	{
	return 1;	
	}
	else if (cgpa1= cgpa2)
	{
		return 0;
	}
	else (cgpa1< cgpa2)
	{
		return -1;
	}	
}

friend int compareresearchScore(float researchScore1 researchScore2)
{
	
	if (researchScore1> researchScore2)
	{
	return 1;	
	}
	else if (researchScore1= researchScore2)
	{
		return 0;
	}
	else (researchScore1< researchScore2)
	{
		return -1;
	}
	
}

friend int compareFirstName(string firstName1 firstName2)
{
	int count = 30;
	result = strncmp(const char firstName1, const char firstName2, size_t count) //count: number of characters we allow
	return result; // not sure if this syntax works --seems cleaner
}

friend int compareLastName(string lastName1 lastName2)
{
	int count = 30;
	result = strncmp(const char lastName1, const char lastName2, size_t count) //count: number of characters we allow
	return result; // not sure if this syntax works --seems cleaner	
}

// reads information from domestic student file, checks, and places into the array _studArray

