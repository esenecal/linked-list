#include "ll_nodes.h"
#include <stdio.h>
#include <stdlib.h>

// Used https://www.w3schools.com/dsa/dsa_theory_linkedlists_memory.php as a help occasionally.

/** A node in the linked list. Contains a value (int) and a pointer to the next int */
typedef struct Node {
    int value;  // Value of the node
    Node *ptr;  // Pointer to next node.
} Node;

// Create the first node of a linked list and thus initialize the list. Automatically set the value of the linked list to null.
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
    
    printf("address: %p value: %d ptr %p\n", node, node->value, node->ptr);   // Debugging
    return node;
}

