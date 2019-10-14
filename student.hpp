/*ENSC 251 - LAB1
*Authors: Saba Khangholi and Sharanjit Virdi
*September 25, 2019
*This is the header file studnent.hpp which declares all our classes.
*/

#pragma once 
#define DEBUG 
#ifdef DEBUG
#define STUDENT_HPP  //Might havet to change it 

#include <iostream>
using namespace std; //use namespace std
#include <string> //we will have to use string in C++
#include <cstdlib>
#include <cstddef>


//Create a parent class called student that has first_name, last_name, CGPA,
//research_score, and student ID as its member variables.
class Student
{
private:
	string firstName;
	string lastName;
	float cgpa;
	int researchScore;
	int studentID;

	Student* stu_array;

	//check
	//bool checkcgpa();
	//bool checkresearchScore();


//	Student(string FN="")
/*	{
		firstName = FN;
	};*/

public:
	Student(); //Default Constructor
	Student(string _firstName, string _lastName, float _cgpa, int _researchScore, int _studentID);

	Student(const Student& student_object);//Copy constructor declaration
	//~Student(); //Destructor. Returns all dynamic memory used by the object to the freestore

	//get functions
	string getfirstName();
	string getlastName();
	float  getcgpa();
	int getresearchScore();
	int getstudentID();

	//set functions
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setcgpa(float cgpa);
	void setresearchScore(int researchScore);
	void setstudentID(int studentID);

	//check fuctions
	bool checkcgpa();
	bool checkresearchScore();

	//overloaded extraction and insection operators
	friend ostream& operator <<(ostream& outs, const Student& student_person);
	//Precondition: If outs is a file output stream, then outs has already been
	//connected to a file

	//Overloaded assignemnt operator declaration
	void operator =(Student& right_side); //Overloads the assignemnt operator = to copy a string from one object to another

	////friend funtion prototypes
	//friend int compareCGPA(float cgpa1, float cgpa2);
	//friend int compareResearchScore(int researchScore1, int researchScore2);
	//friend int compareFirstName(string firstName1, string firstName2);
	//friend int compareLastName(string lastName1, string lastName2);

	////DO WE NEED TO OVERLOAD THIS?=================================================????
	//friend istream& operator <<(istream& outs, const Student& student_person);
	////Precondition: If outs is a file output stream, then outs has already been
	////connected to a file


};

//This is a child class from the parent class Student, which has inherited 
//all the objects from the parent class and has extended to include the 
//province object.
//This allows for code reusability.
class DomesticStudent :public Student
{
public:
	DomesticStudent(); //Default Constructor
	DomesticStudent(string province);
	DomesticStudent(string _firstName, string _lastName, float _cgpa, int _researchScore, int _studentID, string province);

	DomesticStudent(const DomesticStudent& dom_student_object)
	{
		province = "";
	};
	//Copy constructor declaration
	//~DomesticStudent(); //Destructor. Returns all dynamic memory used by the object to the freestore

	string getprovince();
	void setprovince(string province);

	//friend funtion prototypes
	friend int compareCGPA_dom(DomesticStudent cgpa1, DomesticStudent cgpa2);
	friend int compareResearchScore_dom(DomesticStudent researchScore1, DomesticStudent researchScore2);
	friend int compareFirstName_dom(DomesticStudent firstName1, DomesticStudent firstName2);
	friend int compareLastName_dom(DomesticStudent lastName1, DomesticStudent lastName2);
	friend int compareProvince(DomesticStudent dom1, DomesticStudent dom2);

	friend ostream& operator <<(ostream& outs, DomesticStudent& _dom_student);


	//Overloaded assignemnt operator declaration
	void operator =(const DomesticStudent& right_side); //Overloads the assignemnt operator = to copy a string from one object to another
	//const DomesticStudent& operator =(const DomesticStudent& );

	//friend void sort_dom_CGPA(DomesticStudent*);

private:
	string province;
	DomesticStudent* dom_array;
};

//This is a seperate class for that will be used by the international students. 
class ToeflScore
{
public:
	ToeflScore(); //Default Constructor
	ToeflScore(int reading, int listening, int speaking, int writing);
	//friend ostream& operator <<(ostream& outs, const ToeflScore& _currentToefl);

	//This is a member function of the ToeflScore Class.
	int addTOEFLScore();

	int getreading();
	int getlistening();
	int getspeaking();
	int getwriting();
	int gettotalScore();

	void setreading(int reading);
	void setlistening(int listening);
	void setspeaking(int speaking);
	void setwriting(int writing);
	void settotalScore(int totalScore);

	bool checkreading();
	bool checkwriting();
	bool checklistening();
	bool checkspeaking();
	bool checktotalScore();

private:
	int reading;
	int listening;
	int speaking;
	int writing;
	int totalScore; // will sum of reading, listening, speaking, and writing scores
};

//This is another child class from the parent class Student, which has inherited
//all objects from the parent class and has extended to include the 
//country object and the ToeflScore class.
//This also allows for code reusability.
class InternationalStudent :public Student
{
public:
	InternationalStudent(); //Default Constructor
	InternationalStudent(string country, ToeflScore TOEFL);

