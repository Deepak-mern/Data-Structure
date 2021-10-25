#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE 50

char stack[SIZE];
int top = -1;

int push(char a)
{
    stack[++top] = a;
}
char pop()
{
    return (stack[top--]);
}
int precdence(char symbol)
{

    if (symbol == '^')
        return 3;
    else if (symbol == '*' || symbol == '/')
    {
        return 2;
    }
    else if (symbol == '+' || symbol == '-')
        return 1;
    else
        return 0;
}
int main()
{
    char infix[50], prefix[50], ch, elem;
    int k =0;int i = 0;
    printf("Enter the infix: ");
    scanf("%s",infix);
    
    push('$');
    strrev(infix);
    while ((ch = infix[i++]) != '\0')
    {
        if (ch == ')')
            push(ch);
        else if (isalnum(ch))
            prefix[k++] = ch;
        else if (ch == '(')
        {
            while (stack[top] != ')')
            {
                prefix[k++] = pop();
            }
            elem = pop();
        }
        else
        {
            while (precdence(stack[top]) >= precdence(ch))
                prefix[k++] = pop();
            push(ch);
        }
    }
    while (stack[top]!='$')
    {
        prefix[k++]=pop();

    }
    prefix[k]='\0';
    strrev(prefix);
    printf("The prefix Expression is : %s",prefix);
}
