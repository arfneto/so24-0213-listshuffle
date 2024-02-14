#include "Record.h"

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
// data related functions

Info* so_copy_info(const Info* orig)
{
    if (orig == NULL) return NULL;
    Info* cp = malloc(sizeof(Info));
    if (cp == NULL) return NULL;
    memcpy(cp, orig, sizeof(Info));
    return cp; 
}

Info* so_delete_info(Info* del)
{
    if (del == NULL) return NULL;
    free(del);
    return NULL;
}

Info* so_factory_info(void)
{  // just copy and paste from question data
#include "data.txt"
    Info* one = malloc(sizeof(Info));
    if (one == NULL) return NULL;
    static int ix = 0;
    memcpy(one, test_data+ix, sizeof(Info));
    one->songTitle[0] = (char)('0' + ix);
    ix             = (ix == 8) ? 0 : ++ix;
    return one;
}

int so_print_info(Info* info, const char* msg)
{
    if (info == NULL) return -1;
    if (msg != NULL) printf("%s", msg);
    printf(
        "\
    '%s' %s from '%s' in '%s' [%s] Played %d times, rating %d pos %d\n",
        info->songTitle, info->songLength, info->artist,
        info->albumTitle, info->genre, info->timesPlayed,
        info->rating, info->position);
    return 0;
}
