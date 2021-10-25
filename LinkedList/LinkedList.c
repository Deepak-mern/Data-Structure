#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void beginAtStart();
void lastInsert();
void randomInsert();
void deleteAtBegin();
void EndDelete();
void Randomdelete();
void dislay();
void search();

void main()
{
    int choice = 0;
    while (choice != 10)
    {
        printf("\n      Main Menu      ");
        printf("\n choose thr Option  ");

        printf("\n 1.insert at start \n 2Insert at last \n 3. Insert at Random position \n 4. Delete from begining \n 5. Delete from last \n 6.Delete node at specified location\n 7.Search for element  \n 8.Show \n 9.Exit");
        printf("\n Enter Your Choice ");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            beginAtStart();
            break;
        case 2:
            lastInsert();
            break;

        case 3:
            randomInsert();
            break;
        case 4:
            deleteAtBegin();
            break;

        case 5:
            EndDelete();
            break;

        case 6:
            Randomdelete();
            break;
        case 7:
            search();
            break;

        case 8:
            dislay();
            break;
        case 9:
            exit;

        default:
            printf("Invalid Input");
            break;
        }
    }
}

void beginAtStart()
{

    struct node *ptr;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("\n Overflow");
    }
    else
    {
        printf("\n Enter the value");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        printf("\n Node inserted Sucessfully");
    }
}
void lastInsert()
{
    struct node *ptr, *temp;
    int item;
    char ans;
    do
    {
        ptr = (struct node *)malloc(sizeof(struct node *));
        if (ptr == NULL)
        {
            printf("\n Overflow");
        }
        else
        {

            printf("\n Enter the value");
            scanf("%d", &item);
            ptr->data = item;
            if (head == NULL)
            {
                ptr->next = NULL;
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
                ptr->next = NULL;
                printf("\n Node inserted");
            }
        }
        printf("Do yo want to add more  nodes");
        scanf("%c", &ans);
    } while (ans == 'Y');
}
void randomInsert()
{
    int i, location, item;
    struct node *ptr, *temp;
    ptr = (struct node *)malloc(sizeof(struct node *));
    if (ptr == NULL)
    {
        printf("\n Overflow");
    }
    else
    {

        printf("\n enter element vaue");
        scanf("%d", &item);
        ptr->data = item;
        printf("\n Enter The location ");
        scanf("%d ", &location);
        temp = head;
        for (i = 0; i < location; i++)
        {
            temp = temp->next;
            if (temp == NULL)
            {
                printf("\n cannot inserted");
                return;
            }
        }
        ptr->next = temp->next;
        temp->next = ptr;
        printf("\n node inserted");
    }
}
void deleteAtBegin()
{

    struct node *ptr;
    if (head == NULL)
    {
        printf("\n List is Empty");
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        printf("\n Node at begin is deleted");
    }
}
void EndDelete()
{

    struct node *ptr, *ptr1;
    if (head == NULL)
    {
        printf("\n list is empty");
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr1 = ptr;
            ptr = ptr->next;
        }
        ptr1->next = NULL;
        free(ptr);
        printf("Node at Last is deleted");
    }
}
void Randomdelete()
{

    struct node *ptr, *ptr1;
    int location, i;
    printf("Enter the location of the Node To be deleted");
    scanf("%d", &location);
    ptr = head;
    for (i = 0; i < location; i++)
    {
        ptr1 = ptr;
        ptr = ptr->next;

        if (ptr == NULL)
        {
            printf("\n cant Delete");
            return;
        }
        else
        {

            ptr1->next = ptr->next;
            free(ptr);
        }
    }
}
void search()
{
    struct node *ptr;
    int item, i = 0, flag;
    ptr = head;
    if (ptr == NULL)
    {
        printf("\n Empty list");
    }
    else
    {
        printf("Enter the element to search");
        scanf("%d", &item);
        while (ptr != NULL)
        {
            if (ptr->data == item)
            {
                printf("found at %d", i + 1);
                flag = 0;
            }
            else
            {
                flag = 1;
            }
            i++;
            ptr = ptr->next;
        }
        if (flag == 1)
        {
            printf("\n Item not found");
        }
    }
}
void dislay()
{
    struct node *ptr;
    ptr = head;
    if (ptr == NULL)
    {
        printf("Nothing to print");
    }
    else
    {
        printf("\n Printing ...");
        while (ptr != NULL)
        {
            printf("\n %d ->", ptr->data);
            ptr = ptr->next;
        }
    }
}