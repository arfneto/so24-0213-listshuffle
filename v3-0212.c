#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "List.h"
#include "stuff.h"

int so_cmp_info_artist(void* a, void* b);

int main(void)
{
    int      seed    = 240212;  // for rand()
    List*    my_list = so_create_list();
    unsigned N       = 9;  // 9 records on sample data
    for (unsigned i = 0; i < N; i += 1)
    {
        Info* one = so_factory_info();
        so_insert_back(one, my_list);
        free(one);
    }
    so_print_list(
        my_list, "\n    ***** with the test data *****\n");
    so_sort_nodes(my_list, so_cmp_info);
    so_print_list(
        my_list,
        "\n    ***** after sort on position *****\n");
    so_sort_nodes(my_list, so_cmp_info_artist);
    so_print_list(
        my_list,
        "\n    ***** after sort on ARTIST *****\n");
    so_delete_list(my_list);
    return 0;
};

int so_cmp_info_artist(void* a, void* b)
{
    if (a == NULL) return 0;
    if (b == NULL) return 0;
    Node* one   = (Node*)a;
    Node* other = (Node*)b;
    return strcmp(
        other->info->artist, one->info->artist);
};
