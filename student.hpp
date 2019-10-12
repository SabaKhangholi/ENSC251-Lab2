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

	//check
	bool checkcgpa();
	bool checkresearchScore();

public:
	Student(); //Default Constructor
	Student(string _firstName, string _lastName, float _cgpa, int _researchScore, int _studentID);

	//Student(const Student& student_object);//Copy constructor 
	~Student(); //Destructor. Returns all dynamic memory used by the object to the freestore

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

	//friend funtion prototypes
	friend int compareCGPA(float cgpa1, float cgpa2);
	friend int compareResearchScore(int researchScore1, int researchScore2);
	friend int compareFirstName(string firstName1, string firstName2);
	friend int compareLastName(string lastName1, string lastName2);

	//overloaded extraction and insection operators
	friend ostream& operator <<(ostream& outs, const Student& student_person);
	//Precondition: If outs is a file output stream, then outs has already been
	//connected to a file

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

	string getprovince();
	void setprovince(string province);



private:
	string province;
};

//This is a seperate class for that will be used by the international students. 
class ToeflScore
{
public:
	ToeflScore(); //Default Constructor
	ToeflScore(int reading, int listening, int speaking, int writing);

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

	string getcountry();
	void setcountry(string country);

	ToeflScore getTOEFL();

private:
	string country;
	ToeflScore TOEFL;

};

#endif


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
