#include <iostream>
#include "headers/dll.h"
using namespace std;

int main()
{
    dll myList = dll();
    string s;
    do
    {
        cout << "Please enter the operation :\n 1. enter <value> : \n 2. delete\n 3. print\n";
        cin >> s;

        if (s == "enter")
        {
            int value;
            cin >> value;
            myList.insert(value);
        }
        else if (s == "delete")
            myList.remove();
        else if (s == "print")
            cout << myList;
        else
            cout << "invalid input! \n";

        cout << "Do you want to  make more operations ? (y/n) \n";
        cin >> s;
    } while (s == "y");
}
