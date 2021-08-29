#include <bits/stdc++.h>

using namespace std;
class heapcls
{
    long long *arr, size;

public:
    heapcls(long long arr[], long long size) : arr(arr), size(size)
    {
    }
    void heapify(long long n)
    {
        long long left, right;
        long long smallest = n;
        left = 2 * n + 1;
        right = (2 * n) + 2;
        if (left < size && arr[n] > arr[left])
            smallest = left;
        if (right < size && arr[smallest] > arr[right])
            smallest = right;
        if (smallest != n)
        {
            swap(arr[n], arr[smallest]);
            heapify(smallest);
        }
        return;
    }
    void build_min_heap()
    {
        for (long long i = size / 2; i > 0; i--)
            heapify(i);
        return;
    }
    void minimum()
    {
        cout << arr[0] << endl;
        return;
    }
    void extract_min()
    {
        if (size == 0)
        {
            cout << "underflow";
            return;
        }
        swap(arr[1], arr[size]);
        size--;
        heapify(1);
    }
    void heapify_up(long long n)
    {
        if (n == 1)
            return;
        long long parent = n / 2;
        if (arr[n] < arr[parent])
        {
            swap(arr[n], arr[parent]);
            heapify_up(parent);
        }
        return;
    }
    void insert(long long x)
    {
        size++;
        arr[size] = x;
        heapify_up(size);
    }
    void decrease_key(long long index, long long key)
    {
        if (arr[index] > key)
        {
            arr[index] = key;
            heapify_up(index);
        }
        return;
    }
    void increase_key(long long index, long long key)
    {
        if (arr[index] < key)
        {
            arr[index] = key;
            heapify(index);
        }
        return;
    }
    void print()
    {
        for (long long i = 1; i <= size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main()
{

    long long size, i, choice, initial_size;
    long long value, index;

    cin >> size;
    initial_size = size;
    long long array[size + 1];
    array[0] = -999;
    for (i = 1; i <= size; i++)
    {
        cin >> array[i];
    }
    heapcls heap1(array, size);
    heap1.build_min_heap();
    heap1.print();
    while (1)
    {
        cin >> choice;
        switch (choice)
        {
        case 0:
            break;
        case 1:

            heap1.minimum();
            break;

        case 2:
            heap1.extract_min();
            heap1.print();
            break;

        case 3:
            long long input;
            cin >> input;
            heap1.insert(input);
            heap1.print();
            break;
        case 4:

            cin >> index >> value;
            heap1.decrease_key(index, value);
            heap1.print();
            break;
        case 5:
            cin >> index >> value;
            heap1.increase_key(index, value);
            heap1.print();
            break;
        }
        return 0;
    }
}