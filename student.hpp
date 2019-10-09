
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
		cout<< _studArray[i].getstdentID()<<" "
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
*/
