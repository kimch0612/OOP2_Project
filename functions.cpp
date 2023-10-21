#include "functions.h"

int user_score:: sum_digit(int flag, int current_turn, user_score& usr1, user_score& usr2)
{
    int temp = 0;
    switch(flag)
    {
        case 1:
            if (current_turn % 2 == 1)
            {
                for (int i=0; i<5; i++)
                {
                    if (usr1.current_dice[i] == 1)
                        temp += usr1.current_dice[i];
                }
                usr1.digits++;
                usr1.all += temp;
                usr1.bonus += temp;
            }
            else
            {
                for (int i=0; i<5; i++)
                {
                    if (usr2.current_dice[i] == 1)
                        temp += usr2.current_dice[i];
                }
                usr2.digits++;
                usr2.all += temp;
                usr2.bonus += temp;
            }
            break;
        case 2:
            if (current_turn % 2 == 1)
            {
                for (int i=0; i<5; i++)
                {
                    if (usr1.current_dice[i] == 2)
                        temp += usr1.current_dice[i];
                }
                usr1.digits++;
                usr1.all += temp;
                usr1.bonus += temp;
            }
            else
            {
                for (int i=0; i<5; i++)
                {
                    if (usr2.current_dice[i] == 2)
                        temp += usr2.current_dice[i];
                }
                usr2.digits++;
                usr2.all += temp;
                usr2.bonus += temp;
            }
            break;
        case 3:
            if (current_turn % 2 == 1)
            {
                for (int i=0; i<5; i++)
                {
                    if (usr1.current_dice[i] == 3)
                        temp += usr1.current_dice[i];
                }
                usr1.digits++;
                usr1.all += temp;
                usr1.bonus += temp;
            }
            else
            {
                for (int i=0; i<5; i++)
                {
                    if (usr2.current_dice[i] == 3)
                        temp += usr2.current_dice[i];
                }
                usr2.digits++;
                usr2.all += temp;
                usr2.bonus += temp;
            }
            break;
        case 4:
            if (current_turn % 2 == 1)
            {
                for (int i=0; i<5; i++)
                {
                    if (usr1.current_dice[i] == 4)
                        temp += usr1.current_dice[i];
                }
                usr1.digits++;
                usr1.all += temp;
                usr1.bonus += temp;
            }
            else
            {
                for (int i=0; i<5; i++)
                {
                    if (usr2.current_dice[i] == 4)
                        temp += usr2.current_dice[i];
                }
                usr2.digits++;
                usr2.all += temp;
                usr2.bonus += temp;
            }
            break;
        case 5:
            if (current_turn % 2 == 1)
            {
                for (int i=0; i<5; i++)
                {
                    if (usr1.current_dice[i] == 5)
                        temp += usr1.current_dice[i];
                }
                usr1.digits++;
                usr1.all += temp;
                usr1.bonus += temp;
            }
            else
            {
                for (int i=0; i<5; i++)
                {
                    if (usr2.current_dice[i] == 5)
                        temp += usr2.current_dice[i];
                }
                usr2.digits++;
                usr2.all += temp;
                usr2.bonus += temp;
            }
            break;
        case 6:
            if (current_turn % 2 == 1)
            {
                for (int i=0; i<5; i++)
                {
                    if (usr1.current_dice[i] == 6)
                        temp += usr1.current_dice[i];
                }
                usr1.digits++;
                usr1.all += temp;
                usr1.bonus += temp;
            }
            else
            {
                for (int i=0; i<5; i++)
                {
                    if (usr2.current_dice[i] == 6)
                        temp += usr2.current_dice[i];
                }
                usr2.digits++;
                usr2.all += temp;
                usr2.bonus += temp;
            }
            break;
        case 7:
            all += 35;
            break;
    }
    return temp;
}

int dice_gen(void)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(1, 6);
    return dis(gen);
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
