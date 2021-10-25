#include <stdio.h>
#define SIZE 100
int elem[SIZE];
int front = -1;
int rear = -1;
int i;
int isFull()
{
    if ((front == rear + 1) || (front == 0 && rear == SIZE - 1))
    {
        return 1;
    }
    return 0;
}
int isEmpty()
{
    if (front == -1)
        return 1;
    return 0;
}

void enQuene(int data)
{
    if (isFull())
    {
        printf("\n Quene is full");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        elem[rear] = data;
        printf("\n inserted Element uis : %d\n ", data);
    }
}
int deQuene()
{
    int data;
    if (isEmpty())
    {
        printf("\n Quene Is empty ");
        return (-1);
    }
    else
    {

        data = elem[rear];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % SIZE;
        }
        printf("\n Deleted element is : %d", data);
        return (data);
    }
}

void display()
{
    if (isEmpty())
    {
        printf("\n Quene Is Empty");
    }
    else
    {
        printf("\n Elements in Queene are: ");

        while (i <= rear)
        {
            printf("%d ", elem[i]);
            i = (i + 1) % SIZE;
        }
    }
}

int main()
{
    enQuene(1);
    enQuene(8);
    enQuene(7);
    enQuene(3);
    enQuene(2);
    display();
    deQuene();
    deQuene();
    enQuene(5);

    display();
}