#include <stdlib.h>
#include <stdio.h>
#include "stuff.h"
#include "List.h"

int main(void)
{
    int  N      = 12;
    int* my_set = so_shuffle(N, 1, N, NULL);
    so_print_v(my_set, N, "\n    shuffled values: ");
    free(my_set);
    char prefix[10];
    for (size_t i = 0; i < N; i += 1)
    {
        Info* info = so_factory_info();
        sprintf(prefix, "    [%2llu] ", i);
        so_print_info(info, prefix);
        free(info);
    }
    return 0;
};
