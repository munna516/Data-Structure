#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};
class LinkedList
{
public:
    node *head;
    LinkedList()
    {
        head = NULL;
    }
    node *CreateNewNode(int value)
    {
        node *new_node = new node;
        new_node->data = value;
        new_node->next = NULL;
    }
    void InsertAtHead(int value)
    {
        node *a = CreateNewNode(value);
        if (head == NULL)
        {
            head = a;
            return;
        }
        a->next = head;
        head = a;
    }

    void Traverse()
    {
        node *p = head;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        cout << endl;
    }
    int SearchDistinctValue(int value)
    {
        node *p = head;
        int index = 0;
        while (p != NULL)
        {
            if (p->data == value)
            {
                return index;
            }
            p = p->next;
            index++;
        }
        return -1;
    }
    void SearchAllValue(int value)
    {

        node *p = head;
        int index = 0;
        while (p != NULL)
        {
            if (p->data == value)
            {
                cout << value << " is found at index : " << index << endl;
            }
            p = p->next;
            index++;
        }
        }
};
int main()
{
    LinkedList l;
    l.InsertAtHead(10);
    l.InsertAtHead(20);
    l.InsertAtHead(30);
    l.InsertAtHead(40);
    l.InsertAtHead(50);
    l.InsertAtHead(30);
    l.Traverse();
    cout << "10 found at index : " << l.SearchDistinctValue(10) << endl;
    cout << "30 found at index : " << l.SearchDistinctValue(30) << endl;
    cout << "100 found at index : " << l.SearchDistinctValue(100) << endl;

    l.SearchAllValue(30);
    return 0;
}