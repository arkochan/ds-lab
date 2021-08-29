#include <bits/stdc++.h>
using namespace std;
char opposite_par(char x)
{
    char par[']' - '(' + 1] = {};
    par['(' - '('] = ')';
    par[')' - '('] = '(';
    par['{' - '('] = '}';
    par['}' - '('] = '{';
    par['[' - '('] = ']';
    par[']' - '('] = '[';
    return par[x - '('];
}
bool isopening(char x)
{
    return x == '(' or x == '{' or x == '[';
}
int main()
{
    long long i, j, n;
    long long x = 0, t, sum = 0;
    cin >> t;
    string inp;

    for (i = 0; i < n; i++)
        while (t--)
        {
            bool vul = 0;
            stack<char> st;
            cin >> inp;
            n = inp.length();
            for (i = 0; i < n; i++)
            {
                if (opposite_par(inp[i]))
                {
                    if (isopening(inp[i]))
                        st.push(inp[i]);
                    else
                    {
                        if (st.empty())
                        {
                            cout << "No" << endl;
                            vul = 1;
                            break;
                        }
                        if ((opposite_par(inp[i]) == st.top()))
                            st.pop();
                        else
                        {
                            cout << "No" << endl;
                            vul = 1;
                            break;
                        }
                    }
                }
            }
            if (!vul and st.empty())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
}
