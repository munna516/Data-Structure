#include <bits/stdc++.h>
using namespace std;
class Stack
{
private:
    int size;
    int top;
    int *s;

public:
    Stack(int sz)
    {
        size = sz;
        top = -1;
        s = new int[size];
    }

    // Pushing element
    void push(int value)
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
    int top_element()
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

    // Check operator or operand
    int isOperand(char x)
    {
        if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^' || x == '(' || x == ')')
            return 0;
        else
            return 1;
    }

    // Evaluation of Postfix Expression
    int EvaluationOfPostfix(char *postfix)
    {
        int x1, x2, r = 0;
        for (int i = 0; postfix[i] != '\0'; i++)
        {
            if (isOperand(postfix[i]))
                push(postfix[i] - '0');
            else
            {
                x2 = pop();
                x1 = pop();
                switch (postfix[i])
                {
                case '+':
                    r = x1 + x2;
                    break;
                case '-':
                    r = x1 - x2;
                    break;
                case '*':
                    r = x1 * x2;
                    break;
                case '/':
                    r = x1 / x2;
                    break;
                }
                push(r);
            }
        }
        return pop();
    }
};

int main()
{
    char *postfix = "234*+82/-";
    int len = strlen(postfix);
    Stack st(len);
    int result = st.EvaluationOfPostfix(postfix);
    cout << result << endl;

    return 0;
}
