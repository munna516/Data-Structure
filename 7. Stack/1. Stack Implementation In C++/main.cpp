#include <bits/stdc++.h>
using namespace std;
const int max_size = 500;

// Stack Implementaion Using Static Array
class Stack_Static_Array
{
public:
    int A[max_size];
    int stack_size;
    // Constructor
    Stack_Static_Array()
    {
        stack_size = 0;
    }

    // Adding Element At Stack
    void push(int value)
    {
        if (stack_size + 1 > max_size)
        {
            cout << "Stack is Full" << endl;
            return;
        }
        stack_size++;
        A[stack_size - 1] = value;
    }

    // Deleting Element At a Stack
    void pop()
    {
        if (stack_size == 0)
        {
            cout << "Stack is Empty!" << endl;
            return;
        }
        A[stack_size - 1] = 0;
        stack_size--;
    }

    // Top Element
    int Top()
    {
        if (stack_size == 0)
            return -1;
        return A[stack_size - 1];
    }
};
int main()
{
    Stack_Static_Array st;
    // st.push(10);
    cout << st.Top() << endl;
    st.push(20);
    st.push(30);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    return 0;
}