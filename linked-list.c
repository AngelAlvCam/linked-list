#include "linked-list.h"

/*
Function that returns a pointer to a empty LinkedList struct.
*/
LinkedList *create_list()
{
    LinkedList* list = calloc(1, sizeof(LinkedList));
    if (list == NULL) return NULL;
    list->head = NULL;
    list->tail = NULL;
    return list;
}

/*
Inserts a node at the beginning of the linked list, with a given integer value.
Returns true if the new node could be allocated succesfully to add it in the list,
otherwise, returns false.
*/
bool insert_at_head(LinkedList* list, int value)
{
    // Initialize node
    Node* new_node = calloc(1, sizeof(Node));
    if (new_node == NULL) return false;
    new_node->value = value;

    // If the list is empty..
    if (list->head == NULL && list->tail == NULL)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        // If the list is not empty
        new_node->next = list->head;
        list->head = new_node; // Update head
    }
    return true;
}

/*
Insert a node at the end of the linked list, with a given value.
Returns true if the new node could be allocated succesfully to add it in the list,
otherwise, returns false.
*/
bool insert_at_tail(LinkedList* list, int value)
{
    Node* new_node = calloc(1, sizeof(Node));
    if (new_node == NULL) return false;
    new_node->value = value;

    // If the list is empty...
    if (list->head == NULL && list->tail == NULL)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        // If the list is not empty
        list->tail->next = new_node;
        list->tail = new_node;
    }
    return true;
}

/*
Removes a node at the end of a linked list.
Returns true if a node could be removed succesfully.
Otherwise (if the list is empty), returns false.
*/
bool remove_at_tail(LinkedList* list)
{
    // If the list is empty... nothing to do
    if (list->head == NULL && list->tail == NULL) return false;
    
    // If the list only has one node
    if (list->head == list->tail) 
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        return true;
    }

    // If the list has 2 nodes or more, look for the last node and free it
    Node* prev = list->head;
    Node* current = list->head->next;
    while (current != list->tail)
    {
        prev = current;
        current = current->next;
    }

    list->tail = prev; // Update tail reference
    list->tail->next = NULL;
    free(current);
    return true;
}

/*
Removes a node at the beginning of a linked list.
Returns true if a node could be removed succesfully.
Otherwise (if the list is empty), returns false.
*/
bool remove_at_head(LinkedList* list)
{
    // If the list is empty... nothing to do
    if (list->head == NULL && list->tail == NULL) return false;

    // If the list only has one node
    if (list->head == list->tail)
    {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        return true;
    }

    // if the list has 2 nodes or more...
    Node* temp = list->head->next;
    free(list->head);
    list->head = temp; // Update head reference
    return true;
}

/*
Prints the content of a linked list.
*/
void print_list(LinkedList* list)
{
    Node* current = list->head;
    printf("[");
    while (current != NULL)
    {
        printf(" %d ", current->value);
        current = current->next;
    }
    printf("]\n");
}

/*
Reverse a given linked list.
*/
void reverse_list(LinkedList* list)
{
    if (list->head == NULL && list->tail == NULL) return;
    if (list->head == list->tail) return; // if the list has one node or less

    Node *prev = list->head;
    Node *current = list->head->next;

    list->head->next = NULL;
    list->tail = list->head;

    while (current != NULL)
    {
        Node *temp = current->next;
        current->next = prev; 
        prev = current;
        current = temp;
    }
    
    // Set new head
    list->head = prev;
}

/*
Inserts a node in the linked list at a specified position.
If the length of the list is m, then the index could be [0, m+1]
*/
bool insert_at_index(LinkedList* list, int index, int value)
{
    // If the index is 0, use the insert at head function
    if (index == 0) return insert_at_head(list, value);
    if (list->head == NULL) return false; 
    
    Node *current = list->head;
    for (int i = 1; i < index; i++)
    {
        current = current->next;
        if (current == NULL) return false;
    }

    Node *temp = current->next;
    if (temp == NULL) return insert_at_tail(list, value);

    Node* new_node = calloc(1, sizeof(Node));
    new_node->value = value;
    current->next = new_node;
    new_node->next = temp;
    return true;
}

/*
Removes a node from the linked list in the specified index.
If the length of the list is m, the valid index is in [0,m-1]
*/
bool remove_at_index(LinkedList* list, int index)
{
    if (index == 0) return remove_at_head(list);

    Node *prev = list->head;
    Node *current = list->head->next; // Current is the node to be deleted
    for (int i = 1; i < index; i++)
    {
        prev = current;
        current = current->next;
        if (current == NULL) return false;
    }

    Node *temp = current->next; // temp is the node next to the node to be deleted
    if (temp == NULL) return remove_at_tail(list);

    free(current);
    prev->next = temp;
    return true;
}