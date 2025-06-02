#include <bits/stdc++.h>
using namespace std;

class MyHashMap
{
private:
    static const int SIZE = 10007;
    struct Node
    {
        int key, value;
        Node *next;
        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };
    Node *table[SIZE];

    int hash(int key)
    {
        return key % SIZE;
    }

public:
    MyHashMap()
    {
        for (int i = 0; i < SIZE; ++i)
        {
            table[i] = nullptr;
        }
    }

    void put(int key, int value)
    {
        int h = hash(key);
        Node *curr = table[h];
        while (curr)
        {
            if (curr->key == key)
            {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }
        Node *newNode = new Node(key, value);
        newNode->next = table[h];
        table[h] = newNode;
    }

    int get(int key)
    {
        int h = hash(key);
        Node *curr = table[h];
        while (curr)
        {
            if (curr->key == key)
            {
                return curr->value;
            }
            curr = curr->next;
        }
        return -1;
    }

    void remove(int key)
    {
        int h = hash(key);
        Node *curr = table[h];
        Node *prev = nullptr;
        while (curr)
        {
            if (curr->key == key)
            {
                if (prev)
                {
                    prev->next = curr->next;
                }
                else
                {
                    table[h] = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    ~MyHashMap()
    {
        for (int i = 0; i < SIZE; ++i)
        {
            Node *curr = table[i];
            while (curr)
            {
                Node *next = curr->next;
                delete curr;
                curr = next;
            }
        }
    }
};
int main()
{
    MyHashMap obj;
    obj.put(1, 10);
    obj.put(2, 20);
    cout << obj.get(1) << endl;
    cout << obj.get(3) << endl;
    obj.put(2, 30);
    cout << obj.get(2) << endl;
    obj.remove(2);
    cout << obj.get(2) << endl;
    return 0;
}
