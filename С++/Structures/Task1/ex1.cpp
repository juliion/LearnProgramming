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
	cout << "������� ������������ �����: ";
	cin >> n.a;
	cout << "������� ������ �����(��� i): ";
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
		cout << "������� ����������� �����:" << endl;
		n1 = createCompNum();
		cout << "��������(+-*/ ):";
		cin >> act;
		cout << "� ������ ����������� �����:" << endl;
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
				cout << "������ ������� �� ����!" << endl;
				return 0;
			}
			res = div(n1, n2);
			break;
		default:
			cout << "������� ������������ ��������!";
		}

		cout << "(";
		printNum(n1);
		cout << ") " << act << " (";
		printNum(n2);
		cout << ") = ";
		printNum(res);
		cout << endl;

		cout << "���� ������ ����������, ������� 1:" << endl
			<< "��� ������ ������� ����� ������ �����:" << endl;
		cin >> a;
	} while (a == 1);
	return 0;
}