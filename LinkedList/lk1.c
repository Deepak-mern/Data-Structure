#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *link;
};
struct node *start = NULL;
struct node *end;

struct node *GetNode()
{
    return ((struct node *)malloc(sizeof(struct node)));
}
void CreateList()
{
    char ch;
    struct node *I, *end = NULL;
    int newdata;
    if (start != NULL)
    {
        printf("\nLinked list has already been Created");
        return;
    }
    do
    {
        I = GetNode();
        if (start == NULL)
        {
            start = I;
        }
        else
        {
            end->link = I;
        }

        printf("\n Enter the elements to be inserted in the Linked list: ");
        scanf("%d", &(I->data));
        end = I;
        I->link = NULL;
        printf(" Do you want to add more modes (Y/N): ");
        ch = getch();
    }

    while (toupper(ch) == 'Y');
}
int countNodes()
{
    int count = 0;
    struct node *temp = start;
    while (temp != NULL)
    {
        count++;
        temp = temp->link;
    }
    return count;
}
void display()
{
    struct node *temp = start;
    if (start == NULL)
    {
        printf("\n Linked list has not be initiazed");
    }
    printf("\n Linked List Created is ");
    printf("\n start  ");
    while (temp != NULL)
    {
        printf("-> %d", temp->data);
        temp = temp->link;
    }
    printf("  ->End");
}
void insertBefore()
{
    int val;
    struct node *ptr = start;
    struct node *I;
    struct node *ptrBefore = start;
    if (start == NULL)
    {
        printf("\n linked list not creadted");
        return;
    }
    printf("\n Enter the value you want to insert Before the value: ");
    scanf("%d", &val);
    while (ptr->data != val)
    {
        ptr = ptr->link;
    }
    if (ptr == NULL)
    {
        printf("\n No such Value exists in Linked List");
        return;
    }
    I = GetNode();
    printf(" Enter the value Inserted before: ");
    scanf("%d", &I->data);
    if (ptr == start)
    {
        I->link = start;
        start = I;
    }
    while (ptrBefore->link != ptr)
    {
        ptrBefore = ptrBefore->link;
    }
    I->link = ptrBefore->link;
    ptrBefore->link = I;
}

