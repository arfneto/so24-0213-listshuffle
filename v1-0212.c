#include <stdlib.h>
#include <stdio.h>
#include "stuff.h"
#include "List.h"

Node* so_locate_at(List* list, size_t pos);
int   so_swap_info(Node* one, Node* other);

int main(void)
{
    Info* one     = NULL;
    List* my_list = so_create_list();
    // 1
    one     = so_factory_info();
    so_insert_back(one, my_list);
    free(one);
    // 2
    one = so_factory_info();
    so_insert_back(one, my_list);
    free(one);
    so_print_list(
        my_list, "\n2 nodes: one is head other is tail\n");
    // test swap
    so_swap_info(my_list->head, my_list->tail);
    so_print_list(
        my_list, "\nafter swapping head and tail\n");
    // test pos
    Node* first = so_locate_at(my_list, 0);
    so_print_info(first->info, " first");
    Node* second = so_locate_at(my_list, 1);
    so_print_info(second->info, "second");
    so_delete_list(my_list);
    return 0;
};

