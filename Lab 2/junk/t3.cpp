#include <bits/stdc++.h>
using namespace std;

class car
{
public:
    car(int x = 0) : a(x)
    {
    }

    int a;
};

main()
{
    car heehh;
    car pewpew(6);
    cout << heehh.a << endl;
    cout << pewpew.a << endl;
}

int myFunc(int a, int b = 0)
{
    //code
}

myFunc(5, 10);

myFunc(5);

void swap(int &x, int &y)
{
    int temp;
    temp = x; /* save the value at address x */
    x = y;    /* put y into x */
    y = temp; /* put x into y */
}

int main()
{
    // local variable declaration:
    int a = 100;
    int b = 200;

    /* calling a function to swap the values using variable reference.*/
    swap(a, b);
    //Now
    //a = 200
    //b = 100
    return 0;
}