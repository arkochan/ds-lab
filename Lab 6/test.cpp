#include <bits/stdc++.h>
#define ll long long
using namespace std;

class node
{
public:
    node(ll inp) : key(inp), lc(NULL), rc(NULL), parent(NULL) {}
    ll key;
    ll h;
    node *lc;
    node *rc;
    node *parent;
};

class AVL
{
    node *root;

public:
    AVL() : root(NULL) {}
    long long root_key()
    {
        return root->key;
    }
    ll balance(node *x)
    {
        return x->lc->h - x->rc->h;
    }
    void rotate_right(node *z)
    {
        node *left = z->lc;
        node *lrc = left->rc;

        left->parent = z->parent;
        if (z == root)
            root = left;
        else
        {
            if (z->parent->lc == z)
                z->parent->lc = left;
            else
                z->parent->rc = left;
        }
        z->parent = left;
        left->rc = z;
        if (lrc)
            lrc->parent = z;
        z->lc = lrc;
        node *ite = z;
        while (ite != NULL)
        {
            update_height(ite);
            ite = ite->parent;
        }
    }
    void rotate_left(node *z)
    {
        node *right = z->rc;
        node *rlc = right->rc;
        right->parent = z->parent;
        if (z == root)
            root = right;
        else
        {
            if (z->parent->rc == z)
                z->parent->rc = right;
            else
                z->parent->lc = right;
        }
        right->lc = z;
        z->parent = right;
        if (rlc)
            rlc->parent = z;
        z->rc = rlc;
        node *ite = z;
        while (ite != NULL)
        {
            update_height(ite);
            ite = ite->parent;
        }
    }
    node *insert(long long key)
    {
        node *newnode = new node(key);
        node *ite = root;
        node *target;
        if (ite == NULL)
            root = newnode;
        else
        {
            while (ite != NULL)
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
            node *ite = target;
            while (ite != NULL)
            {
                update_height(ite);
                ite = ite->parent;
            }
        }
        return newnode;
    }
    long long height(node *x)
    {
        return x ? x->h : -1;
    }
    void update_height(node *ite)
    {
        ite->h = max(height(ite->lc), height(ite->rc)) + 1;
    }
    long long balance_factor(node *x)
    {
        return height(x->lc) - height(x->rc);
    }
    void dfs()
    {
        node *ite = root;
        stack<node *> s;
        while (!s.empty() || ite != NULL)
        {
            while (ite != NULL)
            {
                s.push(ite);
                ite = ite->lc;
            }
            ite = s.top();
            s.pop();
            cout << ite->key << "(" << balance_factor(ite) << ") ";
            ite = ite->rc;
        }
        return;
    }
    long long check_balance(node *new_node)
    {
        long long imbalanced = 0;
        node *ite = new_node->parent;
        while (ite != NULL)
        {
            if (balance_factor(ite) >= -1 && balance_factor(ite) <= 1)
            {
                ite = ite->parent;
            }
            else
            {
                imbalanced = 1;
                cout << "Imbalanced node at: " << ite->key << endl;
                if (balance_factor(ite) > 1 && balance_factor(ite->lc) > 0)
                {
                    cout << "LL case" << endl;
                    cout << "Right_rotate(" << ite->key << ")" << endl;
                    rotate_right(ite);
                }
                else if (balance_factor(ite) > 1 && balance_factor(ite->lc) < 0)
                {
                    cout << "LR case" << endl;
                    cout << "Left_rotate(" << ite->lc->key << "),"
                         << "Right_rotate(" << ite->key << ")" << endl;
                    rotate_left(ite->lc);
                    rotate_right(ite);
                }
                else if (balance_factor(ite) < -1 && balance_factor(ite->rc) > 0)
                {
                    cout << "RL case" << endl;
                    cout << "Right_rotate(" << ite->rc->key << "),"
                         << "Left_rotate(" << ite->key << ")" << endl;
                    rotate_right(ite->rc);
                    rotate_left(ite);
                }
                else if (balance_factor(ite) < -1 && balance_factor(ite->rc) < 0)
                {
                    cout << "RR case" << endl;
                    cout << "Left_rotate(" << ite->key << ")" << endl;
                    rotate_left(ite);
                }
                break;
            }
        }
        if (!imbalanced)
        {
            cout << "Balanced" << endl;
        }
        return imbalanced;
    }
};

int main()
{
    AVL tree1;
    long long input, imbalance;
    while (1)
    {
        cin >> input;
        if (input == -1)
        {
            cout << "Status: ";
            tree1.dfs();
            cout << endl;
            break;
        }
        node *new_node = tree1.insert(input);
        tree1.dfs();
        cout << endl;
        imbalance = tree1.check_balance(new_node);
        if (imbalance)
        {
            cout << "Status: ";
            tree1.dfs();
            cout << endl;
        }
        cout << "root= " << tree1.root_key() << endl;
    }
    return 0;
}
