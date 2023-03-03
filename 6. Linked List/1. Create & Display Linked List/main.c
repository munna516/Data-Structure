#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
int size = 0;
struct Node *CreateNewNode(int x)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}
void Create_Using_Array(int A[], int n)
{
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[0];
    t->next = NULL;
    head = t;
    last = head;
    size++;
    for (int i = 1; i < n; i++)
    {
        struct Node *p = CreateNewNode(A[i]);
        last->next = p;
        last = p;
    }
}

// Display Linked List
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
}
// Display using Recursion
void DisplayRecursion(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        DisplayRecursion(p->next);
    }
    printf("\n");
}
// Display Reverse Using Recursion
void DisplayReverseRecursion(struct Node *p)
{
    if (p != NULL)
    {
        DisplayReverseRecursion(p->next);
        printf("%d ", p->data);
    }
}
// Count of Node
int CountNode(struct Node *p)
{
    p = head;
    int c = 0;
    while (p != NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}
// Counting Nodes Using Recursion
int CountNodeRecursion(struct Node *p)
{
    if (p == NULL)
        return 0;
    else
        return CountNodeRecursion(p->next) + 1;
}
// Sum of All Nodes
int Add(struct Node *p)
{
    int sum = 0;
    while (p != NULL)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}
// Sum of All Nodes Using Recursion
int AddRecursion(struct Node *p)
{
    int sum = 0;
    if (p == NULL)
        return 0;
    else
        return AddRecursion(p->next) + p->data;
}
// Max Element From Linked List
int MaxElement(struct Node *p)
{
    int max = INT_MIN;
    while (p != NULL)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
// Max Element From Linked List Using Recursion
int MaxElementRecursion(struct Node *p)
{
    int x = 0;
    if (p == NULL)
        return INT_MIN;
    x = MaxElementRecursion(p->next);
    return p->data > x ? p->data : x;
}
// Search Key
struct Node *LSearch(struct Node *p, int key)
{
    while (p != NULL)
    {
        if (p->data == key)
            return p;
        p = p->next;
    }
    return NULL;
}
// Recursive Version of Search
struct Node *RLSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (p->data == key)
        return p;
    return RLSearch(p->next, key);
}
// Improving Linear search
struct Node *ImproveLSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (p->data == key)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}
// Insert a new Node
void Insert(struct Node *p, int index, int value)
{
    struct Node *t;
    if (index < 0 && index > CountNode(p))
        return;
    t = CreateNewNode(value);
    size++;
    if (index == 0)
    {
        t->next = head;
        head = t;
    }
    else
    {
        int current_index = 0;
        while (current_index != index - 1)
        {
            p = p->next;
            current_index++;
        }
        t->next = p->next;
        p->next = t;
    }
}
// Always Insert At Last
void InsertAtLast(int value)
{
    struct Node *t, *last;
    t = CreateNewNode(value);
    if (head == NULL)
    {
        head = t;
        return;
    }
    last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = t;
    last = t;
}
// Insert a node In Sorted LinkedList
void InsertSort(struct Node *p, int value)
{
    struct Node *t, *q = NULL;
    t = CreateNewNode(value);
    if (head == NULL)
        head = t;
    else
    {
        while (p != NULL && p->data < value)
        {
            q = p;
            p = p->next;
        }
        if (p == head)
        {
            t->next = head;
            head = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    Create_Using_Array(A, 5);
    InsertSort(head, 12);
    InsertSort(head, 12);
    Display(head);
    return 0;
}