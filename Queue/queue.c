#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define M 5

struct que
{
	char arr[M];
	int rear, front;
};

typedef struct que Queue;

void initialize(Queue *q);
int isFull(Queue *q);
int isEmpty(Queue *q);
void dispqueue(Queue *q);
void enqueue(Queue *q, char v);
char dequeue(Queue *q);

int main()
{
	Queue *q;
	char r, v;
	int choice, val;

	q = (Queue *)malloc(sizeof(Queue));
	do
	{
		system("cls");
		printf("\n----Menu----");
		printf("\n1:Initialize queue");
		printf("\n2:Disp queue");
		printf("\n3:Insert an elelement");
		printf("\n4:Delete an element");
		printf("\n5:Exit");
		printf("\nEnter you choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			system("cls");
			initialize(q);
			break;
		case 2:
			system("cls");
			dispqueue(q);
			getch();
			break;
		case 3:
			system("cls");
			fflush(stdin);
			printf("\nEnter value:");
			scanf("%c", &v);
			enqueue(q, v);
			getch();
			break;
		case 4:
			system("cls");
			r = dequeue(q);
			printf("%c is deleted", r);
			getch();
			break;
		case 5:
			printf("good bye");
			break;
		}
	} while (choice != 5);
	return (1);
}

void initialize(Queue *p)
{
	if (p == NULL)
	{
		printf("Memory not available");
		exit(0);
	}
	else
	{
		p->rear = -1;
		p->front = 0;
	}
}

void dispqueue(Queue *p)
{
	int i, n;

	system("cls");
	printf("\n");
	if (isEmpty(p))
	{
		printf("Queue is empty");
		return;
	}
	for (i = p->front; i <= p->rear; i++)
		printf("%c  ", p->arr[i]);
}

int isFull(Queue *p)
{
	return (p->rear == M - 1 ? 1 : 0);
}

int isEmpty(Queue *p)
{
	return (p->rear == -1 && p->front == 0 ? 1 : 0);
}

void enqueue(Queue *p, char v)
{
	if (isFull(p))
		printf("\nQueue overflows");
	else
	{
		p->rear++;
		p->arr[p->rear] = v;
	}
}

char dequeue(Queue *p)
{
	char t;
	if (isEmpty(p))
	{
		printf("\nQueue underflows");
		return '\0';
	}
	else
	{
		t = p->arr[p->front];
		p->front++;
		if (p->front > p->rear)
		{
			p->rear = -1;
			p->front = 0;
		}
	}
	return (t);
}
