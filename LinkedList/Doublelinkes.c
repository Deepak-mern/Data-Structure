#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    struct node *next;
    int data;

} struct node *head;
void insertBegin();
void insertLast();
void insertSpecific();
void deleteStart();
void deleteLast();
void deleteSpecified();
void Display();
void search();
void main()
{
}
void insertBegin()
{
    struct node *ptr;
    int data;
    ptr = (struct node *)malloc(size of(struct node));
    if (ptr == NULL)
    {
        printf("\n Overflow ");
    }
    else
    {
        printf("\n Enter the data");
        scanf("%d", &data);

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = data;
            head = ptr;
        }
        else
        {
            ptr->data = data;
            ptr->prev = NULL;
            ptr->next = head;
            head = ptr;
        }
    }
}
void insertLast()
{
    struct node *ptr, *temp;
    int data1;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n Overflow ");
    }
    else
    {
        printf("\n Enter the data");
        scanf("%d", &data1);
        ptr->data = NULL;

        if (head == NULL)
        {
            ptr->next = NULL;
            ptr->prev = NULL;
            ptr->data = data1;
            head = ptr;
        }
        else
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            ptr->next = NULL;
        }
    }
}
void insertSpecific()
{
    struct node *ptr, *temp;
    int data, location, i;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\n Overflow");
    }
    else
    {
        temp = head;
        printf("Enter the location");
        scanf("%d ", &location);
        for (i = 0; i < location; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\n There are less elements");
                return;
            }
        }
        printf("Enter the value: ");
        scanf("%d ", &data);
        ptr->data = data;
        ptr->next = temp->next;
        ptr->prev = temp;
        temp->next = ptr;
        temp->next->prev = ptr;
    }
}
void deleteStart()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n Overflow");
        {
        }
        else if (head->next == NULL)
        {
            head = NULL;
            free(head);
            printf("\n Node Deleted");
        }
        else
        {
            ptr = head;
            head = head->next;
            head->prev = NULL;
            free(ptr);
            printf("\n Node Deleted")
        }
    }
}
void deleteLast()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\n Underflow");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        printf("\n Node Deleted");
    }
    else
    {
        ptr = head;
        if (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = NULL;
        free(ptr);
        printf("\n Node Deleted");
    }
}
void deleteSpecified()
{
    struct node *ptr, *temp;
    int value;
    printf("\n Enter the data after which to deleted");
    scanf("%d", &value);
    ptr = head;
    while (ptr->data != value)
        ptr = ptr->next;
    if (ptr->next == NULL)
    {
        printf("\n Cannot delete")
    }
    else if (ptr->next->next == NULL)
    {
        ptr->next == NULL;
    }
    else
    {
        temp = ptr->next;
        ptr->next = temp->next;
        temp->next->prev = ptr;
        free(temp);
        printf("\n Node Deleted");
    }
}
void display()
{
    struct node *ptr;
    printf("\n printing Values");
    ptr = head;
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}
