#include <bits/stdc++.h>
#define mx 100001
using namespace std;
int arr[mx];
int tree[mx * 3];
int type(int a, int b)
{
    return min(a, b);
}
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    init(Left, b, mid);
    init(Right, mid + 1, e);
    tree[node] = type(tree[Left], tree[Right]);
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
        return INT_MAX;
    if (b >= i && e <= j)
        return tree[node];
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);
    return type(p1, p2);
}

int main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >>
            arr[i];
    }
    init(1, 1, n);
    while (q--)
    {
        int x, y;
        cin >> x >> y;
        cout << query(1, 1, n, x, y) << endl;
    }
}
