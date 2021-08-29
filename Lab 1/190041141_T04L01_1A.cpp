#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long i, j, n = 0;
    long long x = 0, t, inp, sum = 0, b = 0, a = 0;
    map<long long, vector<long long>> mp1;
    vector<pair<long long, long long>> out;
    while (1) //n
    {
        cin >> inp;
        if (inp == 0)
            break;
        mp1[inp].push_back(n++);
    }
    cin >> x;
    for (auto i : mp1) //n
    {
        if (mp1.find(x - i.first) == mp1.end() or i.first * 2 > x)
            continue;

        for (a = 0; a < i.second.size(); a++)
            for (b = i.first * 2 == x ? a + 1 : 0; b < mp1.at(x - i.first).size(); b++)
                out.push_back({i.second[a], mp1.at(x - i.first)[b]});
    }
    if (!out.size())
        cout << "No pair found!" << endl;
    else
    {
        cout << out.size() << " pairs:" << endl;
        for (auto i : out)
            cout << "(worker-"
                 << i.first + 1 << ", worker-" << i.second + 1 << ")" << endl;

        cout << endl;
    }
}

/*
1 5 5 1 1 7 7 -9

    1->{1, 4, 5}

    5-> { 2, 3 }

    7->{6, 7}

1 1 1 1 1 1 1 1
    n *(n - 1)*/