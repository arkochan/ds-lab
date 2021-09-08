#include "bits/stdc++.h"

using namespace std;

class node
{
    node *next[26];

    bool flag;
    int count;

public:
    node()
    {
        count = 0;
        flag = false;
        for (int i = 0; i < 26; i++)
            next[i] = NULL;
    }
    node *&getnode(char x)
    {
        return next[x - 'a'];
    }
    bool has(char x)
    {
        return next[x - 'a'];
    }
    node *setnode(char x)
    {
        if (has(x))
            return getnode(x);
        else
            return getnode(x) = new node();
    }
    void end()
    {
        flag = true;
    }
    bool isend()
    {
        return flag;
    }
    int wcount()
    {
        return count;
    }
    void newword()
    {
        count++;
    }
};
class trie
{
    node *root = new node();

public:
    void insert(string str)
    {
        node *ite = root;
        for (auto i : str)
            ite = ite->setnode(i);
        ite->end();
        ite->newword();
    }
    bool find(string str)
    {
        node *ite = root;
        for (auto i : str)
        {
            if (ite->has(i))
            {
                ite = ite->getnode(i);
            }
            else
                return 0;
        }
        return ite->wcount();
    }
    void prefix(string str)
    {
        int count = 0;
        auto ite = root;
        queue<pair<node *, string>> q;
        for (auto c : str)
        {
            if (ite->has(c))
                ite = ite->getnode(c);
        }
        if (ite->isend())
        {
            cout << str << endl;
            count += ite->wcount();
        }
        q.push({ite, ""});
        while (!q.empty())
        {
            ite = q.front().first;
            for (char i = 'a'; i <= 'z'; i++)
            {
                if (ite->has(i))
                {

                    if (ite->getnode(i)->isend())
                    {
                        count += ite->wcount();

                        cout << str + q.front().second + i << endl;
                    }
                    q.push({ite->getnode(i), q.front().second + i});
                }
            }
            q.pop();
        }
        cout << count << endl;
    }
    void prefixc(string str)
    {
        int count = 0;
        auto ite = root;
        for (auto i : str)
        {
            if (ite->has(i))
                ite = ite->getnode(i);
            else
            {
                cout << 0 << endl;
                return;
            }
        }
        if (ite->isend())
        {
            count += ite->wcount();
        }
        queue<node *> q;
        q.push(ite);
        while (!q.empty())
        {
            ite = q.front();
            for (auto i = 'a'; i < 'z'; i++)
            {
                if (ite->has(i))
                {
                    count += ite->getnode(i)->wcount();
                    q.push(ite->getnode(i));
                }
            }
            q.pop();
        }
        cout << count << endl;
    }
};
int main()
{
    int x;
    trie t1;
    t1.insert("arko");
    t1.insert("arkoa");
    t1.insert("arkoa");
    t1.insert("arkoa");
    t1.insert("arkob");
    t1.insert("arkoab");
    t1.insert("arkotheredoder");
    t1.insert("arkotheredoder");
    t1.insert("arkotheredoder");

    t1.prefixc("arko");
    cin >> x;
}