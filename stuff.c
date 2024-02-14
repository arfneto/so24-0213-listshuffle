#include "stuff.h"

// returns a shuffled vector of 'N' values from 'min_v'
// to 'max_v' inclusive. If 'pSeed' is not 'NULL' will
// be used as a seed for rand()
int* so_shuffle(
    size_t N, size_t min_v, size_t max_v, unsigned* pSeed)
{
    if (pSeed != NULL) srand(*pSeed);
    if (min_v >= max_v) return NULL;
    size_t set = max_v - min_v + 1;
    if (set < 2) return NULL;  // at least 2...
    if (N == 0) return NULL;   // silly, but...
    if (N > set) N = set;      // for sanity
    int* v = (int*)malloc(set * sizeof(int));  // he vector
    if (v == NULL) return NULL;                // error
    // number the slots
    for (size_t i = 0, val = min_v; i < set; i += 1)
        *(v + i) = (int) val++;
    for (unsigned i = 1; i < N; i += 1)
    {  // one of the other values
        int* one   = v + i - 1;
        int* other = v + i + (rand() % (N - i));
        int  temp  = *one;    // the 1st value
        *one       = *other;  // exchange
        *other     = temp;
    };  // for()
    return v;
};

int so_print_v(int* v, size_t N, const char* msg)
{
    if (v == NULL) return -1;
    if (msg != NULL) printf("%s", msg);
    printf("%llu values: ", N);
    for (size_t i = 0; i < N; i += 1) printf("%d ", v[i]);
    printf("\n");
    return 0;
}
