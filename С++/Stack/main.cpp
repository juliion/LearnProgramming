#include <iostream>
#include <stack>
using namespace std;

void checkBrackets(string str)
{
	stack <char> correctBrackets;
	for (int i = 0; i < str.length(); i++)
	{
		char charOfStr = str[i];
		if (charOfStr == '(')
			correctBrackets.push(')');
		else if (charOfStr == '[')
			correctBrackets.push(']');
		else if (charOfStr == '{')
			correctBrackets.push('}');
		if (charOfStr == ')' || charOfStr == ']' || charOfStr == '}')
		{
			if (correctBrackets.empty() || correctBrackets.top() != charOfStr)
			{
				cout << str.substr(0, i) << " wrong" << endl;
				return;
			}
			correctBrackets.pop();
		}
	}
	if (correctBrackets.empty())
		cout << str << " - is correct!" << endl;
	else
		cout << str << " wrong" << endl;
}

int main()
{
	//test
	checkBrackets("({x-y-z}*[x+2y]-(z+4x)");
	checkBrackets("({x-y-z}*[x+2y]-(z+4x))");
	checkBrackets("([x-y-z}*[x+2y)-{z+4x)]");
	return 0;
}