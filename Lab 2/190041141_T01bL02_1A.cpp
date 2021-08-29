#include <iostream>
#include <stack>
using namespace std;
void printrec(stack<long long> stacktemp)
{
    if (stacktemp.size() == 0)
        return;

    long long temp_out = stacktemp.top();
    stacktemp.pop();
    printrec(stacktemp);
    cout << temp_out << " ";
}
void print(stack<long long> stackA)
{
    stack<long long> stacktemp = stackA;

    printrec(stacktemp);
    cout << endl;
}

main()
{
    long long inp, t;
    cin >> inp;
    cin >> t;
    stack<long long> stackA;
    while (t--)
    {
        cin >> inp;
        switch (inp)
        {
        case 1:
            cin >> inp;
            stackA.push(inp);
            cout << "size= " << stackA.size() << " items: ";
            print(stackA);
            break;
        case 2:
            if (stackA.size() > 0)
                stackA.pop();
            cout << "size= " << stackA.size() << " items: ";
            print(stackA);
            break;

        default:
            cout << "INVALID OPTION";
            break;
        }
    }
}
