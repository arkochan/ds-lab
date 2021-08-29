#include <bits/stdc++.h>

using namespace std;
struct node
{
private:
    long long data;
    node *lc;
    node *rc;
    node *parent;

public:
    node(long long key) : data(key) //cotr
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
        node *newnode = new node(data);
        node *ite = root;
        if (!ite)
            root = newnode;
        else
        {
            node *target;
            while (ite)
            {
                target = ite;
                if ((newnode->data + 3) < ite->data)
                    ite = ite->lc;
                else if ((newnode->data - 3) > ite->data)
                    ite = ite->rc;
                else
                    return false;
            }
            newnode->parent = target;
            if (newnode->data < target->data)
                target->lc = newnode;
            else
                target->rc = newnode;
        }
        return 1;
    }
    void dfs()
    {
        node *ite = root;
        stack<node *> st;
        while (!st.empty() || ite != NULL)
        {
            while (ite != NULL)
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
    bool search(long long key)
    {
        return search(root, key);
    }
    bool search(node *parent, long long key)
    {
        if (!parent)
            return 0;
        if (parent->data == key)
            return 1;
        else if (parent->data < key)
            return search(parent->rc, key);
        else
            return search(parent->lc, key);
    }
};
int main()
{
    const int n = 100;
    bool b[n];
    for (int i = 0; i < n; ++i)
    {
        int x = b[i];
        if (x)
        {
            std::cout << x << ' ';
        }
    }
}
