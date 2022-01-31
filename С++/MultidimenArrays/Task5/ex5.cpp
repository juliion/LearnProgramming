#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string.h>
using namespace std;

char** pushContact(char** contacts, int* col, char* name, char* phNumber)
{
    char** newCont = new char* [*col + 2];
    for (int i = 0; i < *col; i++)
    {
        newCont[i] = new char[strlen(contacts[i])];
        strcpy(newCont[i], contacts[i]);
    }
    delete[] contacts;

    newCont[*col] = new char[strlen(name)];
    strcpy(newCont[*col], name);
    newCont[*col + 1] = new char[strlen(phNumber)];
    strcpy(newCont[*col + 1], phNumber);
    *col += 2;

    return newCont;
}

bool contactInArray(char** contacts, int col, char* name, char* phNumber)
{
    bool found = false;
    for (int i = 0; i < col; i++)
    {
        if (name != nullptr && phNumber != nullptr)
            found = (strcmp(contacts[i], name) == 0) && (strcmp(contacts[i + 1], phNumber) == 0);
        else if (name != nullptr)
            found = strcmp(contacts[i], name) == 0;
        else if (phNumber != nullptr)
            found = strcmp(contacts[i], phNumber) == 0;

        if (found)
            break;
    }
    return found;
}

void search(char** contacts, int col, char* data)
{
    cout << endl;
    for (int i = 0; i < col; i++)
    {
        if (strcmp(contacts[i], data) == 0)
        {
            int n = i % 2 == 0 ? i : i - 1;
            cout << "Ваш контакт:" << endl
                << "----------------------------" << endl
                << "Имя: " << contacts[n] << endl
                << "Номер телефона: " << contacts[n + 1] << endl
                << "----------------------------" << endl;
        }
    }
    cout << endl;
}

char** changeContact(char** contacts, int col, char* name, char* phNumber, char* newName, char* newPhNum)
{
    char** newCont = new char* [col];
    for (int i = 0; i < col - 1; i++)
    {
        if (strcmp(contacts[i], name) != 0 && strcmp(contacts[i + 1], phNumber) != 0)
        {
            newCont[i] = new char[strlen(contacts[i])];
            strcpy(newCont[i], contacts[i]);
            newCont[i + 1] = new char[strlen(contacts[i])];
            strcpy(newCont[i + 1], contacts[i + 1]);
        }
        else
        {
            newCont[i] = new char[strlen(newName)];
            strcpy(newCont[i], newName);
            newCont[i + 1] = new char[strlen(newPhNum)];
            strcpy(newCont[i + 1], newPhNum);
            i++;
        }
    }
    delete[] contacts;
    return newCont;
}

void printContacts(char** contacts, int col)
{
    cout << endl << endl;
    cout << "*КОНТАКТЫ*" << endl;
    if (col == 0)
        cout << "Список пуст!";
    for (int i = 0; i < col; i++)
    {
        if (i % 2 == 0)
        {
            cout << "----------------------------" << endl;
            cout << "Имя: " << contacts[i] << endl;
        }
        else
        {
            cout << "Номер телефона: " << contacts[i] << endl;
            cout << "----------------------------" << endl;
        }
    }
    cout << endl << endl;
}

int main()
{
    setlocale(0, "");
    int col = 0;
    char** contacts = new char* [col];
    int act;
    do
    {
        cout << "Введите: " << endl
            << "1 - чтобы добавить контакт" << endl
            << "2 - найти контакт по имени" << endl
            << "3 - найти контакт по номеру телефона" << endl
            << "4 - именить контакт" << endl
            << "5 - показать все контакты" << endl
            << "любую друю цифру, чтобы закончить" << endl << endl;
        cin >> act;
        switch (act)
        {
        case 1:
        {
            char name[256];
            char phNumber[256];
            cout << endl;
            cout << "Введите имя:" << endl;
            cin.ignore();
            cin.getline(name, 256);
            cout << "номер телефона:" << endl;
            cin.getline(phNumber, 256);
            contacts = pushContact(contacts, &col, name, phNumber);
            cout << "Контакт добавлен!" << endl << endl;
        }
        break;
        case 2:
        {
            char name[256];
            cout << "Введите имя:" << endl;
            cin.ignore();
            cin.getline(name, 256);
            if (!contactInArray(contacts, col, name, nullptr))
                cout << "Контакт не найден!" << endl << endl;
            else
                search(contacts, col, name);
        }
        break;
        case 3:
        {
            char phNumber[256];
            cout << "Введите номер телефона:" << endl;
            cin.ignore();
            cin.getline(phNumber, 256);
            if (!contactInArray(contacts, col, nullptr, phNumber))
                cout << "Контакт не найден!" << endl << endl;
            else
                search(contacts, col, phNumber);
        }
        break;
        case 4:
        {
            char name[256];
            char phNumber[256];
            char newName[256];
            char newPhNum[256];
            cout << endl;
            cout << "Введите имя контакта, который нужно изменить:" << endl;
            cin.ignore();
            cin.getline(name, 256);
            cout << "Введите его номер:" << endl;
            cin.getline(phNumber, 256);
            if (!contactInArray(contacts, col, name, phNumber))
                cout << "Контакт не найден!" << endl << endl;
            else
            {
                cout << "Введите новое имя:" << endl;
                cin.getline(newName, 256);
                cout << "Введите новый номер телефона:" << endl;
                cin.getline(newPhNum, 256);
                contacts = changeContact(contacts, col, name, phNumber, newName, newPhNum);
                cout << "Контакт изменен!" << endl;
            }
        }
        break;
        case 5:
            printContacts(contacts, col);
            break;
        }

    } while (act >= 1 && act <= 5);

    for (int i = 0; i < col; i++)
        delete[] contacts[i];
    delete[] contacts;

    return 0;
}