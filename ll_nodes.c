#include "ll_nodes.h"
#include <stdio.h>
#include <stdlib.h>

// Used https://www.w3schools.com/dsa/dsa_theory_linkedlists_memory.php as a help occasionally.

/** A node in the linked list. Contains a value (int) and a pointer to the next int */
typedef struct Node {
    int value;  // Value of the node
    Node *ptr;  // Pointer to next node.
} Node;

// Create a pointer.
Node* create_pointer(int value, Node* ptr) {
    Node *node;
    node = malloc(sizeof(*node));
    // Test to ensure allocation was successful.
    if (node == NULL) {
        printf("Memory allocation unsuccessful.\n");
        return node;
    }
    node->value = value;
    node->ptr = ptr;
    printf("Node: value: %d ptr %p\n", node->value, node->ptr);
    return node;
}