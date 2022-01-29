#include <iostream>

using namespace std;

struct complexNum
{
	double a;
	double b;
};

complexNum createCompNum()
{
	complexNum n;
	cout << "Введите вещественную часть: ";
	cin >> n.a;
	cout << "Введите мнимую часть(без i): ";
	cin >> n.b;
	return n;
}

complexNum sum(complexNum n1, complexNum n2)
{
	complexNum resNum;
	resNum.a = n1.a + n2.a;
	resNum.b = n1.b + n2.b;
	return resNum;
}

complexNum diff(complexNum n1, complexNum n2)
{
	complexNum resNum;
	resNum.a = n1.a - n2.a;
	resNum.b = n1.b - n2.b;
	return resNum;
}

complexNum mult(complexNum n1, complexNum n2)
{
	complexNum resNum;
	resNum.a = n1.a * n2.a - n1.b * n2.b;
	resNum.b = n1.b * n2.a + n1.a * n2.b;
	return resNum;
}

complexNum div(complexNum n1, complexNum n2)
{
	complexNum resNum;
	resNum.a = (n1.a * n2.a + n1.b * n2.b) / (n2.a * n2.a + n2.b * n2.b);
	resNum.b = (n1.b * n1.a - n1.a * n2.b) / (n2.a * n2.a + n2.b * n2.b);
	return resNum;
}

void printNum(complexNum n)
{
	cout << n.a << (n.b >= 0 ? " + " : " ") << n.b << "i";
}


int main()
{
	setlocale(0, "");
	complexNum n1, n2, res;
	char act;
	int a;
	do
	{
		cout << "Введите комплексное число:" << endl;
		n1 = createCompNum();
		cout << "действие(+-*/ ):";
		cin >> act;
		cout << "и второе комплексное число:" << endl;
		n2 = createCompNum();
		switch (act)
		{
		case '+':
			res = sum(n1, n2);
			break;
		case '-':
			res = diff(n1, n2);
			break;
		case '*':
			res = mult(n1, n2);
			break;
		case '/':
			if (n2.a == 0 && n2.b == 0)
			{
				cout << "Ошибка деления на ноль!" << endl;
				return 0;
			}
			res = div(n1, n2);
			break;
		default:
			cout << "Введены неправильные значения!";
		}

		cout << "(";
		printNum(n1);
		cout << ") " << act << " (";
		printNum(n2);
		cout << ") = ";
		printNum(res);
		cout << endl;

		cout << "Если хотите продолжить, введите 1:" << endl
			<< "Для выхода введите любое другое число:" << endl;
		cin >> a;
	} while (a == 1);
	return 0;
}