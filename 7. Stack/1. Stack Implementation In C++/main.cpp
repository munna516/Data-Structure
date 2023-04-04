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

// Stack Implementation Using Dynamic Array
class Stack_Dynamic_Array
{
public:
    int *A;
    int array_cap;
    int stack_size;
    Stack_Dynamic_Array()
    {
        A = new int[1];
        array_cap = 1;
        stack_size = 0;
    }

    // Increasing Array
    void Increase_Array()
    {
        int *temp;
        temp = new int[array_cap * 2];
        for (int i = 0; i < array_cap; i++)
            temp[i] = A[i];
        swap(A, temp);
        delete[] temp;
        array_cap = array_cap * 2;
    }

    // Adding Element At Stack
    void push(int value)
    {
        if (stack_size + 1 > array_cap)
        {
            Increase_Array();
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
    Stack_Dynamic_Array st;
    st.push(100);
    cout << st.Top() << endl;
    st.push(20);
    st.push(30);
    cout << st.Top() << endl;
    st.pop();
    cout << st.Top() << endl;
    return 0;
}