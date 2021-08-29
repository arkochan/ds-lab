#include <bits/stdc++.h>

using namespace std;
bool isop(char x)
{
    return x == '^' or x == '/' or x == '*' or x == '-' or x == '+';
}
int main()
{
    map<char, int> prec;
    prec['+'] = 1;
    prec['-'] = 2;
    prec['*'] = 3;
    prec['/'] = 4;
    prec['^'] = 5;
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        int i;
        char topTemp, temp;
        stack<char> st;
        vector<char> vec;
        for (i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                st.push(s[i]);
            else if ((isalpha(s[i])))
                vec.push_back(s[i]);
            else if (isop(s[i]))
            {
                topTemp = st.top();
                if (isop(topTemp))
                {

                    if (prec[topTemp] <= prec[s[i]])
                    {
                        st.push(s[i]);
                    }
                    else
                    {
                        vec.push_back(topTemp);
                        st.pop();
                        while (st.top() != '(')
                        {
                            temp = st.top();
                            if (prec[topTemp] <= prec[s[i]])
                            {
                                vec.push_back(temp);
                                st.pop();
                            }
                            else
                                break;
                        }
                        st.push(s[i]);
                    }
                }
                else
                    st.push(s[i]);
            }
            else if (s[i] == ')')

                while (st.top() != '(')
                {
                    temp = st.top();
                    vec.push_back(temp);
                    st.pop();
                }
            st.pop();
        }
        for (i = 0; i < vec.size(); i++)
        {
            cout << vec[i];
        }
        cout << endl;
    }
    return 0;
}
