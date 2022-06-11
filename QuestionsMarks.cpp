/*
Have the function QuestionsMarks(str) take the str string parameter,
which will contain single digit numbers, letters, and question marks,
and check if there are exactly 3 question marks between every pair
of two numbers that add up to 10. If so, then your program should return
 the string true, otherwise it should return the string false. If there aren't
 any two numbers that add up to 10 in the string, then your program should return
 false as well.

For example: if str is "arrb6???4xxbl5???eee5" then your program should return true
because there are exactly 3 question marks between 6 and 4, and 3 question marks
between 5 and 5 at the end of the string.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>

void QuestionsMarks(std::string str)
{
	bool result = false;
	std::vector<int> digitPos;

	for (int i = 0; i < str.size(); i++)
	{
		if (std::isdigit(str[i]))
		{
			digitPos.push_back(i);
		}
	}
	for (int j = 0; j < digitPos.size(); j++)
	{
		try
		{
			digitPos.at(j + 1);
		}
		catch (...)
		{
			break;
		}
		auto start = str.begin();
		std::advance(start, digitPos[j]);
		auto stop = str.begin();
		std::advance(stop, digitPos[j + 1]);
		int startInt = int(*start) - 48;
		int stopInt = int(*stop) - 48;

		if ((std::count(start, stop, '?') == 3) and (startInt + stopInt) == 10)
		{
			result = true;
		}
	}

	std::cout << std::boolalpha << result << std::endl;
}

int main()
{
	QuestionsMarks("arrb6???4xxbl5???eee5");
}
