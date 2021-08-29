#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i, j, n;
    long long x = 0, t, sum = 0;
    cin >> t;
    string inp;
    stack<char> stackA;
    while (t--)
    {
        cin >> inp;
        for (i = 0; i < inp.length(); i++)
            stackA.push(inp[i]);
        while (stackA.size())
        {
            cout << stackA.top();
            stackA.pop();
        }
        cout << endl;
    }
}
