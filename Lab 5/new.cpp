// CPP program to illustrate bool
// data type in C++
#include <iostream>
using namespace std;

int main()
{
    int x1 = 10, x2 = 20, m = 2;
    bool b1, b2 = 50;
    b1 = x1 == x2; // false

    b2 = x1 < x2; // true

    bool b3 = true;

    int x3 = false + 5 * m - b3;
    cout << sizeof(b2);

    return 0;
}
