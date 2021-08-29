#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i = 0, j = 0, n = 0, inp, max = 0, sum = 0;
    vector<long long> vecin;
    vector<pair<long long, long long>> vec(9);
    while (1)
    {
        cin >> inp;
        if (inp < 1 or inp > 9)
            break;
        vecin.push_back(inp);
    } //
    3 11 2 2

        for (i = 0; i < vecin.size(); i++)
    {
        vec[vecin[i] - 1].first = vecin[i] - 1;
        vec[vecin[i] - 1].second++;
    }
    sort(vec.begin(), vec.end(),
         [](pair<long long, long long> a, pair<long long, long long> b) { return a.second > b.second; });

    for (auto i : vec)
    {
        if (i.second)
            cout << i.first + 1 << " appears " << i.second << " times." << endl;
    }
}
