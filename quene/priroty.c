#include <stdio.h>
#include <stdlib.h>

#define MAX 5

void insert(int);
void delete (int);
void check(int);
void highpirority();
void create();
void Lowestpirority();
void display();

int pri_que[MAX];
int front, rear;

void main()
{
    int n, ch;

    printf("\n1 Insert an element into queue");
    printf("\n2 Delete an element from queue");
    printf("\n3 Display queue elements");
    printf("\n4 Display Highest Pirority");
    printf("\n5 Display Lowest Pirority");
    printf("\n4 Exit");

    create();

    do
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter value to  inserted : ");
            scanf("%d", &n);
            insert(n);
            break;
        case 2:
            printf("\nEnter value to delete : ");
            scanf("%d", &n);
            delete (n);
            break;
        case 3:
            display();
            break;
        case 4:
            highpirority();
            break;
        case 5:
            Lowestpirority();
            break;
        case 6:
            exit(0);
        default:
            printf("\nChoice is invalid, Enter a correct choice");
        }
    } while (ch < 6);

}



void insert(int data)
{
    if (rear >= MAX - 1)
    {
        printf("\nQueue overflow ");
        return;
    }
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        pri_que[rear] = data;
        return;
    }
    else
        check(data);
    rear++;
}

void check(int data)
{
    int i, j;

    for (i = 0; i <= rear; i++)
    {
        if (data >= pri_que[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                pri_que[j] = pri_que[j - 1];
            }
            pri_que[i] = data;
            return;
        }
    }
    pri_que[i] = data;
}

void delete (int data)
{
    int i;

    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty ");
        return;
    }

    for (i = 0; i <= rear; i++)
    {
        if (data == pri_que[i])
        {
            for (int i; i < rear; i++)
            {
                pri_que[i] = pri_que[i + 1];
            }

            pri_que[i] = -999;
            rear--;

            if (rear == -1)
                front = -1;
            return;
        }
    }
    printf("\n%d not found in queue ", data);
}

void display()
{
    if ((front == -1) && (rear == -1))
    {
        printf("\nQueue is empty");
        
    }
    printf("\n Quene in Pirorty Quene");

    for (int front; front <= rear; front++)
    {
        printf(" %d ", pri_que[front]);
    }

    front = 0;
}
void highpirority(){
    printf("\n Highest Pirority : %d ", pri_que[0]);
}
void Lowestpirority(){
    printf("\n Lowest Pirority : %d ", pri_que[rear]);
}
void create()
{
    front = rear = -1;
}