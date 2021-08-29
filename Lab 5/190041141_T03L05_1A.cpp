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
            if (ite->lc != NULL)
                q.push(ite->lc);
            if (ite->rc != NULL)
                q.push(ite->rc);
            cout << ite->data << " ";
        }
        cout << endl;
    }

    int maximum_enemy()
    {
        return maximum_enemy(root);
    }
    int maximum_enemy(node *curr_node)
    {
        int lh, rh;
        if (curr_node == NULL)
            return -1;
        lh = maximum_enemy(curr_node->lc);
        rh = maximum_enemy(curr_node->rc);
        return max(lh, rh) + 1;
    }
};
int main()
{
    long long inp, max_enemy;
    bool flag = 1;
    bst bst1;
    while (1)
    {
        cin >> inp;
        if (inp == -1)
            break;
        bst1.insert(inp);
        cout << endl;
    }
    max_enemy = bst1.maximum_enemy();
    cout << max_enemy << endl;
}
