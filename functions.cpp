#include "functions.h"

int user_score:: sum_digit(int digit)
{
    
}

int dice_gen(void)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 6);
    return dis(gen)
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
