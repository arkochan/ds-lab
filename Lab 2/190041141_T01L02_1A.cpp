#include <iostream>

using namespace std;

class stack
{
public:
    long long MAX_SIZE;
    stack(long long n)
    {
        MAX_SIZE = n;
        arr = (long long *)malloc(sizeof(long long) * MAX_SIZE);
    }
    void insert(long long input)
    {
        if (MAX_SIZE - 1 == ind)
            cout << "Overflow" << endl;
        else
            arr[++ind] = input;
    }
    long long top()
    {
        return arr[ind];
    }
    void pop()
    {
        if (ind > -1)
            ind--;
    }
    void print()
    {
        if (ind == -1)
            cout << "NULL";
        else
            for (long long i = 0; i <= ind; i++)
            {
                cout << arr[i] << " ";
            }
        cout << endl;
    }
    long long size()
    {
        return ind + 1;
    }

private:
    long long *arr;
    long long ind = -1;
};

main()
{
    long long inp, t;
    cin >> inp;
    cin >> t;
    stack stackA(inp);
    while (t--)
    {
        cin >> inp;
        switch (inp)
        {
        case 1:
            cin >> inp;
            stackA.insert(inp);
            cout << "size= " << stackA.size() << " items: ";
            stackA.print();
            break;
        case 2:
            stackA.pop();
            cout << "size= " << stackA.size() << " items: ";
            stackA.print();
            break;

        default:
            cout << "INVALID OPTION";
            break;
        }
    }
}


