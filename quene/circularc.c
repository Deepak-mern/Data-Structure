#include <stdio.h>
#define SIZE 10
int arrq[SIZE], front = -1, rear = -1;
void enquene(int value)
{
    if (front == -1 && rear == -1)
    {
        front = rear = 0;
    }
    else if ((rear + 1) % SIZE == front)
    {
        printf("Quene is fukll");
    }
    else
    {
        rear = (rear + 1) % SIZE;
        arrq[rear] = value;
    }
}
int dequene()
{
    if ((front == -1) && (rear == -1))
    {
        printf("Quene is underflow");
    }
    else if (front == rear)
    {
        printf("\n the dequene element is %d :", arrq[front]);
        front = (front + 1) % SIZE;
    }
}
void display()
{
    if (front == -1 && rear == -1)
    {
        printf("\n Quene is empty");
    }
    else
    {
        printf("\n Elements in the Cquene are :");
        while (front <= rear)
        {
            printf("%d ", arrq[front]);
            front = (front + 1) % SIZE;
        }
    }
}
int main()
{
}