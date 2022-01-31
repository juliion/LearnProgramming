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
            cout << "��� �������:" << endl
                << "----------------------------" << endl
                << "���: " << contacts[n] << endl
                << "����� ��������: " << contacts[n + 1] << endl
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
    cout << "*��������*" << endl;
    if (col == 0)
        cout << "������ ����!";
    for (int i = 0; i < col; i++)
    {
        if (i % 2 == 0)
        {
            cout << "----------------------------" << endl;
            cout << "���: " << contacts[i] << endl;
        }
        else
        {
            cout << "����� ��������: " << contacts[i] << endl;
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
        cout << "�������: " << endl
            << "1 - ����� �������� �������" << endl
            << "2 - ����� ������� �� �����" << endl
            << "3 - ����� ������� �� ������ ��������" << endl
            << "4 - ������� �������" << endl
            << "5 - �������� ��� ��������" << endl
            << "����� ���� �����, ����� ���������" << endl << endl;
        cin >> act;
        switch (act)
        {
        case 1:
        {
            char name[256];
            char phNumber[256];
            cout << endl;
            cout << "������� ���:" << endl;
            cin.ignore();
            cin.getline(name, 256);
            cout << "����� ��������:" << endl;
            cin.getline(phNumber, 256);
            contacts = pushContact(contacts, &col, name, phNumber);
            cout << "������� ��������!" << endl << endl;
        }
        break;
        case 2:
        {
            char name[256];
            cout << "������� ���:" << endl;
            cin.ignore();
            cin.getline(name, 256);
            if (!contactInArray(contacts, col, name, nullptr))
                cout << "������� �� ������!" << endl << endl;
            else
                search(contacts, col, name);
        }
        break;
        case 3:
        {
            char phNumber[256];
            cout << "������� ����� ��������:" << endl;
            cin.ignore();
            cin.getline(phNumber, 256);
            if (!contactInArray(contacts, col, nullptr, phNumber))
                cout << "������� �� ������!" << endl << endl;
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
            cout << "������� ��� ��������, ������� ����� ��������:" << endl;
            cin.ignore();
            cin.getline(name, 256);
            cout << "������� ��� �����:" << endl;
            cin.getline(phNumber, 256);
            if (!contactInArray(contacts, col, name, phNumber))
                cout << "������� �� ������!" << endl << endl;
            else
            {
                cout << "������� ����� ���:" << endl;
                cin.getline(newName, 256);
                cout << "������� ����� ����� ��������:" << endl;
                cin.getline(newPhNum, 256);
                contacts = changeContact(contacts, col, name, phNumber, newName, newPhNum);
                cout << "������� �������!" << endl;
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