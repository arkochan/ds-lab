#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i, j, n;
    long long x = 0, t, inp, sum = 0;
    int val;
    int k = 2;
    for (int i = 0; i < 128; i++)
    {
        val = i;
        val = val & (1 | 4 | 8 | 16 | 64);
        cout << val << endl;
    }
}
