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
    cout << "Введите компанию: ";
    getline(cin, n.Company);

    cout << "Модель: ";
    getline(cin, n.Model);

    cout << "Цвет: ";
    getline(cin, n.color);

    cout << "Тип коробки передач: ";
    getline(cin, n.type_of_trans);

    cout << "Год: ";
    cin >> n.year;

    cout << "Длина: ";
    cin >> n.lenth;

    cout << "Клиренс: ";
    cin >> n.klirens;

    cout << "Объем двигателя: ";
    cin >> n.V_engine;

    cout << "Мощность двигателя: ";
    cin >> n.power_engine;

    cout << "Диаметр колес: ";
    cin >> n.D_wheel;

    return n;
}

car* createCarsArray(int size)
{
    system("cls");
    car* cars = new car[size];
    for (int i = 0; i < size; i++)
    {
        cout << "-------------(Машина #" << i + 1 << ")-------------" << endl;
        cars[i] = createCar();
        cout << endl;
    }
    return cars;
}

void printCar(car n)
{
    cout << "Компания: " << n.Company << endl;
    cout << "Модель: " << n.Model << endl;
    cout << "Цвет: " << n.color << endl;
    cout << "Год: " << n.year << endl;
    cout << "Тип коробки передач: " << n.type_of_trans << endl;
    cout << "Длина: " << n.lenth << endl;
    cout << "Клиренс: " << n.klirens << endl;
    cout << "Объем двигателя: " << n.V_engine << endl;
    cout << "Мощность двигателя: " << n.power_engine << endl;
    cout << "Диаметр колес: " << n.D_wheel << endl;
}

void printCarsArray(car* cars, int size)
{
    system("cls");
    for (size_t i = 0; i < size; i++)
    {
        cout << "-------------(Машина #" << i + 1 << ")-------------" << endl;
        printCar(cars[i]);
        cout << endl;
    }
}


void searchForCompany(string searchСompany, car* cars, int size)
{
    system("cls");
    int c = 0;
    for (int i = 0; i < size; i++)
    {
        if (searchСompany == cars[i].Company)
        {
            cout << "-------------(Машина #" << i + 1 << ")-------------" << endl;
            printCar(cars[i]);
            cout << endl;
            c++;
        }
    }
    if (c == 0)
    {
        cout << "Не найдено!" << endl;
    }
}
int main()
{
    int size;
    setlocale(0, "");
    cout << "Введите колличество машин: ";
    cin >> size;
    car* c = createCarsArray(size);
    printCarsArray(c, size);
    string str;
    cin.ignore();
    cout << "Введите компанию машины для поиска: ";
    getline(cin, str);
    searchForCompany(str, c, size);
    return 0;
}