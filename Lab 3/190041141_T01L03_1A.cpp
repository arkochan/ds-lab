#include <bits/stdc++.h>

using namespace std;

class queuecls
{
    long long *arr;
    long long front = 0;
    long long back = 0;
    long long size;

public:
    queuecls(long long n = 128)
    {
        size = n;
        arr = (long long *)malloc(sizeof(long long) * size);
    }
    void enque(long long n)
    {
        arr[front++] = n;
    }
    long long deque()
    {
        return arr[back++];
    }
    bool isMAX()
    {
        return front + 1 == size;
    }
    bool isempty()
    {
        return front == back;
    }
};
int main()
{
    long long n;
    cin >> n;
    queuecls q1(n);
}
