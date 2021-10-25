#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int cQuene[SIZE];
int front = -1;
int rear = -1;

void enquene(int data)
{
    if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;
        cQuene[rear] = data;
    }
    else if ((rear + 1) % SIZE == front)
    {
        printf("Quene is overflow");
    }
    else
    {
        rear = (rear + 1) % SIZE;
        cQuene[rear] = data;
    }
}

int dequeue()
{
    if ((front == -1) && (rear == -1)) //
    {
        printf("\nQueue is underflow..");
    }
    else if (front == rear)
    {
        printf("\nThe dequeued element is %d", cQuene[front]);
        front = -1;
        rear = -1;
    }
    else
    {
        printf("\nThe dequeued element is %d", cQuene[front]);
        front = (front + 1) % SIZE;
    }
}
void Display()
{
    int i = front;
    if (front == -1 && rear == -1)
    {
        printf("\n Quene is Empty");
    }
    else
    {
        printf("\n Elements in the Quene Are: ");
        while (i != rear)
        {
            printf("%d ", cQuene[i]);
            i = (i + 1) % SIZE;
        }
    }
}

int main()
{
    int choice, a;
    do
    {
        printf("\n ***** Circular Quene ****");
        printf("\n 1. Insert an Element");
        printf("\n 2. Delete an Element");
        printf("\n 3. Dispaly The Quene");
        printf("\n 4. Exit ");
        printf("\n Enter a choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the element to be inserted : ");
            scanf("%d", &a);
            enquene(a);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            Display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("Invalid Input");
            break;
        }

    } while (choice < 4);
    return 0;
}