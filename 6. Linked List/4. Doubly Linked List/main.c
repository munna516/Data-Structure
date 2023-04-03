#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *previous;
    int data;
    struct node *next;
} *head = NULL;
int num_of_nodes = 0;
// Create a New Node
struct node *CreateNewNode(int value)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    num_of_nodes++;
    t->previous = NULL;
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
        t->previous = last;
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
        head->previous = t;
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
        t->previous = p;
        t->next = p->next;
        if (p->next)
            p->next->previous = t;
        p->next = t;
    }
}

// Delete First Node
void DeleteAtFirst()
{
    head->next->previous = NULL;
    head = head->next;
    num_of_nodes--;
}

// Delete At Node
void Delete(struct node *p, int index)
{
    struct node *a;

    if (index < 0 || index > num_of_nodes)
        return;
    if (index == 0)
        DeleteAtFirst();
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        if (p->next->next == NULL)
        {
            p->next = NULL;
            num_of_nodes--;
        }
        else
        {
            a = p->next;
            p->next = a->next;
            p->previous = a->previous;
            num_of_nodes--;
        }
    }
}

// Reverse Doubly A Linked List
void Reverse(struct node *p)
{
    struct node *temp;
    while (p != NULL)
    {
        temp = p->next;
        p->next = p->previous;
        p->previous = temp;
        p = p->previous;
        if (p!=NULL && p->next == NULL)
            head = p;
    }
}
int main()
{
    Insert(head, 0, 100);
    Insert(head, 1, 200);
    Insert(head, 2, 300);
    Insert(head, 3, 400);
    Insert(head, 4, 500);
    Reverse(head);
    Display(head);
    return 0;
}

/* NULL <- head ->100 -> <- 200 -> <- 300 -> <- 400 -> <- 500-> NULL */