#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
} *top = NULL;

// Display
void Display()
{
    struct node *p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Pushing in Stack
void push(int x)
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    if (t == NULL)
        printf("Stack is Full\n");
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

// Pop From Stack
int pop()
{
    int x = -1;
    struct node *p = top;
    if (top == NULL)
        printf("Stack is Empty!!\n");
    else
    {
        top = top->next;
        x = p->data;
        free(p);
    }
    return x;
}

// peek a value from stack
int peek(int pos)
{
    struct node *p = top;
    for (int i = 0; p != NULL && i < pos - 1; i++)
    {
        p = p->next;
    }
    if (p != NULL)
        return p->data;
    else
        return -1;
}

// Stack top value
int stacktop()
{
    if (top)
        return top->data;
    else
        return -1;
}

// Check Stack is Empty
int isEmpty()
{
    return top == NULL ? 1 : 0;
}

// Check Stack is Full
int isFull()
{
    struct node *t = (struct node *)malloc(sizeof(struct node));
    int r = (t == NULL) ? 1 : 0;
    free(t);
    return r;
}
int main()
{
   
    return 0;
}