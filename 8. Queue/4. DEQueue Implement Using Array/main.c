#include <stdio.h>
#include <stdlib.h>
struct DEQueue
{
    int size;
    int rear;
    int front;
    int *Q;
};

// Creating DEQueue
void CreateDeQueue(struct DEQueue *q, int sz)
{
    q->size = sz;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(sizeof(q->size));
}

// Display DEQueue
void display(struct DEQueue *q)
{
    for (int i = q->front + 1; i <= q->rear; i++)
        printf("%d ", q->Q[i]);
    printf("\n");
}
// Insert at last  in DEQueue
void enqueuerear(struct DEQueue *q, int value)
{
    if (q->rear == q->size - 1)
        printf("DEQue is Full\n");
    else
    {
        q->rear++;
        q->Q[q->rear] = value;
    }
}

// // Insert at last  in DEQueue
void enqueuefront(struct DEQueue *q, int value)
{
    if (q->front == -1)
        printf("Not Inserted In First\n");
    else
    {
        q->Q[q->front] = value;
        q->front--;
    }
}

// Delete from first
int dequeuefront(struct DEQueue *q)
{
    int x = -1;
    if (q->front == q->rear)
        printf("DEQueue is Empty\n");
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

// Delete from last
int dequeuerear(struct DEQueue *q)
{
    int x = -1;
    if (q->rear == -1)
        printf("DEQueue is Empty\n");
    else
    {
        x = q->Q[q->rear];
        q->rear--;
    }
    return x;
}
int main()
{
    struct DEQueue d;
    CreateDeQueue(&d, 7);
    enqueuerear(&d, 10);
    enqueuerear(&d, 20);
    enqueuerear(&d, 30);
    enqueuerear(&d, 40);
    display(&d);
    printf("%d\n", dequeuefront(&d));
    printf("%d\n", dequeuefront(&d));
    display(&d);
    enqueuefront(&d, 10);
    enqueuefront(&d, 40);
    display(&d);
    dequeuerear(&d);
    dequeuerear(&d);
    display(&d);

    return 0;
}
/*
output :
10 20 30 40
10
20
30 40
40 10 30 40
40 10
*/