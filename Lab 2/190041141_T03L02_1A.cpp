#include <bits/stdc++.h>

using namespace std;
long long operate(long long a, char op, long long b)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        break;
    }
    return 0;
}
int main()
{
    stack<long long> stack;
    long long i, j, n;
    long long x = 0, t, sum = 0, temp1, temp2;
    string inp;

    cin >> t;
    while (t--)
    {
        cin >> inp;
        for (i = 0; i < inp.length(); i++)
        {
            if (isdigit(inp[i]))
            {
                stack.push(inp[i] - '0');
            }

            else
            {
                temp1 = stack.top();
                stack.pop();
                temp2 = stack.top();
                stack.pop();

                stack.push(operate(temp2, inp[i], temp1));
            }
        }
        cout << stack.top() << endl;
    }
}