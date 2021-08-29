#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i, j, n;
    long long x = 0, t, inp, sum = 0;
    cin >> n >> x;
    priority_queue<int, vector<int>, > q;
    for (i = 0; i < n; i++)
    {
        cin >> inp;
        q.push(inp);greater<int>
    }
    while (q.top() < x)
    {
        int temp = q.top();
        q.pop();
        int temp2 = q.top();
        q.pop();
        q.push(temp + 2 * q.top());
        sum++;
    }
    cout << sum << endl;
}