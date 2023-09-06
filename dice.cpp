#include "yacht.h"

int dice_gen(void)
{
    srand((unsigned int)time(NULL));
    return (random() % 6) + 1;
}

void reset_dice(int *index, char **reroll_flag)
{
	*index = -1;
	*reroll_flag = { 0 };
}