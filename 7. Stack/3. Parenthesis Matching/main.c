#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Stack
{
    char *A;
    int size;
    int top;
};

// Push an Element In a stack. O(1)
void push(struct Stack *s, char value)
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
void pop(struct Stack *s)
{
    char x = -1;
    if (s->top == -1)
        printf("Stack is Emply!!!\n");
    else
    {
        x = s->A[s->top];
        s->top--;
    }
    // return x;
}

// Check Stack is Empty
int isEmpty(struct Stack s)
{
    if (s.top == -1)
        return 1;
    return 0;
}
// Parenthesis match or Not
int Balance(char *exp)
{
    struct Stack st;
    st.size = strlen(exp);
    st.top = -1;
    st.A = (char *)malloc(st.size * sizeof(char));
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
            push(&st, exp[i]);
        else if (exp[i] == ')')
        {
            if (isEmpty(st))
                return 0;
            pop(&st);
        }
    }
    if (isEmpty(st))
        return 1;
    else
        return 0;
}

int main()
{
    char *exp = "((a+b)+(b-c)*a+b*(a-c)))";
    printf("%d ", Balance(exp));
    return 0;
}