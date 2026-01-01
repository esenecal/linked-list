#include "ll_nodes.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Create the linked list as the head pointer.
    Node* head_ptr = create_linked_list(1);
    for(int i = 2; i < 5; i++){
        ll_append(head_ptr, i);
    }
    print_list(head_ptr);
    head_ptr = add_node(head_ptr, 200, 0);
    print_list(head_ptr);
    ll_append(head_ptr, 300);
    print_list(head_ptr);

    delete_list(head_ptr);

    return 0;
}