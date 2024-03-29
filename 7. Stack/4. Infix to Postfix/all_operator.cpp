#include <bits/stdc++.h>
using namespace std;
class Stack
{
private:
    int size;
    int top;
    char *s;

public:
    Stack(int sz)
    {
        size = sz;
        top = -1;
        s = new char[size];
    }

    // Pushing element
    void push(char value)
    {
        if (top == size - 1)
            cout << "Stack is full" << endl;
        else
        {
            top++;
            s[top] = value;
        }
    }

    // Pop Element
    char pop()
    {
        char x = -1;
        if (top == -1)
            cout << "Stack is Empty!!" << endl;
        else
        {
            x = s[top];
            top--;
        }
        return x;
    }

    // Top Element
    char top_element()
    {
        if (top == -1)
            return -1;
        else
            return s[top];
    }

    // stack is empty
    int isEmpty()
    {
        if (top == -1)
            return 1;
        else
            return 0;
    }
    // Stack is Full
    int isFull()
    {
        if (top == size - 1)
            return 1;
        else
            return 0;
    }

    // Check Precedence
    int pre(char x)
    {
        if (x == '+' || x == '-')
            return 1;
        else if (x == '*' || x == '/')
            return 2;
        else if (x == '^')
            return 3;

        else
            return -1;
    }

    // Check operator or operand
    int isOperand(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^'||x=='('||x==')')
            return 0;
        else
            return 1;
    }

    // Convert Infix to postfix
    char *infixToPostfix(char *infix)
    {
        char *postfix;
        int len = strlen(infix);
        postfix = new char[len + 2];
        int i = 0, j = 0;
        while (infix[i] != '\0')
        {
            if (isOperand(infix[i]))
                postfix[j++] = infix[i++];

            else if (infix[i] == '(')
                push(infix[i++]);

            else if (infix[i] == ')')
            {
                while (top > -1 && top_element() != '(')
                {
                    postfix[j++] = top_element();
                    pop();
                }
                pop();
                i++;
            }

            else
            {
                while (top > -1 && pre(top_element()) >= pre(infix[i]))
                {
                    postfix[j++] = top_element();
                    pop();
                }
                push(infix[i++]);
            }
        }
        while (!isEmpty())
        {
            postfix[j++] = top_element();
            pop();
        }
        postfix[j] = '\0';

         return postfix;
    }
};

int main()
{
    char *infix = "a+b*(c^d-e)^(f+g*h)-i";
    int len = strlen(infix);
    Stack st(len);
    char *postfix = st.infixToPostfix(infix);
    cout << postfix << endl;

    return 0;
}
