#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

bool zad1(string s)
{
	Stack <char> brackets;
	int i = 0;
	while (i < s.length())
	{
		if ((s[i] == '(') || (s[i] == '{') || (s[i] == '['))
			brackets.push(s[i]);
		else if  ((!brackets.empty()) && (s[i] == ')') && (brackets.top() == '(') || (s[i] == '}') && (brackets.top() == '{') || (s[i] == ']') && (brackets.top() == '['))
		{
			brackets.pop();
		}
		else if ((s[i] == ')') || (s[i] == '}') || (s[i] == ']'))
			return false;
		i++;
	}
	if (brackets.empty())
		return true;
	return false;
}

void main(int argc, char *argv[])
{
	
	string s = argv[1];
	cout << zad1(s) << '\n';
}

