#include "ll_nodes.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    
    // Create the linked list as the head pointer.
    Node* head_ptr = create_linked_list(1);
    // for(int i = 2; i < 5; i++){
    //     ll_append(head_ptr, i);
    // }
    print_list(head_ptr);
    // delete the node
    head_ptr = delete_node(head_ptr, 0);
    printf("%p", head_ptr);
    // print_list(head_ptr);

    // test to ensure the remaining list is intact.
    // delete_list(head_ptr);

    return 0;
}