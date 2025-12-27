#ifndef LL_NODES_H

#define LL_NODES_H
typedef struct Node {
    int value;
    struct Node *ptr;
} Node;

Node* create_pointer(int, Node*);
#endif