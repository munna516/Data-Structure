#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
} *head = NULL;

// Create a New Node
struct node *CreateNewNode(int value)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
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

int main()
{
    int A[] = {1, 7, 2, 4, 5, 9, 8};
    CreateDoubleLinkedList(A, 7);
    Display(head);
    printf("%d ",length(head));
    return 0;
}