#include "yacht.h"

int dice_gen(void)
{
    srand((unsigned int)time(NULL));
    return (random() % 6) + 1;
}