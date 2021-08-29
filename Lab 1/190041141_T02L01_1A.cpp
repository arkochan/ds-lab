#include <bits/stdc++.h>
using namespace std;
long long factorial_loop(long long n)
{
    long long fac = 1;
    while (n)
        fac *= n--;
    return fac;
}
long long factorial_rec(long long n)
{
    if (!n)
        return 1;
    else
        return factorial_rec(n - 1) * n;
}
int main()
{
    long long n;
    cin >> n;
    cout << factorial_loop(n) << " (using iteration)" << endl;
    cout << factorial_rec(n) << " (using recursion)" << endl;
}
