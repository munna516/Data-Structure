#include <stdio.h>
#include <stdlib.h>
struct Queue
{
    int size;
    int front;
    int rare;
    int *Q;
};

// Creating Queue
void CreateQueue(struct Queue *q, int size)
{

    q->size = size;
    q->Q = (int *)malloc(q->size * sizeof(int));
    q->front = -1;
    q->rare = -1;
}

// Display Queue
void display(struct Queue q)
{
    for (int i = q.front + 1; i <= q.rare; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
}
// Inserting in queue
void enqueue(struct Queue *q, int x)
{
    if (q->rare == q->size - 1)
        printf("Queue is Full\n");
    else
    {
        q->rare++;
        q->Q[q->rare] = x;
    }
}

// Delete from queue
int dequeue(struct Queue *q)
{
    int x = -1;
    if (q->rare == q->front)
        printf("Queue is Empty!!\n");
    else
    {
        q->front++;
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
    display(q);
    printf("%d\n", dequeue(&q));
    return 0;
}