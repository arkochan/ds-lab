#include <bits/stdc++.h>

using namespace std;

void enq(long long arr[], long long &front, long long &back, long long size, long long data)
{
    if ((front + 1) % size + 1 == back)
    {
        cout << "full" << endl;
        cout << front << endl;
        cout << back << endl;
        return;
    } // o
    else
    {
        cout << "g2" << endl;
        arr[front] = data;
        front = (front + 1) % size;
    }
}
void deq(long long arr[], long long &front, long long &back, long long size)
{
    if (front == back)
    {
        cout << "g3" << endl;
        cout << "empty";
        return;
    }

    else
        cout << "g4" << endl;
    {
        back = (back + 1) % size;
    }
}

int main()
{
    long long i, j, n;
    long long x = 0, t, inp, sum = 0;
    n = 3;
    long long arr[n];
    long long front = 0, back = 0;

    enq(arr, front, back, 3, x++);
    enq(arr, front, back, 3, x++);
    enq(arr, front, back, 3, x++);
    enq(arr, front, back, 3, x++);
    enq(arr, front, back, 3, x++);
    enq(arr, front, back, 3, x++);

    for (auto enn : arr)
        cout << enn << " ";
}
//wrong what????
