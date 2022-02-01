#include <iostream>
using namespace std;

int main()
{
    const int s = 10;
    double m[s];
    cout << "Enter 10 student marks: " << endl;
    for (int i = 0; i < s; i++)
    {
        cout << i + 1 << ") ";
        cin >> m[i];
    }
    system("cls");
    int n;
    do {
        cout << "Enter action number: " << endl
            << "1 - Print marks" << endl
            << "2 - Retake the exam" << endl
            << "3 - Is there a scholarship? " << endl
            << "4 - Exit" << endl;
        cin >> n;
        system("cls");
        switch (n)
        {
        case 1:
            cout << endl << "Your marks: " << endl;
            for (int i = 0; i < s; i++)
                cout << m[i] << " ";
            cout << endl << endl;
            break;
        case 2:
            int ind, newMark;
            cout << "Enter the mark number (1 to 10)" << endl;
            cin >> ind;
            cout << "Old mark:  " << m[ind - 1] << endl;
            cout << "Enter new mark:" << endl;
            cin >> newMark;
            m[ind - 1] = newMark;
            break;
        case 3:
            int sum = 0;
            for (int i = 0; i < s; i++)
                sum += m[i];
            cout << endl;
            if ((double)sum / s >= 10.7) cout << "You have a scholarship!" << endl;
            else cout << "You do not have a scholarship ((" << endl;
            cout << "Your aver mark:" << (double)sum / s << endl << endl;
            break;
        }
    } while (n != 4);
    return 0;
}