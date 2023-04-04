#include <stdio.h>
#include <stdlib.h>
struct Stack
{
    int *A;
    int size;
    int top;
};

// Creating a Stack
void CreateStack(struct Stack *s)
{
    printf("Enter the Array Size : ");
    scanf("%d", &s->size);
    s->A = (int *)malloc(s->size * sizeof(int));
    s->top = -1;
}

// Display Stack
void Display(struct Stack s)
{
    for (int i = s.top; i >= 0; i--)
        printf("%d ", s.A[i]);
    printf("\n");
}

// Push an Element In a stack. O(1)
void push(struct Stack *s, int value)
{
    if (s->top == s->size - 1)
        printf("Stack is Full\n");
    else
    {
        s->top++;
        s->A[s->top] = value;
    }
}

// Pop an Element in a Stack. O(1)
int pop(struct Stack *s)
{
    int x = -1;
    if (s->top == -1)
        printf("Stack is Emply!!!\n");
    else
    {
        x = s->A[s->top];
        s->top--;
    }
    return x;
}

// Peak a particular Index
int peek(struct Stack s, int index)
{
    int x = -1;
    if (s.top - index < 0)
        printf("Invalid Index\n");
    x = s.A[s.top - index + 1];
    return x;
}

// Check Stack is Empty
int isEmpty(struct Stack s)
{
    if (s.top == -1)
        return 1;
    return 0;
}

// Check Stack is Full
int isFull(struct Stack s)
{
    return s.top == s.size - 1;
}

// Top Element In stack
int stackTop(struct Stack s)
{
    if (!isEmpty(s))
        return s.A[s.top];
    return -1;
}
int main()
{
    struct Stack st;
    CreateStack(&st);
    push(&st, 6);
    push(&st, 61);
    push(&st, 16);
    push(&st, 12);
    push(&st, 112);
    Display(st);

    return 0;
}