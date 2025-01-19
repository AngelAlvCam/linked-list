#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/*
Type definition of a linked list node
*/
typedef struct node {
    int value;
    struct node *next;
} Node;

/*
Type definition of a linked list
*/
typedef struct linkedlist {
    Node *head;
    Node *tail;
} LinkedList;

/* Functions */
LinkedList *create_list();
bool insert_at_head(LinkedList* list, int value);
bool insert_at_tail(LinkedList* list, int value);
bool remove_at_tail(LinkedList* list);
bool remove_at_head(LinkedList* list);
void print_list(LinkedList* list);
void reverse_list(LinkedList* list);
bool insert_at_index(LinkedList* list, int index, int value);
bool remove_at_index(LinkedList* list, int index);