#include <stdio.h>
int top;

int stack[10];
int push(int a);
int pop();
int isEmpty();
int Exit();
int peek();
void display();
int c;

int main()

{
    int top = -1;

    int choice;

    

    while (choice != 6)
    {

        printf("\n*****Menu****\n");
        printf("Enter The Choice\n1.Push\n2.Pop\n3.Peek\n4.IsEmpty\n5.exit\n6.Display The stack");

        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(c);
            break;
        case 2:
            pop();
            break;
        case 3:

            peek();

            break;
        case 4:
            isEmpty();
            break;
        case 5:
            Exit();
            break;

        case 6:
            display();
            break;

        default:
            printf("Invalid operator");
            break;
        }
    }

    return 0;
}
int push(int a)
{
    if (top >= (9))
    {
        printf("STACK oVERFLOW\n");
    }
    else
    {
        printf("enter the value to push");
        scanf("%d", &c);
        top++;
        stack[top] = a;
        printf("element %d is pushed inn stack", a);
    }
}
int pop()
{
    if (top < 0)
    {
        printf("Stack is empty");
    }
    else
    {
        int a = stack[top--];
        return a;
    }
}

int isEmpty()
{
    return (top < 0);
}
int Exit()
{
    return 0;
}
int peek()
{

    printf("The value at the top is %d", stack[top]);
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
