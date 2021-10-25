#include <stdio.h>
#define MAX 5
void enque(int a);
void deque();
void display();
int Quene[MAX], rear = -1, front = -1;

void main()
{
    enque(4);
    enque(3);
    enque(2);
    enque(1);
    enque(1);
    display();
    deque();
    display();
};

void enque(int a)
{
    if (rear == MAX - 1)
    {
        printf("thr Quene is full\n");
    }
    else
    {
        if (front == -1)
            front == 0;
        rear++;
        Quene[rear] = a;
        printf("inserted value is %d\n", a);
    }
}
void deque()
{
    if (front == -1)
    {
        printf("Quene Underflow \n");
    }
    else
    {
        printf("element deleted is :%d \n", Quene[front]);
        front++;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
}

void display()
{
    if (rear == -1)
    {
        printf("Quene is empty\n");
    }
    else
    {
        printf("Quene is \n:");
        for (int i = 0; i <= rear; i++)
        {
            printf("%d->", Quene[i]);
        }
    }
}