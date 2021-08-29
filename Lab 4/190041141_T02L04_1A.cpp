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
    sn *head = new sn();
    sn *tail = new sn();

public:
    linked_list()
    {
        head->next = tail;
        head->prev = NULL;
        tail->next = NULL;
        tail->prev = head;
    }
    void insert_front(long long key)
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
    void insert_back(long long key)
    {
        sn *newnode = new sn();
        newnode->key = key;

        newnode->next = tail;       //2
        newnode->prev = tail->prev; //3
        tail->prev->next = newnode; //1
        tail->prev = newnode;       //4
    }
    void insert_after(long long key, long long v) //not in task
    {
        bool flag = 0;
        sn *newnode = new sn();
        newnode->key = key;

        sn *ite = head;
        long long index = 0;
        while (ite != tail)
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

        newnode->next = ite->next;     //2
        newnode->prev = ite;           //3
        ite->next = newnode;           //1
        newnode->next->prev = newnode; //4
    }
    void update_node(long long key, long long v)
    {
        sn *ite = head->next;
        while (ite != tail)
        {
            if (ite->key == v)
            {
                ite->key = key;
                return;
            }
            ite = ite->next;
        }
    }
    long long remove_element(long long key)
    {
        long long ret;
        sn *ite = head;
        do
        {
            if (ite->next->key == key)
            {
                sn *temp = ite->next;
                ite->next->next->prev = ite; //delete nodes next node is delete nodes prev;
                ite->next = ite->next->next; //delete nodes prev nodes next node is delete nodes next node
                ret = temp->key;
                delete temp;
            }
            ite = ite->next;
        } while (ite->next != tail);
        return ret;
    }
    void remove_front()
    {

        sn *temp = head->next;
        head->next->next->prev = head;
        head->next = head->next->next;
        delete temp;
    }
    void remove_end()
    {

        sn *temp = tail->prev;
        if (empty())
        {
            cout << "empty" << endl;
            return;
        }
        tail->prev = tail->prev->prev;
        temp->prev->next = tail;
        delete temp;
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
            cout << ite->key << " ";
            ite = ite->next;
        }
        cout << endl;
    }
    void printr()
    {
        if (empty())
            cout << "empty" << endl;
        sn *ite = tail->prev;
        while (ite != head)
        {
            cout << ite->key << " ";
            ite = ite->prev;
        }
        cout << endl;
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
            lst.printr();
        }
        else if (choice == 2)
        {
            cin >> key;
            lst.insert_back(key);
            lst.print();
            lst.printr();
        }
        else if (choice == 3)
        {
            int val;
            cin >> key >> val;
            lst.insert_after(key, val);
            lst.print();
            lst.printr();
        }
        else if (choice == 4)
        {
            int val;
            cin >> key >> val;
            lst.update_node(key, val);
            lst.print();
            lst.printr();
        }
        else if (choice == 5)
        {
            cin >> key;
            lst.remove_element(key);
            lst.print();
            lst.printr();
        }
        else if (choice == 6)
        {
            lst.remove_end();
            lst.print();
            lst.printr();
        }
    }
    return 0;
}