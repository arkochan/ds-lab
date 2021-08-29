#include <bits/stdc++.h>
#define ll long long

using namespace std;
class queuecls
{
    ll *arr;
    ll front = 0;
    ll back = 0;
    ll size;
    ll count = 0;

public:
    queuecls(long long n = 128)
    {
        size = n;
        arr = (ll *)malloc(sizeof(ll) * size);
    }
    void enque(ll n)
    {
        if (count == size)
        {
            cout << "FULL" << endl;
            return;
        }
        arr[front] = n;
        front = (front + 1) % size;
        count++;
    }
    long long deque()
    {
        if (isempty())
            return -1;
        long long temp = back;
        back = (back + 1) % size;
        count--;
        return arr[temp];
    }
    bool isfull()
    {
        return count == size;
    }
    bool isempty()
    {
        return front == back;
    }
};
int main()
{
    long long i, j, n;
    long long x = 0, t, inp, sum = 0;
    cin >> n;
}
