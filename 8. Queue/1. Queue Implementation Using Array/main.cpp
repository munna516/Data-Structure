#include <bits/stdc++.h>
using namespace std;
class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        Q = new int[this->size];
    }

    void display()
    {
        for (int i = front + 1; i <= rear; i++)
            printf("%d ", Q[i]);
        printf("\n");
    }
    // Inserting in queue
    void enqueue(int x)
    {
        if (rear == size - 1)
            printf("Queue is Full\n");
        else
        {
            rear++;
            Q[rear] = x;
        }
    }

    // Delete from queue
    int dequeue()
    {
        int x = -1;
        if (rear == front)
            printf("Queue is Empty!!\n");
        else
        {
            front++;
            x = Q[front];
        }
        return x;
    }
};
int main()
{
    Queue q(7);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.display();
    cout << q.dequeue() << endl;

    return 0;
}