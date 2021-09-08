#include "bits/stdc++.h"
#define prime 7
using namespace std;
class Hash
{
    int *arr;
    int size;
    int n;
    int c;

public:
    Hash(int size, int c)
    {
        n = 0;
        this->size = size;
        arr = new int[size];
        for (auto i = 0; i, size; i++)
        {
            arr[i] = -2;
        }
    }
    int hash(int x)
    {
        return x % size;
    }

public:
    void insert(int key)
    {
        int i = 1, index = hash(key);
        while (arr[index % size] < -1)
        {
            cout << "collision at " << index % size << endl;
            if (c == 1)
                index + i;
            else if (c == 2)
                index += i * i;
            else if (c == 3)
                index = index + (prime - key % prime) * i;
            if (i++ == 7)
            {
                cout << "Input Abandoned" << endl;
                return;
            }
        }
        arr[index % size] = key;
        n++;
        cout << "Inserted : Index-"
             << index % size << "(L.F = " << double(n) / double(size) << ")"
             << endl;
    }
};
int main()
{
    long long i, j, n;
    long long x = 0, t, q, inp, sum = 0;
    cin >> t >> n >> q;
    Hash h(n, t);
    while (q--)
    {
        cin >> n;
        h.insert(n);
    }
}
