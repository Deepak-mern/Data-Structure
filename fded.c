#include <stdio.h>

int top = -1;
char stack[100];
void push(char);
void pop();
void Peek();

int main()
{
    char a[100];
    printf("Enter The Expression");
    scanf("%s",a);
    for (int i = 0; a[i] != '\0'; i++)
    {

        if (a[i] == '(')
        {
            push(a[i]);
        }
        else if (a[i] == ')')
        {
            pop();
        }
    }

    return 0;
}

void push(char a)
{

    {
        stack[top] = a;
        top++;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("stack is empty ");
     
    }
    else
    {
        top--;
    }
}
void Peek()
{
    if (top == -1)
    {
        printf("Matched");
    }
    else
    {
        printf(" no Matched");
    }
}