#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i, j, n;
    long long x = 0, t, inp, sum = 0;
    stack<long long> st1, st2;
    cin >> n;
    while (1)
    {
        cin >> inp;
        switch (inp)
        {
        case 1:
            cin >> inp;
            while (!st1.empty())
            {
                st2.push(st1.top());
                st1.pop();
            }
            st1.push(inp);
            while (!st2.empty())
            {
                st1.push(st2.top());
                st2.pop();
            }
            break;
        case 2:
            if (st1.empty())
            {
                cout << "Q is Empty";
                exit(0);
            }
            int x = st1.top();
            st1.pop();
        }
    }
