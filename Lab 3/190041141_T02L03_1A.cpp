#include <bits/stdc++.h>
#define ll long long
using namespace std;
class heapcls
{
    ll *arr;
    ll size;

public:
    heapcls(ll n, ll *arrin)
    {
        size = n;
        arr = arrin;
    }
    void heapify(ll n)
    {
        ll largest = n;
        ll leftChild = 2 * n + 1;
        ll rightChild = 2 * n + 2;
        if (leftChild < size && arr[leftChild] > arr[n])
            largest = leftChild;
        if (rightChild <= size && arr[rightChild] > arr[n])
            largest = rightChild;
        if (largest != n)
        {
            cout << n << " " << largest << endl;
            swap(arr[n], arr[largest]);
            heapify(largest);
        }
        return;
    }
    void heap_sort()
    {
        if (size == 1)
            return;
        swap(arr[0], arr[size]);
        size--;
        heapify(0);
        heap_sort();
        return;
    }
    void build_max_heap()
    {
        for (ll i = size / 2; i >= 0; i--)
            heapify(i);
        heapify(0);
    }
};

int main()
{
    long long i, j, n;
    long long x = 0, t, inp, sum = 0;
    ll arr[] = {5, 6, 4, 3, 1, 61, 43, 15, 33, 53};
    heapcls heap1(10, arr);
    heap1.build_max_heap();

    for (i = 0; i < 10; i++)
        cout << arr[i] << " ";
}
