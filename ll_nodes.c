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
        free(node);
        return NULL;
    }
    
    node->value = value;    // Assign values to the struct.
    node->ptr = NULL;
    node->tail = node;
    
    printf("address: %p ptr: %p tail: %p value: %d\n",  node, node->ptr, node->tail, node->value);   // Debugging
    return node;
}

void ll_append(Node* head_ptr, int value) {     // Append to the end of the list.

    Node *node;
    node = malloc(sizeof(*node));   // Allocate to dynamic memory.
    
    // Test to ensure allocation was successful.
    if (node == NULL) {
        printf("Memory allocation unsuccessful.\n");
        free(node);
        return;
    }

    node->value = value;
    node->ptr = NULL;       // Last node. Does not point to anywhere.
    node->tail = NULL;      // node's tail pointer doesn't matter.

    head_ptr->tail->ptr = node;     // Point the (former) tail's ptr to the new node.
    head_ptr->tail = node;          // Point the tail ptr to the node.

    printf("address: %p ptr: %p tail: %p value: %d\n",  node, node->ptr, node->tail, node->value);   // Debugging
}

// Append a node at the beginning of a list. Returns the new head pointer.
Node* ll_append_beginning(Node* head_ptr, int value) {
    
    Node *node;     // new node.
    node = malloc(sizeof(*node));   // Allocate to dynamic memory.
    
    // Test to ensure allocation was successful.
    if (node == NULL) {
        printf("Memory allocation unsuccessful.\n");
        free(node);     // clear memory?
        return head_ptr;    // Just return the original head pointer.
    }

    node->value = value;
    node->ptr = head_ptr;   // replaces the head_ptr by pointing to the head_ptr.
    node->tail = head_ptr->tail;

    head_ptr->tail = NULL;

    printf("address: %p ptr: %p tail: %p value: %d\n",  node, node->ptr, node->tail, node->value);   // Debugging

    return node;        // this is the new head pointer.
}

Node* delete_node(Node* head_ptr, int position) {       // delete a node at a specific position, with 0 being the first node.
    Node *prev; // Node before the current node.
    Node *node = head_ptr;
    for (int i = 0; i < position; i++) {    // Iterate up to the proper node
        if (node == NULL) {     // check to ensure we have not gone over the limit.
            printf("Over limit length.\n");
            return head_ptr;
        }
        printf("Node %d: %d\n", position, node->value);
        prev = node;
        node = node->ptr;
    }
    // We have reached the position to be deleted.
    if (position == 0) {        // If the pointer being deleted is the head pointer:
        node = head_ptr->ptr;           // make node the new head pointer--start pointing over info.
        node->tail = head_ptr->tail;
        free(head_ptr);                     // deallocate memory
        return node;                        // return the new head node (prev)      
    } else {  
        prev->ptr = node->ptr;  // Point the previous node to the node after the node being deleted.
        free(node);
        return head_ptr;        // return the head pointer.
    }
}

void print_list(Node* head_ptr) {   // Print the linked list.
    Node *iter = head_ptr;  // Create a pointer pointing to the head pointer.
    while (iter->ptr != NULL) {     // Iterate up to the tail
        printf("Value: %d tail: %p -> ", iter->value, iter->tail);
        iter = iter->ptr;           // Move to the next node.
    }
    // print the tail.
    printf("Value: %d tail: %p -> NULL\n", iter->value, iter->tail);
}

void delete_list(Node* head_ptr) {      // Deallocate all memory used in the linked list.
    Node *node = head_ptr;  // Create a pointer pointing to the head pointer.
    Node *next = head_ptr->ptr;
    while (next != NULL) {     // Iterate up to the tail
        printf("Clearing %d\n", node->value);
        free(node);
        node = next;
        next = node->ptr;
    }
    // clear the last node.
    printf("Clearing %d\n", node->value);
        free(node);
}