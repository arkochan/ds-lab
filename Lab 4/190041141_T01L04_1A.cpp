#include <bits/stdc++.h>
using namespace std;
typedef struct node sn;
struct node
{
    long long key;
    struct node *next;
};
class linked_list
{
    sn *head = new sn();

public:
    void insert_front(long long key)
    {
        sn *newnode = new sn();
        newnode->key = key;
        newnode->next = head->next;
        head->next = newnode;
    }
    void insert_back(long long key)
    {
        sn *newnode = new sn();
        newnode->key = key;
        newnode->next = NULL;
        sn *ite = head;

        while (ite->next) 
            ite = ite->next;

        ite->next = newnode;
    }
    void insert_after(long long key, long long v) //not in task
    {
        bool flag = 0;
        sn *newnode = new sn();
        newnode->key = key;

        sn *ite = head;
        long long index = 0;
        while (ite->next)
        {
            ite = ite->next;
            if (ite->key == v)
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            printf("nod with value %ll dosent exist", v);
            return;
        }
        newnode->next = ite->next;
        ite->next = newnode;
    }
    void update_node(long long key, long long v)
    {
        sn *ite = head;
        while (ite)
        {
            if (ite->key == v)
            {
                ite->key = key;
                return;
            }
            ite = ite->next;
        }
    }
    void remove_element(long long key)
    {
        sn *ite = head;
        while (ite->next->next)
        {
            if (ite->next->key == key)
            {
                sn *temp = ite->next;
                ite->next = ite->next->next;
                delete temp;
                return;
            }
            ite = ite->next;
        }
        if (ite->next->key == key)
        {
            delete ite->next;
            ite->next = NULL;
        }
    }
    void remove_end()
    {
        sn *ite = head;
        while (ite->next->next)
            ite = ite->next;
        delete ite->next;
        ite->next = NULL;
    }
    void print()
    {
        sn *ite = head->next;
        while (ite)
        {
            cout << ite->key << endl;
            ite = ite->next;
        }
    }
};

int main()
{
    linked_list lst;
    long long choice, key;
    while (1)
    {
        cin >> choice;
        if (choice == 7)
            break;
        else if (choice == 1)
        {
            cin >> key;
            lst.insert_front(key);
            lst.print();
        }
        else if (choice == 2)
        {
            cin >> key;
            lst.insert_back(key);
            lst.print();
        }
        else if (choice == 3)
        {
            int val;
            cin >> key >> val;
            lst.insert_after(key, val);
            lst.print();
        }
        else if (choice == 4)
        {
            int val;
            cin >> key >> val;
            lst.update_node(key, val);
            lst.print();
        }
        else if (choice == 5)
        {
            cin >> key;
            lst.remove_element(key);
            lst.print();
        }
        else if (choice == 6)
        {
            lst.remove_end();
            lst.print();
        }
    }
    return 0;
}