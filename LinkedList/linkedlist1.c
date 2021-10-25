#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *head;


void InsertAtBegining();
void InsertAtLast();

void main()
{
}
struct node *GetNode()
{

    return (struct node *)malloc(sizeof(struct node *));
}
void InsertABegining()
{
}
void CreateList()
{
    struct Node *I;
    int x;
    char ch;
    if (head != NULL)
    {
        printf("\n The linked list is already Created");
        return;
    }
    do
    {
        I = GetNode();
        printf("\n Enter the data to be entered");
        scanf("%d", &x);
        I->data=x;
    }
}