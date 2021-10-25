#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertatbegin(struct node **head_ref, int new_item)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_item;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}
void insertafter(struct node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("Head node cannot be emptty");
        return;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}
void insertatend(struct node **head_ref, int new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;
    return;
}
void delete (struct node **head_ref, int key)
{
    struct node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
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
void printlist(struct node* Node){
    while (Node != NULL)
    {
        printf(" %d ", Node->data);
        Node = Node->next;
    }
    
}


int main()
{
     struct node* head =NULL;
     insertatbegin(&head, 1);
     insertatbegin(&head, 2);
     insertatbegin(&head, 3);
     insertatbegin(&head, 4);
     printf("Linked List: ");
     printlist(head);

     
    
     printf("\n after deleting the items");
     delete(&head,3);
     printlist(head);

    return 0;
}