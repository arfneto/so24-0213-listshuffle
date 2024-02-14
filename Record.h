// https://stackoverflow.com/questions/77983967/how-would-you-shuffle-a-doubly-linked-list
#include <stdio.h>
typedef const char Duration[10];  // "01:33:33"

typedef struct st_record
{
    char     artist[50];
    char     albumTitle[50];
    char     songTitle[50];
    char     genre[50];
    Duration songLength;
    int      timesPlayed;
    int      rating;
    int      position;
} Record;

typedef Record Info;
