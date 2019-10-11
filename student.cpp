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

