#include "bits/stdc++.h"

using namespace std;
typedef node *pointer;
class node
{
    pointer arr[26];
    bool endflag;
};
class trie
{
    long long trail(pointer x)
    {
        long long count = 0;
        for (int i = 0; i < 26; i++)
        {
            pointer ite = (*x).arr[i];
            while (ite)
            {
                ite = ite->next
            }
        }
    }
};
int main()
{
    long long i, j, n;
    long long x = 0, t, inp, sum = 0;
    cin >> n;
}