	InternationalStudent(const InternationalStudent& int_student_object)
	{
		country = "";
	};//Copy constructor declaration
	//~InternationalStudent(); //Destructor. Returns all dynamic memory used by the object to the freestore

	string getcountry();
	//string getTOEFL();
	void setcountry(string country);
	//void setTOEFL(ToeflScore TOEFL);


	ToeflScore getTOEFL();

	//friend funtion prototypes
	friend int compareCGPA_int(InternationalStudent cgpa1, InternationalStudent cgpa2);
	friend int compareResearchScore_int(InternationalStudent researchScore1, InternationalStudent researchScore2);
	friend int compareFirstName_int(InternationalStudent firstName1, InternationalStudent firstName2);
	friend int compareLastName_int(InternationalStudent lastName1, InternationalStudent lastName2);
	friend int compareCountry(InternationalStudent int1, InternationalStudent int2);

	friend ostream& operator <<(ostream& outs, InternationalStudent& _int_student);

	//Overloaded assignemnt operator declaration
	//void operator =(InternationalStudent& right_side); //Overloads the assignemnt operator = to copy a string from one object to another
	void operator =(const InternationalStudent& right_side);

private:
	string country;
	ToeflScore TOEFL;
	InternationalStudent* int_array;

};

#endif

//sort  functions//
void sort_dom_CGPA(DomesticStudent*);
void sort_int_CGPA(InternationalStudent*);

void sort_dom_ResearchScore(DomesticStudent*);
void sort_int_ResearchScore(InternationalStudent*);

void sort_dom_FirstName(DomesticStudent*);
void sort_int_FirstName(InternationalStudent*);

void sort_dom_LastName(DomesticStudent*);
void sort_int_LastName(InternationalStudent*);

//swap fucntions 
void swap_dom_student(DomesticStudent*, DomesticStudent*);
void swap_int_student(InternationalStudent*, InternationalStudent*);

void sort_dom_province(DomesticStudent* Dom_Stu_Array);
void sort_int_country(InternationalStudent* Int_Stu_Array);

////swap fucntions 
//void swap_int(int*, int*);
//void swap_float(float*, float*);
//void swap_string(string*, string*);


//Overloading the extraction operator to be able to output to the console
//NEED TO SEE IF Student and student_person
//Assume student_person is a domestic or and international student object
//THIS IS WRONG--> NEED TO HAVE SOMETHING DIFFERENT FOR DOM AND INT
//ostream& operator <<(ostream& outs, const Student& student_person)
//{
//	//outs << student_person.getfirstName();
//	//outs << student_person.getlastName();
//	//outs << student_person.getcgpa();
//	//outs << student_person.getresearchScore();
//	//outs << student_person.getstudentID();
//	//outs << student_person.getprovince();
//	//outs << student_person.getcountry();
//	//outs << student_person.getreading();
//	//outs << student_person.getlistening();
//	//outs << student_person.getspeaking();
//	//outs << student_person.getwriting();
//	//outs << student_person.gettotalScore();
//	return outs;
//}



