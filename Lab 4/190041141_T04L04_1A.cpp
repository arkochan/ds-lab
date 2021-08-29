#include <bits/stdc++.h>
using namespace std;
typedef struct node sn;
struct node
{
    long long key;
    struct node *next;
    struct node *prev;
};

class linked_list
{
    sn *tail = new sn();

public:
    sn *head = new sn();
    linked_list()
    {
        head->next = tail;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = head;
    }

    //1 2
    //3 4
    void insert_back(long long key)
    {
        sn *newnode = new sn();
        newnode->key = key;

        newnode->next = tail;       //2
        newnode->prev = tail->prev; //3
        tail->prev->next = newnode; //1
        tail->prev = newnode;       //4
    }
    void print()
    {
        sn *ite = head->next;
        while (ite != tail)
        {
            cout << ite->key << endl;
            ite = ite->next;
        }
    }
};
int main()
{
    linked_list lst;
    long long input;
    while (1)
    {
        cin >> input;
        if (input == -1)
            break;
        lst.insert_back(input);
    }
    sn *ite = lst.head;
    while (ite->next != NULL)
    {
        if (ite->key == ite->next->key)
        {
            sn *temp = ite->next;
            ite->next = ite->next->next;
            delete temp;
        }
        else
            ite = ite->next;
    }
    lst.print();
    return 0;
}