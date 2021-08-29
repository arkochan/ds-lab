#include <bits/stdc++.h>

using namespace std;
struct node
{
private:
    long long data;
    long long subTreeSize;
    node *lc;
    node *rc;
    node *parent;

public:
    node(long long key) : data(key), subTreeSize(1), parent(NULL), lc(NULL), rc(NULL)
    {
    }
    friend class bst;
};

class bst
{
    node *root = NULL;

public:
    bool insert(long long data)
    {
        return insert(root, NULL, data);
    }
    bool insert(node *ite, node *target, long long data)
    {

        if (!ite)
        {
            node *newnode = new node(data);
            if (!root)
            {
                root = newnode;
                return 1;
            }
            newnode->parent = target;
            if (newnode->data < target->data)
                target->lc = newnode;
            else
                target->rc = newnode;
            return 1;
        }
        if ((data + 3) < ite->data)
        {
            if (insert(ite->lc, ite, data))
            {
                ite->subTreeSize++;
                return 1;
            }
            else
                return 0;
        }
        else if ((data - 3) > ite->data)
        {
            if (insert(ite->rc, ite, data))
            {
                ite->subTreeSize++;
                return 1;
            }
            else
                return 0;
        }
        else
            return 0;
    }
    void dfs()
    {
        node *ite = root;
        stack<node *> st;
        while (!st.empty() || ite)
        {
            while (ite)
            {
                st.push(ite);
                ite = ite->lc;
            }
            ite = st.top();
            st.pop();
            cout << ite->data << " ";
            ite = ite->rc;
        }
    }
    void bfs()
    {
        queue<node *> q;
        q.push(root);
        while (!q.empty())
        {
            node *ite = q.front();
            q.pop();
            if (ite->lc)
                q.push(ite->lc);
            if (ite->rc)
                q.push(ite->rc);
            cout << ite->data << " ";
        }
        cout << endl;
    }
    long long reservation_count(long long key)
    {
        long long count = 0;
        node *ite = root;
        while (ite->data != key)
        {
            if (key < ite->data)
                ite = ite->lc;
            else
            {
                count++;
                if (ite->lc)
                    count += ite->lc->subTreeSize;
                ite = ite->rc;
            }
        }
        if (ite->lc)
            return count + ite->lc->subTreeSize;
        else
            return count;
    }
};
int main()
{
    long long inp, t;
    bool flag = 1;
    bst bst1;
    while (1)
    {
        cin >> inp;
        if (inp == -1)
            break;
        flag = bst1.insert(inp);
        bst1.dfs();
        if (!flag)
            cout << "(Reservation failed)";
        cout << endl;
    }
    cin >> t;
    while (t--)
    {
        cin >> inp;
        cout << bst1.reservation_count(inp) << endl;
    }
}
