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
    int size = 0;
    node *head;
    LinkedList()
    {
        head = NULL;
    }
    // Creating New Node
    node *CreateNewNode(int value)
    {
        node *new_node = new node;
        new_node->data = value;
        new_node->next = NULL;
    }
    // Insert a value At Head
    void InsertAtHead(int value)
    {
        size++;
        node *a = CreateNewNode(value);
        if (head == NULL)
        {
            head = a;
            return;
        }
        a->next = head;
        head = a;
    }
    // Traversing All the value
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
    // Search for a Value
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
    // Search For All Occerence Value
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
    // This Function Take O(n) times. so we avoid it
    int Getsize()
    {
        int sz = 0;
        node *a = head;
        while (a != NULL)
        {
            sz++;
            a = a->next;
        }
        return sz;
    }
    // Insert At Any Index
    void InsertAtAnyIndex(int index, int value)
    {
        if (index >= 0 && index <= size)
        {
            if (index == 0)
            {
                InsertAtHead(value);
                return;
            }
            size++;
            node *a = head;
            int current_index = 0;
            while (current_index != index - 1)
            {
                a = a->next;
                current_index++;
            }
            node *newnode = CreateNewNode(value);
            newnode->next = a->next;
            a->next = newnode;
        }
        else
        {
            return;
        }
    }
    // Delete A node From Head
    void DeleteAtHead()
    {
        if (head == NULL)
            return;
        node *a = head;
        head = a->next;
        delete a;
        size--;
    }
    // Delete A node from Any Index
    void DeleteAnyIndex(int index)
    {
        if (index < 0 && index > size - 1)
        {
            return;
        }
        if (index == 0)
        {
            DeleteAtHead();
            return;
        }
        node *a = head;
        int current_index = 0;
        while (current_index != index - 1)
        {
            a = a->next;
            current_index++;
        }
        node *b = a->next;
        a->next = b->next;
        delete b;
        size--;
    }
    // Insert A Node After a Specific Value
    void InsertAfterValue(int value, int data)
    {
        node *a = head;
        while (a != NULL)
        {
            if (a->data == value)
            {
                break;
            }
            a = a->next;
        }
        if (a == NULL)
        {
            cout << "This Value Doesn't Exist In Linked List" << endl;
            return;
        }
        node *newnode = CreateNewNode(data);
        newnode->next = a->next;
        a->next = newnode;
        size++;
    }
    // Printing Reverse Order
    void ReversePrint2(node *a)
    {
        if (a == NULL)
            return;
        ReversePrint2(a->next);
        cout << a->data << " ";
    }
    void ReversePrint()
    {
        ReversePrint2(head);
    }
};
int main()
{
    LinkedList l;
    l.InsertAtHead(10);
    l.InsertAtHead(20);
    l.InsertAtHead(40);
    l.InsertAtAnyIndex(3, 100);
    l.InsertAtAnyIndex(2, 600);
    l.Traverse();
    cout << l.size << endl;
    l.InsertAfterValue(600, 500);
    l.Traverse();
    l.ReversePrint();
    return 0;
}