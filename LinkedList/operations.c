#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void  insertAtBegining(struct Node **headref, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = (*headref);
    (*headref) = newNode;
}
void insertAfter(struct Node *prenode, int newData)
{
    if (prenode == NULL)
    {
        return;
    }
    else
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = newData;
        newNode->next = prenode->next;
        prenode->next = newNode;
    }
}
void insertAtEnd(struct Node **headref, int newData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *headref;
    newNode->data = newData;
    newNode->next = NULL;

    if (*headref == NULL)
    {
        *headref = newNode;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
    return;
}
void delete (struct Node **headref, int key)
{
    struct Node *temp = *headref, *prev;

    if (temp != NULL && temp->data == key)
    {
        *headref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;

    prev->next = temp->next;
    free(temp);
}
int searchNode(struct Node **headref, int key)
{
    struct Node *current = *headref;
    while (current != NULL)
    {
        if (current->data == key)  return 1;
     current = current->next;
    }
    return 0;
}
void display(struct Node *node)
{
    while (node != NULL)
    {
        printf(" %d ", node->next);
        node = node->next;
    }
}
int main()
{

    struct Node *head = NULL;
    insertAtBegining(&head, 1);
    insertAtBegining(&head, 2);
    insertAtEnd(&head, 4);
    insertAfter(head->next, 5);
    display(head);

    return 0;
}