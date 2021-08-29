#include <bits/stdc++.h>
using namespace std;
//0 1 2 3 4

long long binarySearch_rec(long long arr[], long long l, long long r, long long x)
{
    if (r >= l)
    {
        long long m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            return binarySearch_rec(arr, m + 1, r, x);
        else
            return binarySearch_rec(arr, l, m - 1, x);
    }
    return -1;
}
long long binarySearch_ite(long long arr[], long long l, long long r, long long x)
{
    while (l <= r)
    {
        long long m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}
int main()
{
    long long i, j, n = 0;
    long long x = 0, t, inp, sum = 0;
    long long arr[1024];
    while (1)
    {
        cin >> inp;
        if (inp < 0)
            break;
        arr[n++] = inp;
    }
    cin >> x;
    cout << binarySearch_ite(arr, 0, n - 1, x) << " (using iteration)" << endl;
    cout << binarySearch_rec(arr, 0, n - 1, x) << " (using recursion)" << endl;
}