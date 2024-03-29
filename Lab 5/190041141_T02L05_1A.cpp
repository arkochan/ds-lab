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
    node(long long key) : data(key)
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
            node *ite;
            while (ite)
            {
                ite = ite;
                if ((newnode->data + 3) < ite->data)
                    ite = ite->lc;
                else if ((newnode->data - 3) > ite->data)
                    ite = ite->rc;
                else
                    return false;
            }
            newnode->parent = ite;
            if (newnode->data < ite->data)
                ite->lc = newnode;
            else
                ite->rc = newnode;
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
};
int main()
{
    long long inp;
    bool flag = 1;
    bst bst1;
    while (1)
    {
        cin >> inp;
        if (inp == -1)
            break;
        flag = bst1.insert(inp);
        bst1.dfs();
        if (flag)
            cout << "(Reservation failed)";
        cout << endl;
    }
    bst1.bfs();
}
