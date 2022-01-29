#include <iostream>
#include <ctime>
#include <string.h>
#include <string>

using namespace std;

struct car {
    string Company;
    string Model;
    string color;
    string type_of_trans;
    double lenth;
    double klirens;
    float V_engine;
    float power_engine;
    double D_wheel;
    short year;
};

car createCar()
{
    car n;
    cin.ignore();
    cout << "������� ��������: ";
    getline(cin, n.Company);

    cout << "������: ";
    getline(cin, n.Model);

    cout << "����: ";
    getline(cin, n.color);

    cout << "��� ������� �������: ";
    getline(cin, n.type_of_trans);

    cout << "���: ";
    cin >> n.year;

    cout << "�����: ";
    cin >> n.lenth;

    cout << "�������: ";
    cin >> n.klirens;

    cout << "����� ���������: ";
    cin >> n.V_engine;

    cout << "�������� ���������: ";
    cin >> n.power_engine;

    cout << "������� �����: ";
    cin >> n.D_wheel;

    return n;
}

car* createCarsArray(int size)
{
    system("cls");
    car* cars = new car[size];
    for (int i = 0; i < size; i++)
    {
        cout << "-------------(������ #" << i + 1 << ")-------------" << endl;
        cars[i] = createCar();
        cout << endl;
    }
    return cars;
}

void printCar(car n)
{
    cout << "��������: " << n.Company << endl;
    cout << "������: " << n.Model << endl;
    cout << "����: " << n.color << endl;
    cout << "���: " << n.year << endl;
    cout << "��� ������� �������: " << n.type_of_trans << endl;
    cout << "�����: " << n.lenth << endl;
    cout << "�������: " << n.klirens << endl;
    cout << "����� ���������: " << n.V_engine << endl;
    cout << "�������� ���������: " << n.power_engine << endl;
    cout << "������� �����: " << n.D_wheel << endl;
}

void printCarsArray(car* cars, int size)
{
    system("cls");
    for (size_t i = 0; i < size; i++)
    {
        cout << "-------------(������ #" << i + 1 << ")-------------" << endl;
        printCar(cars[i]);
        cout << endl;
    }
}


void searchForCompany(string search�ompany, car* cars, int size)
{
    system("cls");
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        if (search�ompany == cars[i].Company)
        {
            cout << "-------------(������ #" << i + 1 << ")-------------" << endl;
            printCar(cars[i]);
            cout << endl;
            c++;
        }
    }
    if (c == 0)
    {
        cout << "�� �������!" << endl;
    }
}
int main()
{
    int size;
    setlocale(0, "");
    cout << "������� ����������� �����: ";
    cin >> size;
    car* c = createCarsArray(size);
    printCarsArray(c, size);
    string str;
    cin.ignore();
    cout << "������� �������� ������ ��� ������: ";
    getline(cin, str);
    searchForCompany(str, c, size);
    return 0;
}