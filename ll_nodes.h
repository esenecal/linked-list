#ifndef LL_NODES_H

#define LL_NODES_H
typedef struct Node {
    int value;
    struct Node *ptr;
    struct Node *tail;
} Node;

Node* create_linked_list(int);

void ll_append(Node*, int);

Node* ll_append_beginning(Node*, int);

void print_list(Node*);

#endif