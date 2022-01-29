#include<iostream>
#include<string>
#include<cstring>
using namespace std;

union number
{
	char ns[9];
	int ni;
};

struct car
{
	string model;
	string color;
	number carNumber;
	int typeNumber;
};

void createCarNumber(car* c)
{
	do
	{
		cout << "������� ��� ������ ������:" << endl
			<< "1 - ����������� �����" << endl
			<< "2 - ����� �� 8 ��������" << endl;
		cin >> c->typeNumber;
	} while (c->typeNumber != 1 && c->typeNumber != 2);

	switch (c->typeNumber)
	{
	case 1:
	{
		do
		{
			cout << "������� ����������� �����: ";
			cin >> c->carNumber.ni;
		} while (c->carNumber.ni > 99999 || c->carNumber.ni < 10000);
	}
	break;
	case 2:
	{
		cout << "������� ����� �� 8 ��������: ";
		cin.ignore();
		cin.getline(c->carNumber.ns, 9);
	}
	break;
	}
}

car createCar()
{
	car c;
	cout << "������� ������ ������: ";
	cin.ignore();
	getline(cin, c.model);
	cout << "������� ����: ";
	getline(cin, c.color);
	createCarNumber(&c);
	return c;
}

void printCar(car c)
{
	cout << "������: " << c.model << endl;
	cout << "����: " << c.color << endl;
	cout << "�����: ";
	switch (c.typeNumber)
	{
	case 1: cout << c.carNumber.ni << endl; break;
	case 2: cout << c.carNumber.ns << endl; break;
	}
}

car* createArrayOfCars(int n)
{
	car* cars = new car[n];
	for (int i = 0; i < n; i++)
	{
		cout << "------------������ #" << i + 1 << "-------------" << endl;
		cars[i] = createCar();
	}
	return cars;
}

void printArrayOfCars(car* cars, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "------------������ #" << i + 1 << "-------------" << endl;
		printCar(cars[i]);
	}
	cout << endl;
}

car searchByNumber(int typeNum, number searchNum, car* cars, int n)
{
	car foundCar;
	foundCar.model = "not found";
	switch (typeNum)
	{
	case 1:
	{
		for (int i = 0; i < n; i++)
		{
			if (cars[i].carNumber.ni == searchNum.ni)
			{
				foundCar = cars[i];
			}
		}
	}
	break;
	case 2:
	{
		for (int i = 0; i < n; i++)
		{
			if (strcmp(cars[i].carNumber.ns, searchNum.ns) == 0)
			{
				foundCar = cars[i];
			}
		}
	}
	break;
	}
	return foundCar;
}

void editCar(int i, car* cars, int n)
{
	car* changeCar = &cars[i];
	int ch;
	cout << "�������, ��� �� ������ ��������: " << endl
		<< "1 - ������" << endl
		<< "2 - ����" << endl
		<< "3 - ����� ������" << endl;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		cout << "������� ����� ������: ";
		cin.ignore();
		getline(cin, changeCar->model);
	}
	break;
	case 2:
	{
		cout << "������� ����� ����: ";
		cin.ignore();
		getline(cin, changeCar->color);
	}
	break;
	case 3:
	{
		createCarNumber(changeCar);
	}
	break;
	}

}
int main()
{
	setlocale(0, "");
	int n;
	cout << "������� ���������� �����: ";
	cin >> n;
	car* cars = createArrayOfCars(n);
	system("cls");
	int act;
	do
	{
		cout << "�������: " << endl
			<< "1 - ����� �������� ��� ������" << endl
			<< "2 - ������������� ������" << endl
			<< "3 - ����� ������ �� ������" << endl
			<< "����� ���� �����, ����� ���������" << endl << endl;
		cin >> act;
		switch (act)
		{
		case 1:
			printArrayOfCars(cars, n);
			break;
		case 2:
		{
			int cont;
			int i;
			do
			{
				cout << "������� ����� ������ � ������  (1-" << n << ") : ";
				cin >> i;
				editCar(i - 1, cars, n);
				cout << "������ #" << i << " ��������!" << endl;
				cout << "��� �� ���������� ��������� ������� 1" << endl
					<< "����� ������ �����, ����� �����" << endl;
				cin >> cont;
				system("cls");
			} while (cont == 1);
		}
		break;
		case 3:
		{
			car searchCar;
			createCarNumber(&searchCar);
			car foundCar = searchByNumber(searchCar.typeNumber, searchCar.carNumber, cars, n);
			if (foundCar.model == "not found")
				cout << endl << "������ �� ������� !" << endl;
			else
			{
				cout << endl << "------------������-------------" << endl;
				printCar(foundCar);
			}
			cout << endl;
		}
		break;
		default:
			cout << "������� ������������ ��������!";
		}
	} while (act >= 1 && act <= 3);
	return 0;
}