#include "functions.h"

int user_score:: sum_digit(int flag, int current_turn, user_score& usr1, user_score& usr2)
{
    int temp = 0;
    int tmp[] = {0, 0, 0, 0, 0};
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
        case 8: // Choice
            for (int i=0; i<5; i++)
                temp += current_dice[i];
            all += temp;
            break;
        case 9: // 4 kind
            for (int i=0; i<5; i++)
                tmp[current_dice[i] - 1] += 1;
            for (int i=0; i<5; i++)
            {
                if (tmp[i] >= 4)
                {
                    temp = tmp[i] * (i + 1);
                    all += temp;
                }
            }
            break;
        case 10: // Full House
            break;
        case 11: // S. Straight
            break;
        case 12: // L. Straight
            break;
        case 13: // Yahtzee
            for (int i=0; i<5; i++){
                if (current_dice[i] == 0 || current_dice[0] != current_dice[i])
                    return 0;
            }
            temp = 50;
            all += temp;
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
