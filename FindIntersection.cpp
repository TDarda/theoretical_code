/*
Have the function FindIntersection(strArr) read the array of strings stored in 
strArr which will contain 2 elements: the first element will represent a list 
of comma-separated numbers sorted in ascending order, the second element will 
represent a second list of comma-separated numbers (also sorted). Your goal is to 
return a comma-separated string containing the numbers that occur in elements 
of strArr in sorted order. If there is no intersection, return the string false.
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <iterator>

std::vector<int> seperateVector(std::string str)
{
	std::vector<int> temp;
	std::string ss;
	auto it = str.begin();
	do
	{

		if (*it == ',' or *it == ' ')
		{
			if (!ss.empty())
			{
				temp.push_back(std::stoi(ss));
			}
			ss = "";
		}
		else
		{
			ss += *it;
		}
		it++;
	} while (it != str.end());
	if (!ss.empty())
	{
		temp.push_back(std::stoi(ss));
	}
	return temp;
}

void FindIntersection(std::vector<std::string> strArr)
{
	std::vector<int> firstSet = seperateVector(strArr[0]);
	std::vector<int> secondSet = seperateVector(strArr[1]);
	std::set<int> result;

	for (auto &first : firstSet)
	{
		for (auto &second : secondSet)
		{
			if (first == second)
			{
				result.insert(first);
			}
		}
	}

	if (result.empty())
	{
		std::cout << false << std::endl;
	}
	else
	{
		std::copy(result.begin(), result.end(), std::ostream_iterator<int>(std::cout, ", "));
	}
}

int main(int argc, char *argv[])
{
	std::vector<std::string> str{"1, 3, 9, 10, 17, 18", "1, 4, 9, 10"};
	FindIntersection(str);
}
