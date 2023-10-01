#include "functions.h"

int dice_gen(void)
{
    srand((unsigned int)time(NULL));
    return (rand() % 6) + 1;
}

void reset_dice(int *index, char **reroll_flag)
{
    *index = -1;
    *reroll_flag = { 0 };
}

char score_section(void)
{
    return (0);
}

char dice_section(void)
{
    return (0);
}

char final_score(void)
{
    return (0);
}
