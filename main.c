#include "ll_nodes.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Create the linked list as the head pointer.
    Node* linked_list_head = create_linked_list(2);
    print_list(linked_list_head);
    return 0;
}