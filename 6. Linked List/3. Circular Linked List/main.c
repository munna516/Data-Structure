#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *head;

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
    for (int i = 1; i < n; i++)
    {
        t = (struct node *)malloc(sizeof(struct node));
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
        count =1;
        printf("%d ", p->data);
        RecursiveDisplay(p->next);
    }
    count = 0;
}
int main()
{
    int A[] = {2, 4, 6, 8, 10, 12};
    CreateCircualrLinkList(A, 6);
  
    return 0;
}