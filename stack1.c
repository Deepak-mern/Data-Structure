#include <stdio.h>
#define MAX 100
int stack[MAX];
int choice, n, top, x;

void push();
void pop();
void display();
void peek();

int main()
{

    top = -1;
    do
    {

        printf("\n*****Menu****\n");
        printf("Enter The Choice\n1.Push\n2.Pop\n3.Peek\n4.6.Display The stack\n5.exit\n");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;

        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:

            break;

        default:
            printf("Invalid operator");
            break;
        }
    } while (choice != 4);
    return 0;
}
void push()
{
    if (top >= (MAX - 1))
    {
        printf("\nStack Overflow");
    }
    else
    {
        printf("Enter a value to be pushed :  ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top <= 0)
    {
        printf("\nStack UnderFlow");
    }
    else
    {
        printf("\nThe popped element is %d", stack[top]);
        top--;
    }
}
void display()
{
    if (top >= 0)
    {
        printf("\n Elements in the stack\n\n");
        for (int i = top; i >= 0; i--)
        {
            printf("%d\t", stack[i]);
        }
    }
    else
    {
        printf("\nStack is Empty\n");
    }
}
void peek()
{
    if (top <= -1)
    {
        printf("\n The stack Is Empty");
    }
    else
    {

        printf("\nThe value at the top of the stack is %d\n", stack[top]);
    }
}