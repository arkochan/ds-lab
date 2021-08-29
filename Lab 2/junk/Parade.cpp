#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, temp, count = 1, i, no = 0;
        stack<long long int> s;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> temp;
            if (temp == count)
            {
                count++;
            }
            else
            {
                if (s.empty())
                {
                    s.push(temp);
                }
                else
                {
                    if (s.top() == count)
                    {
                        s.pop();
                        count++;
                    }
                    else if (temp < s.top())
                    {
                        s.push(temp);
                    }
                    else
                    {
                        no = 1;
                        break;
                    }
                }
            }
        }
        if (no)
            cout << "no" << endl;
        else
            cout << "yes" << endl;
    }
    return 0;
}