/*
class Student
{
public:
	friend ostream& operator <<(ostream& outs, const Student& student_person);
	//Precondition: If outs is a file output stream, then outs has already been
	//connected to a file
	//Postcondition: ____________NEED TO FIGURE IT OUT_________
	//...

	//DO WE NEED TO OVERLOAD THIS?
	friend istream& operator <<(istream& outs, const Student& student_person);
	//Precondition: If outs is a file output stream, then outs has already been
	//connected to a file
	//Postcondition: ____________NEED TO FIGURE IT OUT_________
	//...

	//friend funtion prototypes
	friend int compareCGPA(float cgpa1, float cgpa2);
	friend int compareResearchScore(int researchScore1, int researchScore2);
	friend int compareFirstName(string firstName1, string firstName2);
	friend int compareLastName(string lastName1, string lastName2);
}


//sort  functions
void sort_dom_CGPA(DomesticStudent);
void sort_int_CGPA(InternationalStudent);

void sort_dom_ResearchScore(DomesticStudent);
void sort_int_ResearchScore(InternationalStudent);

void sort_dom_FirstName(DomesticStudent);
void sort_int_FirstName(InternationalStudent);

void sort_dom_LastName(DomesticStudent);
void sort_int_LastName(InternationalStudent);

//swap fucntions
void swap_int(int*, int*);
void swap_float(float*, float*);
void swap_string(string*, string*);

//NEED TO SEE IF Student and student_person
//Assume student_person is a domestic or and international student object
//THIS IS WRONG--> NEED TO HAVE SOMETHING DIFFERENT FOR DOM AND INT
ostream& operator <<(ostream& outs, const Student& student_person)
{
	outs<< student_person.firstName;
	outs<< student_person.lastName;
	outs<< student_person.cgpa;
	outs<< student_person.researchScore;
	outs<< student_person.studentID;
	outs<< student_person.province;
	outs<< student_person.country;
	outs<< student_person.reading;
	outs<< student_person.listening;
	outs<< student_person.speaking;
	outs<< student_person.writing;
	outs<< student_person.totalScore;
	return outs;
}


//This is a Sort function that sorts the students by their CGPA --> using compareCGPA
void sort_CGPA(Student _studArray)
{
	int arr_len=sizeof(_studArray);
	int i,j;
	for (i=0, i<arr_len-1, i++)
	{
		for(j=0, j<arr_len-1, j++)
		{
			result=compareCGPA(_studArray[j].getcgpa(), _studArray[j+1].getcgpa());
			if (result==-1)
			{
				swap_float(&_studArray[j], &_studArray[j+1]);
			}
		}

	}
}

//This is a Sort function that sorts the students by their Research Score --> using compareResearchScore
void sort_ResearchScore(Student _studArray)
{
	int arr_len=sizeof(_studArray);
	int i,j;
	for (i=0, i<arr_len-1, i++)
	{
		for(j=0, j<arr_len-1, j++)
		{
			result=compareResearchScore(_studArray[j].getresearchScore(), _studArray[j+1].getResearchScore());
			if (result==-1)
			{
				swap(&_studArray[j], &_studArray[j+1]);
			}
		}

	}
}

//This is a Sort function that sorts the students by their First Name Score --> using compareFirstName
void sort_FirstName(Student _studArray)
{
	int arr_len=sizeof(_studArray);
	int i,j;
	for (i=0, i<arr_len-1, i++)
	{
		for(j=0, j<arr_len-1, j++)
		{
			result=compareFirstName(_studArray[j].getfirstName(), _studArray[j+1].getfirstName());
			if (result==1)
			{
				swap_string(&_studArray[j], &_studArray[j+1]);
			}
		}

	}
}

//This is a Sort function that sorts the students by their Last Name Score --> using compareLastName
void sort_LastName(Student _studArray)
{
	int arr_len=sizeof(_studArray);
	int i,j;
	for (i=0, i<arr_len-1, i++)
	{
		for(j=0, j<arr_len-1, j++)
		{
			result=compareLastName(_studArray[j].getcgpa(), _studArray[j+1].getcgpa());
			if (result==1)
			{
				swap(&_studArray[j], &_studArray[j+1]);
			}
		}

	}
}


void swap_int(int *first, int *second)
{
	int temp;
	temp=*first;
	*first=*second;
	*second=temp;
}

void swap_float(float *first, float *second)
{
	float temp;
	temp=*first;
	*first=*second;
	*second=temp;
}

void swap_string(string *first, string *second)
{
	string temp;
	temp=*first;
	*first=*second;
	*second=temp;
}
//Compare functions: 1 for greater, 0 for equal, -1 for less



//Print Array function for Domestic Students
void PrintArrayDomestic(Student _studArray)
{
	int arr_len=sizeof(_studArray);
	int i,j;
	for (i=0, i<arr_len-1, i++)
	{
		cout<< _studArray[i].getstdentID()<<" "
			<< _studArray[i].getfirstName()<<" "
			<< _studArray[i].getlastName()<<" "
			<< _studArray[i].getprovince()<<" "
			<< _studArray[i].getcgpa()<<" "
			<< _studArray[i].getresearchScore()<<" "<< endl;
	}
}

//Print Array function for International Students
void PrintArrayInternational(Student _studArray)
{
	int arr_len=sizeof(_studArray);
	int i,j;
	for (i=0, i<arr_len-1, i++)
	{
		cout<< _studArray[i].getstudentID()<<" "
			<< _studArray[i].getfirstName()<<" "
			<< _studArray[i].getlastName()<<" "
			<< _studArray[i].getcountry()<<" "
			<< _studArray[i].getcgpa()<<" "
			<< _studArray[i].getresearchScore()<<" "
			<< _studArray[i].getTOEFL().getreading()<<" "
			<< _studArray[i].getTOEFL().getlistening()<<" "
			<< _studArray[i].getTOEFL().getspeaking()<<" "
			<< _studArray[i].getTOEFL().getwriting()<<" "
			<< _studArray[i].getTOEFL().addTOEFLScore()<<endl;
//Not sure if the access to the getTOEFL works or not
	}
}

/*
//This is a Sort function that sorts the students by their CGPA --> usinf swap
void sort_CGPA(Student _studArray)
{
	int arr_len=sizeof(_studArray);
	int i,j;
	for (i=0, i<arr_len-1, i++)
	{
		for(j=0, j<arr_len-1, j++)
		{
			if (_studArray[j].getcgpa()>_studArray[j+1].getcgpa())
			{
				swap(&_studArray[j], &_studArray[j+1]);
			}
		}

	}
}

//This is a Sort function that sorts the students by their rese
void sort_ResearchScore(Student _studArray)
{
	int arr_len=sizeof(_studArray);
	int i,j;
	for (i=0, i<arr_len-1, i++)
	{
		for(j=0, j<arr_len-1, j++)
		{
			if (_studArray[j].getresearchScore()>_studArray[j+1].getresearchScore())
			{
				swap(&_studArray[j], &_studArray[j+1]);
			}
		}

	}
}
*///new
