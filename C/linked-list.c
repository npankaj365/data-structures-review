#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node *head = NULL;
node *curr = NULL;

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

int delete_item(node *ptr, int n)
{
    int found = 0;
    if(head->data == n)
    {
        head = head->next;
        found = 1;
    }
    else
    {
        while(ptr != NULL)
        {
            if(ptr->next->data == n)
            {
                found = 1;
                ptr->next = ptr->next->next;
                break;
            }
            ptr = ptr->next;
        }
    }
    return found;
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
    head = create_list(4);
    curr = head;

    // Inserting items into the Linked List
    curr = append_list(curr, 5);
    curr = append_list(curr, 6);
    curr = append_list(curr, 7);

    // Printing items from the Linked List
    traverse_list(head);

    // Deleting items
    if(delete_item(head, 7)){
        printf("Delete of %d successful\n", 7);
    }
    traverse_list(head);
    if(delete_item(head, 6)){
        printf("Delete of %d successful\n", 6);
    }
    traverse_list(head);
}