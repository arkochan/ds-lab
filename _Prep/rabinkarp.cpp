#include <bits/stdc++.h>

using namespace std;

class rabin
{
public:
    long long static prime;
    static long long hash(string str)
    {
        long long primepow = 1;
        long long hashvalue = 0;
        for (long long i = 0; i < str.length(); i++)
        {
            hashvalue += str[i] * primepow;
            primepow *= prime;
        }
        return hashvalue;
    }
    long long static r_find(string x, string y)
    {
        long long x_size = x.length();
        long long y_size = y.length();
        long long r_hash = hash(x.substr(0, y_size));
        long long y_hash = hash(y);
        long long primepow = pow(prime, y_size - 1);
        for (long long i = 0; i < x_size - y_size; i++)
        {
            if (r_hash == y_hash)
            {
                if (x.substr(i, y_size) == y)
                {
                    cout << "found at " << i << endl;
                    return i;
                }
            }

            r_hash -= x[i];
            r_hash /= prime;
            r_hash += x[i + y_size] * primepow;
        }
        return -1;
    }
};
long long rabin::prime = 3;
int main()
{
    string str1 = "killuachan 22 1 arko hahahah";
    string str2 = "arko";
    cout << rabin::r_find(str1, str2) << endl;
}
