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
		cout << "Введите тип номера машины:" << endl
			<< "1 - пятизначный номер" << endl
			<< "2 - слово до 8 символов" << endl;
		cin >> c->typeNumber;
	} while (c->typeNumber != 1 && c->typeNumber != 2);

	switch (c->typeNumber)
	{
	case 1:
	{
		do
		{
			cout << "Введите пятизначное число: ";
			cin >> c->carNumber.ni;
		} while (c->carNumber.ni > 99999 || c->carNumber.ni < 10000);
	}
	break;
	case 2:
	{
		cout << "Введите слово до 8 символов: ";
		cin.ignore();
		cin.getline(c->carNumber.ns, 9);
	}
	break;
	}
}

car createCar()
{
	car c;
	cout << "Введите модель машины: ";
	cin.ignore();
	getline(cin, c.model);
	cout << "Введите цвет: ";
	getline(cin, c.color);
	createCarNumber(&c);
	return c;
}

void printCar(car c)
{
	cout << "Модель: " << c.model << endl;
	cout << "Цвет: " << c.color << endl;
	cout << "Номер: ";
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
		cout << "------------Машина #" << i + 1 << "-------------" << endl;
		cars[i] = createCar();
	}
	return cars;
}

void printArrayOfCars(car* cars, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "------------Машина #" << i + 1 << "-------------" << endl;
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
	cout << "Введите, что вы хотите изменить: " << endl
		<< "1 - модель" << endl
		<< "2 - цвет" << endl
		<< "3 - номер машины" << endl;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		cout << "Введите новую модель: ";
		cin.ignore();
		getline(cin, changeCar->model);
	}
	break;
	case 2:
	{
		cout << "Введите новый цвет: ";
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
	cout << "Введите количество машин: ";
	cin >> n;
	car* cars = createArrayOfCars(n);
	system("cls");
	int act;
	do
	{
		cout << "Введите: " << endl
			<< "1 - чтобы показать все машини" << endl
			<< "2 - редактировать машину" << endl
			<< "3 - поиск машины по номеру" << endl
			<< "любую друю цифру, чтобы закончить" << endl << endl;
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
				cout << "Введите номер машины в списке  (1-" << n << ") : ";
				cin >> i;
				editCar(i - 1, cars, n);
				cout << "Машина #" << i << " изменена!" << endl;
				cout << "Что бы продолжить изменения введите 1" << endl
					<< "любую другую цифру, чтобы выйти" << endl;
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
				cout << endl << "Машина не найдена !" << endl;
			else
			{
				cout << endl << "------------Машина-------------" << endl;
				printCar(foundCar);
			}
			cout << endl;
		}
		break;
		default:
			cout << "Введены неправильные значения!";
		}
	} while (act >= 1 && act <= 3);
	return 0;
}