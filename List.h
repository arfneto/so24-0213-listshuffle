// https://stackoverflow.com/questions/77983967/how-would-you-shuffle-a-doubly-linked-list
#include <stdio.h>

#include "Record.h"
// operations on data records
Info* so_copy_info(Info*);
int   so_cmp_info(void*, void*);
Info* so_delete_info(Info*);
Info* so_factory_info(void);
int   so_print_info(Info*, const char* msg);

// operations on List
typedef struct st_node
{
    struct st_node* prev;  // links
    struct st_node* next;

    Info* info;  // data
} Node;

typedef struct
{
    size_t size;
    Node*  tail;
    Node*  head;
} List;  // a (possibly empty) list of nodes

List* so_create_list(void);
List* so_delete_list(List*);
int   so_insert_back(Info*, List*);
int   so_insert_front(Info*, List*);
int   so_print_list(List*, const char* msg);
int   so_sort_nodes(List*, int (*f)(void*, void*));
int   so_shuffle_nodes(List*);
