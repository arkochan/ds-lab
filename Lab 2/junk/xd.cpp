#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i, j, n;
    long long x = 0, t = 24, inp, sum = 0;
    string ni[] = {"1234", "2134", "3124", "1324", "2314", "3214", "3241", "2341", "4321", "3421", "2431", "4231", "4132", "1432", "3412", "4312", "1342", "3142", "2143", "1243", "4213", "2413", "1423", "4123"};

    for (j = 0; j < 24; j++)
    {
        cout << 4 << endl;
        // cout << j + 1 << " : ";
        for (i = 0; i < 4; i++)
            cout << ni[j][i] << " ";
        cout << endl;
    }
}
