#include <stdlib.h>
#include <time.h>

int dice_gen(void)
{
    int i;
    srand(time(NULL));
    i = (random() % 6) + 1;
    return i;
}