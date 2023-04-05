#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *next;
};

class Stack
{
private:
    node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void Display()
    {
        node *p = top;
        while (p != NULL)
        {
            cout << p->data << " ";
            p = p->next;
        }
        printf("\n");
    }

    // Pushing in Stack
    void push(int x)
    {
        node *t = new node;
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
        node *p = top;
        if (top == NULL)
            cout << "Stack is Empty!!" << endl;
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
        node *p = top;
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
};

int main()
{
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.Display();
    cout << st.peek(3) << endl;

    return 0;
}