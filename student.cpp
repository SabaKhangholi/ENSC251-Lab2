//Sharanjit's Compares that do not work :(

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


//===================================================================
// new check functions for the cgpa and research score 
/*This is the check function for the CGPA. The bounds are from 0 to 4.33 inclusive.*/
bool Student::checkcgpa() //make sure to prototype
{
   bool flag = true;
	if (cgpa< 0 || cgpa>4.33)
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
  flag = true;
	if (listening < 20 || listening>30)
	{
		flag = false;
	};
return flag;
};
bool ToeflScore::checkspeaking() // make sure to prototype
{
  flag = true;
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
		return flag;
	};
	else
	{
		return not flag;
	};
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

//friend funtion prototypes
friend int compareCGPA(float cgpa1 cgpa2);
friend int compareResearchScore(int researchScore1 researchScore2);
friend int compareFirstName(string firstName1 firstName2);
friend int compareLastName(string lastName1 lastName2);

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


//ostream operator from Sharanjit's code
ostream& operator <<(ostream& outs, const DomesticStudent& dom_student) //not sure if we should include const -- bc then can't modify
{
	outs<< dom_student.firstName;
	outs<< dom_student.lastName;
	outs<< dom_student.cgpa;
	outs<< dom_student.researchScore;
	outs<< dom_student.studentID;
	outs<< dom_student.province;
	return outs;
}

ostream& operator <<(ostream& outs, const InernationalStudent& int_student)//not sure if we should include const -- bc then can't modify?
{
	outs<< int_student.firstName;
	outs<< int_student.lastName;
	outs<< int_student.cgpa;
	outs<< int_student.researchScore;
	outs<< int_student.studentID;
	outs<< int_student.country;
	outs<< int_student.reading;
	outs<< int_student.listening;
	outs<< int_student.speaking;
	outs<< int_student.writing;
	outs<< int_student.totalScore;
	return outs;
}
