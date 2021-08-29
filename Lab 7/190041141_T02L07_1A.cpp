
#include <bits/stdc++.h>
#define mx 100001
using namespace std;
int arr[100000];

void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node].sum = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node].sum = tree[Left].sum + tree[Right].sum;
}
int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if (i > e || j < b)
        return 0;

    if (b >= i and e <= j)
        return tree[node].sum + carry * (e - b + 1);

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}
struct info
{
    int prop, sum;
} tree[mx * 3];
void update(int node, int b, int e, int i, int j, int x)
{
    if (i > e || j < b)
        return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);
    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}
void print(int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    int n, test, i, j, choice, v;
    cin >> n >> test;
    for (i = 1; i <= n; i++)
        cin >> arr[i];
    init(1, 1, n);
    while (test--)
    {

        cin >> choice;
        if (choice == 1)
        {
            cin >> i >> j;
            cout << arr[i] << " (";
            update(1, 1, n, i, j, -arr[i]);
            arr[i] = 0;
            print(n);
            cout << ")";
        }
        else if (choice == 2)
        {
            cin >> i >> j >> v;
            update(1, 1, n, i, j, v);
            arr[i] += v;
            print(n);
        }
        else
        {
            cin >> i >> j;
            cout << query(1, 1, n, i, j);
        }
        cout << endl;
    }
}