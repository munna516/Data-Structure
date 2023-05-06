#include <bits/stdc++.h>
using namespace std;
class Queue
{
private:
    int size;
    int front;
    int rare;
    int *Q;

public:
    Queue(int size)
    {
        this->size = size;
        front = rare = -1;
        Q = new int[this->size];
    }

    void display()
    {
        for (int i = front + 1; i <= rare; i++)
            printf("%d ", Q[i]);
        printf("\n");
    }
    // Inserting in queue
    void enqueue(int x)
    {
        if (rare == size - 1)
            printf("Queue is Full\n");
        else
        {
            rare++;
            Q[rare] = x;
        }
    }

    // Delete from queue
    int dequeue()
    {
        int x = -1;
        if (rare == front)
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