#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;

void Create(int A[], int n)
{
    struct Node *last;
    head = (struct node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;
    for (int i = 1; i < n; i++)
    {
        struct Node *t = (struct node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
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

int main()
{
    struct Node *temp;
    int A[] = {3, 6, 2, 10, 7, 9};
    Create(A, 6);
    temp = ImproveLSearch(head, 9);
    if (temp)
        printf("Key Is found\n");
    else
        printf("Key Not Found\n");
    Display(head);
    return 0;
}