#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int subtreeSize;
    Node *parent;
    Node *left;
    Node *right;
    Node(int _a)
    {
        data = _a;
        subtreeSize = 1;
        parent = NULL;
        left = NULL;
        right = NULL;
    }
};
Node *root = NULL;

bool insert(Node *curr_node, Node *target, int data)
{
    bool flag = false;
    if (curr_node == NULL)
    {
        Node *temp = new Node(data);
        if (root == NULL)
        {
            root = temp;
            return true;
        }
        temp->parent = target;
        if (temp->data < target->data)
            target->left = temp;
        else
            target->right = temp;
        return true;
    }
    if ((data + 3) < curr_node->data)
    {
        if (insert(curr_node->left, curr_node, data))
        {
            curr_node->subtreeSize++;
            return true;
        }
        else
        {
            return false;
        }
    }
    else if ((data - 3) > curr_node->data)
    {
        if (insert(curr_node->right, curr_node, data))
        {
            curr_node->subtreeSize++;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int Reservation_count(int key)
{
    int cnt = 0;
    Node *cur = root;
    while (cur->data != key)
    {
        if (key < cur->data)
        {
            cur = cur->left;
        }
        else
        {
            cnt++;
            if (cur->left != NULL)
                cnt += cur->left->subtreeSize;
            cur = cur->right;
        }
    }
    if (cur->left != NULL)
    {
        return cnt + cur->left->subtreeSize;
    }
    else
    {
        return cnt;
    }
}

void inOrder_print(Node *root)
{
    stack<Node *> stk;
    Node *cur = root;

    while (!stk.empty() || cur != NULL)
    {
        while (cur != NULL)
        {
            stk.push(cur);
            cur = cur->left;
        }

        cur = stk.top();
        stk.pop();

        cout << cur->data << " ";
        cur = cur->right;
    }
}

int main()
{
   int a, tc;

    cin >> a;
    do
    {
        if (insert(root, NULL, a))
        {
            inOrder_print(root);
        }
        else
        {
            inOrder_print(root);
            cout << "(Reservation failed)";
        }
        cout << '\n';
        cin >> a;
    } while (a != -1);

    cin >> tc;
    while (tc--)
    {
        cin >> a;
        cout << Reservation_count(a) << '\n';
    }

    return 0;
}
