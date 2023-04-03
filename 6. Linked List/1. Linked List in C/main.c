#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL;
int size = 0;

// Creating A NOde
struct Node *CreateNewNode(int x)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = x;
    new_node->next = NULL;
    return new_node;
}

// Create a Linked List using Array (First)
void Create_Using_Array1(int A[], int n)
{
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[0];
    t->next = NULL;
    first = t;
    last = first;
    size++;
    for (int i = 1; i < n; i++)
    {
        size++;
        struct Node *p = CreateNewNode(A[i]);
        last->next = p;
        last = p;
    }
}

// Create a Linked List using Array (Second)
void Create_Using_Array2(int A[], int n)
{
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[0];
    t->next = NULL;
    second = t;
    last = second;
    size++;
    for (int i = 1; i < n; i++)
    {
        size++;
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
    printf("\n");
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
    p = first;
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
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

// Always insert At first
void InsertAtFirst(int value)
{
    struct Node *a = CreateNewNode(value);
    size++;
    a->next = first;
    first = a;
}

// Insert a new Node
void Insert(struct Node *p, int index, int value)
{
    struct Node *t;
    if (index < 0 && index > CountNode(p))
        return;
    if (index == 0)
    {
        InsertAtFirst(value);
    }
    else
    {
        t = CreateNewNode(value);
        size++;
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
    size++;
    if (first == NULL)
    {
        first = t;
        return;
    }
    last = first;
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
    if (first == NULL)
        InsertAtFirst(value);
    else
    {
        t = CreateNewNode(value);
        size++;
        while (p != NULL && p->data < value)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

// Delete First Node
void DeleteFirstNode()
{
    struct Node *q;
    q = first;
    first = q->next;
    size--;
    free(q);
}

// Delete a Node From Linked List
void DeleteNode(struct Node *p, int index)
{
    int x = -1;
    if (index < 0 || index > size)
        return;
    if (index == 0)
        DeleteFirstNode();
    else
    {
        struct Node *a;
        int current_index = 0;
        while (current_index != index - 1)
        {
            p = p->next;
            current_index++;
        }
        a = p->next;
        p->next = a->next;
        x = a->data;
        free(a);
        size--;
    }
}

// Linked List is Sorted Or Not
int IsSort(struct Node *p)
{
    int x = INT_MIN;
    while (p != NULL)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}

// Remove Duplicate From Sorted Linked List
void RemoveDuplicate(struct Node *p)
{
    struct Node *q = p->next;
    while (q != NULL)
    {
        if (p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}

// Reversing LinkedList(Element)
void ReverseElement(struct Node *p)
{
    int A[size], i = 0;
    while (p != NULL)
    {
        A[i] = p->data;
        p = p->next;
        i++;
    }
    p = first;
    i--;
    while (p != NULL)
    {
        p->data = A[i];
        i--;
        p = p->next;
    }
}

// Reverse Linked List using Links
void ReverseLinks(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

// Reverse Linked List Using Recursion
void ReverseLinkRecursion(struct Node *p, struct Node *q)
{
    if (p)
    {
        ReverseLinkRecursion(p->next, p);
        p->next = q;
    }
    else
        first = q;
}

// Concatenate Two Linkedlist
void ConcatenateLinkedList(struct Node *p, struct Node *q)
{
    third = p;
    while (p->next != NULL)
        p = p->next;
    p->next = q;
}

// Merger Two Linked List (Tow Linked List Must Be Sorted)
void MergeLinkedTwoList(struct Node *p, struct Node *q)
{
    struct Node *last = NULL;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p && q)
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p != NULL)
        last->next = p;
    else
        last->next = q;
}

// Checking Linked List have Loop or Not
int CheckLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = (q != NULL) ? q->next : NULL;
    } while (p != NULL && q != NULL && p != q);
    return (p == q) ? 1 : 0;
}

// Finding Middle of a Linked List
void Middle(struct Node *p)
{
    struct Node *q = first;
    while (q)
    {
        q = q->next;
        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }
}

/* This Is Main Function. */
int main()
{

    return 0;
}