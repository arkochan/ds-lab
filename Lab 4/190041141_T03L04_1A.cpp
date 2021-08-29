#include <bits/stdc++.h>

using namespace std;
typedef struct node sn;
struct node
{
    long long key;
    struct node *next;
    struct node *prev;
};
class dq
{
    sn *head = new sn();
    sn *tail = new sn();

public:
    dq()
    {
        head->next = tail;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = head;
    }
    void push_front(long long key)
    {
        sn *newnode = new sn();
        newnode->key = key;

        newnode->next = head->next; // 2
        newnode->prev = head;       // 3
        head->next->prev = newnode; // 4
        head->next = newnode;       // 1
    }
    //1 2
    //3 4
    void push_back(long long key)
    {
        sn *newnode = new sn();
        newnode->key = key;

        newnode->next = tail;       //2
        newnode->prev = tail->prev; //3
        tail->prev->next = newnode; //1
        tail->prev = newnode;       //4
    }
    long long pop_back()
    {
        long long ret;
        sn *temp = tail->prev;

        tail->prev = tail->prev->prev;
        tail->prev->prev->next = tail;

        ret = temp->key;
        delete temp;
        return ret;
    }
    long long pop_front()
    {
        long long ret;
        sn *temp = tail->prev;
        head->next->next->prev = head;
        head->next = head->next->next;
        ret = temp->key;
        delete temp;
        return ret;
    }
    bool empty()
    {
        return head->next == tail;
    }
    void print()
    {
        if (empty())
            cout << "empty" << endl;
        sn *ite = head->next;
        while (ite != tail)
        {
            cout << ite->key << endl;
            ite = ite->next;
        }
    }
    void printr()
    {
        if (empty())
            cout << "empty" << endl;
        sn *ite = tail->prev;
        while (ite != head)
        {
            cout << ite->key << endl;
            ite = ite->prev;
        }
    }
};

int main()
{

    long long choice, key;
    dq q;
    while (1)
    {
        cin >> choice;
        if (choice == 5)
            break;
        else if (choice == 1)
        {
            cin >> key;
            q.push_front(key);
            q.print();
            q.printr();
        }
        else if (choice == 2)
        {
            cin >> key;
            q.push_back(key);
            q.print();
            q.printr();
        }
        else if (choice == 3)
        {
            q.pop_front();
            q.print();
            q.printr();
        }
        else if (choice == 4)
        {
            q.pop_back();
            q.print();
            q.printr();
        }
    }
    return 0;
}