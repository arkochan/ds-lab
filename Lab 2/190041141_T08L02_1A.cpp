#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i, j, n = 0;
    long long x = 0, t, inp, sum = 0;
    cin >> t;
    while (t--)
    {
        stack<long long> st;
        vector<long long> vec;
        while (1)
        {
            cin >> inp;
            if (inp == -1)
                break;
            vec.push_back(inp);
        }
        n = vec.size();
        for (i = 0; i < n; i++)
        {
            if (st.empty())
                st.push(i);
            else if (vec[st.top()] >= vec[i])
            {
                st.push(i);
            }
            else
            {
                // cout << vec[st.top()] << " sould be replaced by" << vec[i] << endl;
                while (!st.empty() and (vec[st.top()] < vec[i]))
                {
                    // cout << vec[st.top()] << " replaced by" << vec[i] << endl;
                    vec[st.top()] = vec[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        while (!st.empty())
        {
            // cout << "setting " << vec[st.top()] << "to -1"
            //      << " " << st.top() << endl;
            vec[st.top()] = -1;

            st.pop();
        }
        for (i = 0; i < n; i++)
            cout << vec[i] << " ";
        cout << endl;
    }
}
