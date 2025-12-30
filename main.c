#include "ll_nodes.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Create the linked list as the head pointer.
    Node* head_ptr = create_linked_list(2);
    ll_append_beginning(head_ptr, 20);
    print_list(head_ptr);
    
    return 0;
}