/*
Have the function BracketMatcher(str) take the str parameter
being passed and return 1 if the brackets are correctly matched
and each one is accounted for. Otherwise return 0. For example: if str
is "(hello (world))", then the output should be 1, but if str is "((hello (world))"
the the output should be 0 because the brackets do not correctly match up.
Only "(" and ")" will be used as brackets. If str contains no brackets return 1.
*/
#include <iostream>
#include <algorithm>
#include <iomanip>

void BracketMatcher(std::string str)
{
	bool result = false;
	int numberOfOpenBracket = count(str.begin(), str.end(), '(');
	int numberOfCloseBracket = count(str.begin(), str.end(), ')');

	if (numberOfOpenBracket == numberOfCloseBracket)
	{
		result = true;
	}
	std::cout << std::boolalpha << result << std::endl;
}

int main()
{
	BracketMatcher("(hello (world))");
	BracketMatcher("((hello (world))");
	BracketMatcher("hello world");
}
