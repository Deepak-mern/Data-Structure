#include <stdio.h>
#define SIZE 10
void enque(int);
void deQuene();
void display();

int arrq[SIZE], front = -1, rear = -1;
void main()
{
    int choice, a;
    do
    {
        printf("\n ***** Linear Quene ****");
        printf("\n 1. Insert an Element");
        printf("\n 2. Delete an Element");
        printf("\n 3. Dispaly The Quene");
        printf("\n Enter a choice");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n Enter the element to be inserted : ");
            scanf("%d", &a);
            enque(a);
            break;
        case 2:
            deQuene();
            break;
        case 3:
            display();
            break;
        default:
            printf("Invalid Input");
            break;
        }
        
        
    }while (choice <4 );
    

}

void enque(int value)
{
    if (rear == SIZE - 1)
    {
        printf("\n Quene is Full");
    }
    else
    {
        if (front == -1)
            front = 0;
        rear++;
        arrq[rear] = value;
        printf("\n insereted item is %d", value);
    }
}
void deQuene()
{
    if (front == -1)
    {
        printf("\n Quene is empty");
    }
    else
    {
        printf("\n deleted : %d", arrq[front]);
        front++;
        if (front > rear)
            front = rear = -1;
    }
}
void display()
{
    if (rear == -1)
    {
        printf("\n Quene is Empty!  \n");
    }
    else
    {
        printf("\n Elements in Quene Re: ");
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", arrq[i]);
        }
    }
}