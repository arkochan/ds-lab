#include <bits/stdc++.h>

using namespace std;
bool isopening(char x)
{
    return x == '(' or x == '{' or x == '[';
}

int main()
{
    long long i, j, opening = 0;
    long long x = 0, t, sum = 0;
    stack<char> st;
    string inp;
    cin >> inp;
    for (i = 0; i < inp.length(); i++)
    {
        if (isopening(inp[i]))
            st.push(inp[i]);
        else if (!st.empty())
            st.pop();
        else
            opening++;
    }
    cout << st.size() + opening;
}
