#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long i, j, n;
        long long x = 0, inp, go = 1;
        cin >> n;
        long long arr[n];
        for (i = 0; i < n; i++)
            cin >> arr[i];
        stack<long long> side;
        i = 0;

        while (i < n)
        {
            if (arr[i] == go)
            {
                go++;
                i++;
                continue;
            }
            if (side.size())
            {
                if (go == side.top())
                {
                    side.pop();
                    go++;
                    continue;
                }
                if (arr[i] < side.top())
                {
                    side.push(arr[i++]);
                    continue;
                }
                if (arr[i] > side.top())
                {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            else
                side.push(arr[i++]);
        }
        cout << "YES" << endl;
    }
}
