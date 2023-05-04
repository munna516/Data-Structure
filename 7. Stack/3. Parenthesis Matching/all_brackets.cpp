#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int size;
    int top;
    char *s;
    Stack()
    {
        size = 0;
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
    int pop()
    {
        int x = -1;
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
    // Check Bracket
    int check(char c)
    {
        if ((c == ')' && top_element() == '(') || (c == '}' && top_element() == '{') || (c == ']' && top_element() == '['))
            return 1;
        else
            return 0;
    }
    // Parenthesis Matching
    int isBalanced(char *exp)
    {
        size = strlen(exp);
        top = -1;
        s = new char[size];
        for (int i = 0; exp[i] != '\0'; i++)
        {
            if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
                push(exp[i]);
            else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
            {
                if (isEmpty())
                    return 0;
                else
                {
                    int x = check(exp[i]);
                    if (x)
                        pop();
                }
            }
        }
        if (isEmpty())
            return 1;
        else
            return 0;
    }
};

int main()
{
    Stack s;
    char *exp = "[{(a+b*c-(b-d+c)}]";
    cout << s.isBalanced(exp) << endl;

    return 0;
}