#include <stdio.h>
#include <stdlib.h>

#define M 5

struct que
{
    char arr[M];
    int front, rear;
};

typedef struct que Queue;

void init(Queue *q)
{
    q->front = q->rear = -1;
}

int isFull(Queue *q)
{
    return q->rear == M - 1 ? 1 : 0;
}

int isEmpty(Queue *q)
{
    return q->rear == -1 && q->front == -1 ? 1 : 0;
}

void enqueue(Queue *q, char x)
{
    if (isFull(q))
        printf("Queue overflows\n");

    else
    {
        q->front = 0;
        q->rear++;
        q->arr[q->rear] = x;
    }
}

void dequeue(Queue *q)
{
    if (isEmpty(q))
        printf("Queue underflows\n");

    else
        q->front += 1;
}

void display(Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
        return;
    }

    for (int i = q->front; i <= q->rear; i++)
        printf("%c ", q->arr[i]);
}

int main()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    init(q);

    enqueue(q, 'A');
    enqueue(q, 'B');
    enqueue(q, 'C');
    enqueue(q, 'D');
    enqueue(q, 'E');
    dequeue(q);

    display(q);
}