void insertAfter()
{
    int val;
    struct node *ptr = start;
    struct node *I;
    if (start == NULL)
    {
        printf("\n linked list not creadted");
        return;
    }
    printf("\n Enter the value you want to insert After the value: ");
    scanf("%d", &val);

    while (ptr->data != val)
    {
        ptr = ptr->link;
    }
    if (ptr == NULL)
    {
        printf("\n Value not found!! please check the LinkedList");
        return;
    }
    I = GetNode();
    printf("Enter the value Inserted After:  ");
    scanf("%d", &I->data);
    I->link = ptr->link;
    ptr->link = I;
}
void InsertAtEnd()
{
    struct node *ptr = start;
    struct node *I;
    if (start == NULL)
    {
        printf("\n linked list not creadted");
        return;
    }
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    I = GetNode();
    printf("Enter the value Inserted End ");
    scanf("%d", &I->data);
    ptr->link = I;
    I->link = NULL;
}
void InsertAtposition()
{
    int position, count = 2, nodes;
    struct node *ptr = start;
    struct node *I;
    if (start == NULL)
    {
        printf("\n linked list not creadted");
        return;
    }
    display();
    nodes = countNodes();
    printf("enter a position between 1 and %d :", nodes + 1);
    scanf("%d", &position);
    if ((position > 0) && (position < nodes + 2))
    {
        I = GetNode();
        printf("Enter the value Inserted before ");
        scanf("%d", &I->data);

        if (position != 1)
        {
            while (count != position)
            {
                ptr = ptr->link;
                count++;
            }
            I->link = ptr->link;
            ptr->link = I;
        }
        else
        {
            I->link = start;

            start = I;
        }
    }
    else
    {
        printf("Invalid position !!!!\n");
    }
}
void Insertion()
{
    int choice;
    do
    {
        printf("\n\n------Insert Menu------\n");
        printf(" 1-- Insert At Position\n 2-- Insert At End\n 3-- Insert After Value \n 4-- Insert Before value \n 5-- Display Linked List\n 6-- Exit Insertion menu");
        printf("\nEnter Your choice -> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            InsertAtposition();

            break;
        case 2:
            InsertAtEnd();

            break;
        case 3:
            insertAfter();

            break;
        case 4:
            insertBefore();

            break;
        case 5:
            display();

            break;
        case 6:
            return;

            break;

        default:
            printf("Invalid Choice !!!");
            break;
        }
    } while (choice < 7);
}
void deleteByValue()
{
    int val;
    struct node *ptr = start;
    struct node *ptrBefore = start;
    display();
    printf("Enter the value to be Deleted");
    scanf("%d", &val);
    while (ptr->data != val)
    {
        ptr = ptr->link;
    }
    if (ptr == NULL)
    {
        printf("value not found");
        return;
    }
    if (ptr == start)
    {
        start = start->link;
        ptr->link = NULL;
        free(ptr);
        return;
    }
    while (ptrBefore->link != ptr)
    {
        ptrBefore = ptrBefore->link;
    }
    ptrBefore->link = ptr->link;
    ptr->link = NULL;
    free(ptr);
}
void DeleteAtposition()
{
    int count = 1, position;
    struct node *ptr = start;
    struct node *ptrBefore = start;
    int nodes = countNodes();
    display();
    printf("enter the position at which you want to delete");
    scanf("%d", &position);
    if ((position > 0) && (position < nodes + 1))
    {
        if (position == 1)
        {
            start = start->link;
            ptr->link = NULL;
            free(ptr);
        }
        else
        {
            while (count != position)
            {
                count++;
                ptr = ptr->link;
            }
            while (ptrBefore->link != ptr)
            {
                ptrBefore = ptrBefore->link;
            }
            ptrBefore->link = ptr->link;
            ptr->link = NULL;
        }
    }
    else
    {
        printf("Invalid Choice!!!");
    }
}

void sortLinkedList()
{
    struct node *ptr = start, *index = NULL;
    int temp;

    if (start == NULL)
    {
        printf("Linked List Is empty");
        return;
    }
    else
    {
        while (ptr != NULL)
        {
            index = ptr->link;

            while (index != NULL)
            {

                if (ptr->data > index->data)
                {
                    temp = ptr->data;
                    ptr->data = index->data;
                    index->data = temp;
                }
                index = index->link;
            }
            ptr = ptr->link;
        }
    }
    printf("\n The sorted linked List : ");
    display();
}
void Deletion()
{
    int choice;
    do
    {
        printf("\n\n------Delete Menu------\n");
        printf(" 1-- Delete At Position\n 2-- delete At value\n 3-- Display Linked List\n 4-- Exit Insertion menu");
        printf("\nEnter Your choice-> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            DeleteAtposition();

            break;
        case 2:
            deleteByValue();

            break;
        case 3:
            display();

            break;

        case 4:
            return;

            break;

        default:
            printf("\nInvalid Choice !!! Please enter a valid choice");
            break;
        }
    } while (choice < 5);
}
int main()
{

    int choice;
    do
    {
        printf("\n\n------Linked List Menu------\n");
        printf(" 1-- CreateLinkedList\n 2-- Insertion\n 3--Deletion \n 4-- SortlinkedList \n 5-- Dispaly Linked List\n 6--Exit ");
        printf("\n Enter Your choice-> ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            CreateList();

            break;
        case 2:
            Insertion();
            break;
        case 3:
            Deletion();

            break;
        case 4:
            sortLinkedList();
            break;
        case 5:
            display();

            break;
        case 6:
            exit(0);

            break;

        default:
            printf("Invalid Choice !!!");
            break;
        }
    } while (choice < 7);
}
