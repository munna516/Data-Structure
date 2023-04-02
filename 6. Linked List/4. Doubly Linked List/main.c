#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL;
int num_of_nodes = 0;
// Create a New Node
struct node *CreateNewNode(int value)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    num_of_nodes++;
    t->prev = NULL;
    t->data = value;
    t->next = NULL;
    return t;
}

// Display Linked List
void Display(struct node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Length of a LinkedList
int length(struct node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

// Creating a Doubly Linked List Using Array
void CreateDoubleLinkedList(int A[], int n)
{
    struct node *t, *last;
    head = CreateNewNode(A[0]);
    last = head;
    for (int i = 1; i < n; i++)
    {
        t = CreateNewNode(A[i]);
        last->next = t;
        t->prev = last;
        last = t;
    }
}

// Insert At Head
void InsertAtHead(int value)
{
    struct node *t;
    if (head == NULL)
    {
        t = CreateNewNode(value);
        head = t;
    }
    else
    {
        t = CreateNewNode(value);
        t->next = head;
        head->prev = t;
        head = t;
    }
}
// Insert A New Node
void Insert(struct node *p, int index, int value)
{
    struct node *t;
    if (index < 0 || index > num_of_nodes)
        return;

    if (index == 0)
        InsertAtHead(value);
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = CreateNewNode(value);
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}
int main()
{

    
    return 0;
}