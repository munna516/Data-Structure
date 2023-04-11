#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    char data;
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

// Pushing in the Stack
void push(char x)
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
char pop()
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

// Checking Precedence
int pre(char s)
{
    if (s == '+' || s == '-')
        return 1;
    else if (s == '*' || s == '/')
        return 2;
    return 0;
}

// Check Operator or operand
int isOperand(char s)
{
    if (s == '+' || s == '-' || s == '*' || s == '/')
        return 0;
    else
        return 1;
}

// Infix to postfix Conversion
char *InfixToPostfix(char *infix)
{
    int i = 0, j = 0;
    char *postfix;
    int len = strlen(infix);
    postfix = (char *)malloc((len + 2) * sizeof(char));
    while (infix[i] != '\0')
    {
        if (isOperand(infix[i]))
            postfix[j++] = infix[i++];
        else
        {
            if (pre(infix[i]) > pre(top->data))
                push(infix[i++]);
            else
            {
                postfix[j++] = pop();
            }
        }
    }
    while (top != NULL)
    {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b*c/d-c*b";
    push('#');
    char *postfix = InfixToPostfix(infix);
    printf("%s\n", postfix);
    return 0;
}