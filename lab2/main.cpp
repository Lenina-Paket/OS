#include <iostream>
#include "thirteen.h"

using namespace std;

int main() {
    Thirteen empt;
    cout << empt << "There is must be nothing!" << endl;

    Thirteen a(5, 10);
    cout << a << endl;
    string str;
    cin >> str;
    Thirteen b = {4, 10, 12};
    Thirteen c = str;
    if (b != c) cout << b << " and " << c << " are not equal and their sum = " << b + c << endl;
    
    Thirteen d = string("000000000004");
    Thirteen f = string("01");
    cout << d << endl;
    cout << f << endl;
    cout << d - f << endl;
    cout << d + f << endl;

return 0;
}