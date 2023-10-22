#include "functions.h"

int user_score:: sum_digit(int flag, int current_turn, user_score& usr1, user_score& usr2)
{
    int temp = 0;
    switch(flag)
    {
        case 1:
            for (int i=0; i<5; i++)
                if (current_dice[i] == 1) temp += current_dice[i];
            digits++;
            all += temp;
            bonus += temp;
            break;
        case 2:
            for (int i=0; i<5; i++)
                if (current_dice[i] == 2) temp += current_dice[i];
            digits++;
            all += temp;
            bonus += temp;
            break;
        case 3:
            for (int i=0; i<5; i++)
                if (current_dice[i] == 3) temp += current_dice[i];
            digits++;
            all += temp;
            bonus += temp;
            break;
        case 4:
            for (int i=0; i<5; i++)
                if (current_dice[i] == 4) temp += current_dice[i];
            digits++;
            all += temp;
            bonus += temp;
            break;
        case 5:
            for (int i=0; i<5; i++)
                if (current_dice[i] == 5) temp += current_dice[i];
            digits++;
            all += temp;
            bonus += temp;
            break;
        case 6:
            for (int i=0; i<5; i++)
                if (current_dice[i] == 6) temp += current_dice[i];
            digits++;
            all += temp;
            bonus += temp;
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
