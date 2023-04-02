#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head;
int count_of_node = 0;
// Display Circualr Linked List
void Display(struct node *p)
{
    do
    {
        printf("%d ", p->data);
        p = p->next;
    } while (p != head);
    printf("\n");
}

// Creating Cricular Linked List Using Array
void CreateCircualrLinkList(int A[], int n)
{
    struct node *last, *t;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = A[0];
    head->next = head;
    last = head;
    count_of_node++;
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
        count_of_node++;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

// Display Circualr Linked List Using Recursion
void RecursiveDisplay(struct node *p)
{
    int count = 0;
    while (p != head || count == 0)
    {
        count = 1;
        printf("%d ", p->data);
        RecursiveDisplay(p->next);
    }
    count = 0;
}

// Insert At Head
void InsetAtHead(int value)
{
    struct node *t, *p = head;

    t = (struct node *)malloc(sizeof(struct node));
    count_of_node++;
    t->data = value;
    if (head == NULL)
    {
        head = t;
        head->next = head;
    }
    else
    {
        t->next = head;
        while (p->next != head)
        {
            p = p->next;
        };
        p->next = t;
        head = t;
    }
}

// Insert A Node In Circular Linked List
void Insert(struct node *p, int index, int value)
{
    if (index < 0 || index > count_of_node)
        return;
    if (index == 0)
        InsetAtHead(value);
    else
    {
        struct node *t;
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t = (struct node *)malloc(sizeof(struct node));
        count_of_node++;
        t->data = value;
        t->next = p->next;
        p->next = t;
    }
}
int main()
{
    // int A[] = {2, 4, 6, 8, 10, 12};
    // CreateCircualrLinkList(A, 6);
    Insert(head, 0, 100);
    Insert(head, 1, 200);
    Insert(head, 2, 300);
    Insert(head, 3, 400);
    Display(head);
    return 0;
}