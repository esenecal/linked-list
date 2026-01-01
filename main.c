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
    printf("%d\n", get_node_value(head_ptr, 4));

    delete_list(head_ptr);

    return 0;
}