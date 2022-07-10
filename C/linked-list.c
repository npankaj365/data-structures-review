#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;


node* create_list(int n)
{
    node *list = malloc(sizeof(node));
    list->data = n;
    list->next = NULL;
    return list;
}

node* append_list(node *head, int n)
{ 
    printf("Appending %d\n", n);
    node *new_node = malloc(sizeof(node)); 
    new_node->data = n;
    new_node->next = NULL;
    head->next =  new_node;
    return new_node;
}

void delete_item(node *ptr, int n)
{
    while(ptr != NULL)
    {
        if(ptr->next->data == n)
        {
            printf("Deleting %d\n", n);
            ptr->next = ptr->next->next;
            break;
        }
        ptr = ptr->next;
    }
}

void traverse_list(node *ptr)
{
    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(void)
{
    node *list = create_list(4);
    node *head = list;

    // Inserting items into the Linked List
    list = append_list(list, 5);
    list = append_list(list, 6);
    list = append_list(list, 7);

    // Printing items from the Linked List
    traverse_list(head);

    // Deleting item
    delete_item(head, 5);
    traverse_list(head);
    delete_item(head, 6);
    traverse_list(head);
}