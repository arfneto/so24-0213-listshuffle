#include <stdio.h>
#include <stdlib.h>

#include "List.h"
#include "stuff.h"

int main(void)
{
    List*  my_list = so_create_list();
    unsigned N       = 9;  // 9 records on sample data
    for (unsigned i = 0; i < N; i += 1)
    {
        Info* one = so_factory_info();
        so_insert_back(one, my_list);
        free(one);
    }
    so_print_list(
        my_list, "\n    ***** with the test data *****\n");
    so_shuffle_nodes(my_list);
    so_print_list(
        my_list, "\n    ***** after shuffle *****\n");
    so_delete_list(my_list);
    return 0;
};
