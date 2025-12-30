#include "ll_nodes.h"
#include <stdio.h>
#include <stdlib.h>

// Used https://www.w3schools.com/dsa/dsa_theory_linkedlists_memory.php as a help, but not much.

/** A node in the linked list. Contains a value (int) and a pointer to the next int */
typedef struct Node {
    int value;  // Value of the node
    Node *ptr;  // Pointer to next node.
    Node *tail;  // Tail pointer. Only the head pointer's tail value matters.
                 // This means all other nodes have a tail pointer that doesn't do anything. Not the best.
} Node;

// Create the head node of a linked list and thus initialize the list.
Node* create_linked_list(int value) {

    Node *node;
    node = malloc(sizeof(*node));   // Allocate to dynamic memory.
    
    // Test to ensure allocation was successful.
    if (node == NULL) {
        printf("Memory allocation unsuccessful.\n");
        return node;
    }
    
    node->value = value;    // Assign values to the struct.
    node->ptr = NULL;
    node->tail = node;
    
    printf("address: %p value: %d ptr %p tail: %p\n",  node, node->value, node->ptr, node->tail);   // Debugging
    return node;
}

void ll_append(Node* head_ptr, int value) {     // Append to the end of the list.

    Node *node;
    node = malloc(sizeof(*node));   // Allocate to dynamic memory.
    
    // Test to ensure allocation was successful.
    if (node == NULL) {
        printf("Memory allocation unsuccessful.\n");
        return;
    }

    node->value = value;
    node->ptr = NULL;       // Last node. Does not point to anywhere.
    node->tail = NULL;      // node's tail pointer doesn't matter.

    head_ptr->tail->ptr = node;     // Point the (former) tail's ptr to the new node.
    head_ptr->tail = node;          // Point the tail ptr to the node.

    printf("address: %p value: %d ptr %p tail: %p\n",  node, node->value, node->ptr, node->tail);   // Debugging
}

void ll_append_beginning(Node* head_ptr, int value) {       // Append at the beginning of the list.
    
    Node *head_replace; // This will be the REPLACEMENT for the past head node.
    head_replace = malloc(sizeof(*head_replace));   // Allocate to dynamic memory.
    
    // Test to ensure allocation was successful.
    if (head_replace == NULL) {
        printf("Memory allocation unsuccessful.\n");
        return;
    }

    // There must be an easier way to do this.
    *head_replace = *head_ptr;  // Move over the head node to it's new home.
    head_replace->tail = NULL;  // This now has no need to know the tail.

    // Begin replacing pointer info.
    head_ptr->value = value;
    head_ptr->ptr = head_replace;

    printf("address: %p value: %d ptr %p tail: %p\n",  head_ptr, head_ptr->value, head_ptr->ptr, head_ptr->tail);   // Debugging
}

void print_list(Node* head_ptr) {   // Print the linked list.
    Node *iter = head_ptr;  // Create a pointer pointing to the head pointer.
    while (iter->ptr != NULL) {     // Iterate up to the tail
        printf("%d -> ", iter->value);
        iter = iter->ptr;           // Move to the next node.
    }
    // print the tail.
    printf("%d -> NULL\n", iter->value);
}