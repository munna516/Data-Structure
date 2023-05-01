#include <bits/stdc++.h>
using namespace std;
class Stack
{
public:
    int size;
    int top;
    int *s;
    Stack()
    {
        size = 0;
    }

    // Creating Stack
    void CreateStack()
    {
        cout << "Enter the size of stack : ";
        cin >> size;
        s = new int[size];
        top = -1;
    }

    // display
    void display()
    {
        for (int i = top; i >= 0; i--)
            cout << s[i] << " ";
        cout << endl;
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

    // Peek a particular index
    int peek(int pos)
    {
        int x = top - pos + 1;
        if (x < 0)
            cout << "Invalid Index" << endl;
        else
            return s[x];
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
};

int main()
{
    Stack st;
    st.CreateStack();
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);

    return 0;
}