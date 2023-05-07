#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};

// Creating Queue
void CreateQueue(struct Queue *q, int size)
{

    q->size = size;
    q->Q = (int *)malloc(q->size * sizeof(int));
    q->front = 0;
    q->rear = 0;
}

// Display Queue
void display(struct Queue q)
{
    int i = q.front + 1;
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);

    printf("\n");
}
// Inserting in queue
void enqueue(struct Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
        printf("Queue is Full\n");
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x;
    }
}

// Delete from queue
int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->rear == q->front)
        printf("Queue is Empty!!\n");
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front];
    }
    return x;
}
int main()
{
    struct Queue q;
    CreateQueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 30);
    enqueue(&q, 50);
    enqueue(&q, 70);
    enqueue(&q, 80);
    enqueue(&q, 90);
    enqueue(&q, 100);
    enqueue(&q, 810);
    display(q);

    return 0;
}