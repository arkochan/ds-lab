#include <bits/stdc++.h>

using namespace std;
class node
{
public:
    node(long long inp) : key(inp), lc(NULL), rc(NULL), parent(NULL) {}
    long long key;
    long long h;
    node *lc;
    node *rc;
    node *parent;
};
class BST
{
    node *root = NULL;

public:
    void insert(int data)
    {
        node *newnode = new node(data);
        node *ite = root;
        node *target;
        if (ite == NULL)
            root = newnode;
        else
        {
            while (ite)
            {
                target = ite;
                if (newnode->key < ite->key)
                {
                    ite = ite->lc;
                }
                else
                {
                    ite = ite->rc;
                }
            }
            newnode->parent = target;
            if (newnode->key < target->key)
                target->lc = newnode;
            else
                target->rc = newnode;
            node *curr_node = target;
            while (curr_node)
            {
                update_height(curr_node);
                curr_node = curr_node->parent;
            }
        }
    }
    long long height(node *x)
    {
        return x ? x->h : -1;
    }
    void update_height(node *x)
    {
        x->h = max(height(x->lc), height(x->rc)) + 1;
    }
    long long balance_factor(node *x)
    {
        return (long long)((long long)height(x->lc) - (long long)height(x->rc));
    }
    void dfs()
    {
        dfs(root);
    }
    void dfs(node *curr_node)
    {
        if (curr_node == NULL)
        {
            return;
        }
        dfs(curr_node->lc);
        cout << curr_node->key << "(" << (long long)(balance_factor(curr_node)) << ") ";
        dfs(curr_node->rc);
    }
};
int main()
{
    BST tree1;
    int input;
    while (1)
    {
        cin >> input;
        if (input == -1)
            break;
        tree1.insert(input);
        tree1.dfs();
        cout << endl;
    }
    return 0;
}