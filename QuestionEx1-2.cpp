#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

void Test( int& intVal, double doubleVal ) {

intVal = intVal * 2;
doubleVal = double (intVal) + 3.5;

}

void test2(bool a, bool b, bool c, bool d) {
    if (a && b)
        if (!c || !d)
            cout << "un" << endl;
        else if (d)
            cout << "deux" << endl;
        else
            cout << "trois" << endl;
    else if (c != d)
        cout << "quatre" << endl;
    else if (c)
        cout << "cinq" << endl;
    else
        cout << "six" << endl;

}