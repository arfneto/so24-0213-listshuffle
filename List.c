#include "List.h"

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>

#include "stuff.h"

int   so_cmp_info(void* a, void* b);
Node* so_locate_at(List* list, size_t pos);
int   so_swap_info(Node* one, Node* other);

// list related functions

List* so_create_list(void)
{
    List* list = malloc(sizeof(List));
    if (list == NULL) return NULL;
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    fprintf(stderr, "    list created\n");
    return list;
}

List* so_delete_list(List* del)
{
    if (del == NULL) return NULL;  // no list
    for (size_t i = 0; i < del->size; i += 1)
    {  // delete nodes, 1 by 1
        Node* save = del->head->next;
        so_delete_info(del->head->info);
        free(del->head);
        del->head = save;
    };
    free(del);  // delete list
    fprintf(stderr, "    list deleted\n");
    return NULL;
}

// inserts 'info' at the tail of the list
int so_insert_back(Info* info, List* list)
{
    if (list == NULL) return -1;  // no list
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) return -2;  // no alloc
    node->info = so_copy_info(info);
    if (list->size == 0)  // first node
    {
        node->next = NULL;
        list->size = 1;
        list->head = node;
        list->tail = node;
        return 0;  // 1st node
    };
    node->next       = NULL;
    list->tail->next = node;
    list->tail       = node;
    list->size += 1;
    return 0;
}

// inserts 'info' at the head of the list
int so_insert_front(Info* info, List* list)
{
    if (list == NULL) return -1;  // no list
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) return -2;  // no alloc
    node->info = so_copy_info(info);
    if (list->size == 0)
    {
        node->next = NULL;
        list->size = 1;
        list->head = node;
        list->tail = node;
        return 0;  // 1st node
    };
    node->next = list->head;
    list->head = node;
    list->size += 1;
    return 0;
}

int so_print_list(List* list, const char* msg)
{
    if (list == NULL)
    {
        printf("No valid list!\n");
        return 0;
    }
    if (list->size == 0)
    {
        printf("list is empty\n");
        return 0;
    }
    if (msg != NULL) printf("%s", msg);
    Node* p = list->head;
    for (size_t i = 0; i < list->size; i += 1)
    {
        so_print_info(p->info, NULL);
        p = p->next;
    }
    printf("\n[-----]\n\n");
    return 0;
}

// return a pointer to a copy of the record
// at such 'pos', or 'NULL'. 'pos'starts at 0
Node* so_locate_at(List* list, size_t pos)
{
    if (list == NULL) return NULL;
    if (list->size < 1 + pos) return NULL;
    Node* nd = list->head;
    for (size_t i = 0; i < pos; i += 1) nd = nd->next;
    return nd;
}

int so_sort_nodes(List* list, int (*cmp)(void*, void*))
{
    if (list == NULL) return -1;
    if (list->size < 2) return -2;
    if (cmp == NULL) return -3;
    for (int i = 0; i < list->size - 1; i += 1)
        for (int j = 0; j < list->size - i - 1; j += 1)
        {
            Node* one = so_locate_at(list, j);

            if ( cmp((void*)one, (void*)one->next) < 0)
                so_swap_info(one, one->next);
        }
    return 0;
}

// swap data from these 2 nodes
int so_swap_info(Node* one, Node* other)
{
    if (one == NULL) return -1;
    if (other == NULL) return -1;
    Info* temp  = one->info;
    one->info   = other->info;
    other->info = temp;
    return 0;
}

// shuffle data in the list nodes
int so_shuffle_nodes(List* list)
{
    // list->size is the size
    unsigned int seed = 240212;
    // final order
    int* f_order =
        so_shuffle(list->size, 0, list->size - 1, &seed);
    so_print_v(
        f_order, list->size, "    final order for nodes:");

    int* p_order = (int*)malloc(
        list->size * sizeof(int));  // present order
    for (size_t i = 0; i < list->size; ++i)
        p_order[i] = (int)i;
    for (size_t ix = 0; ix < list->size; ix += 1)
    {
        if (f_order[ix] == p_order[ix])
            continue;  // in position now
        size_t pos = ix + 1;
        for (; pos < list->size - 1; pos += 1)
            if (p_order[pos] == f_order[ix]) break;
        // swap info at nodes at 'pos' and 'ix' positions
        Node* one   = so_locate_at(list, ix);
        Node* other = so_locate_at(list, pos);
        so_swap_info(one, other);
        int save     = p_order[pos];
        p_order[pos] = p_order[ix];
        p_order[ix]  = save;
        // so_print_v(
        //     p_order, list->size,
        //     "\tpresent order for nodes:");
    };  // for
    free(p_order);
    free(f_order);
    return 0;
};

int so_cmp_info(void* a, void* b)
{
    if (a == NULL) return 0;
    if (b == NULL) return 0;
    Node* one   = (Node*)a;
    Node* other = (Node*)b;
    if (one->info->position < other->info->position)
        return +1;
    if (one->info->position > other->info->position) return -1;
    return 0;
};
