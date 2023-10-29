#include "functions.h"

int user_score:: sum_digit(int flag, user_score& usr1, user_score& usr2)
{
    int i, check_num = 0, temp = 0;
    int tmp[] = {0, 0, 0, 0, 0, 0};
    bool flag1 = true;
    switch(flag)
    {
        case 1:
            for (i=0; i<5; i++)
                if (current_dice[i] == 1) temp += current_dice[i];
            digits++;
            all += temp;
            bonus += temp;
            break;
        case 2:
            for (i=0; i<5; i++)
                if (current_dice[i] == 2) temp += current_dice[i];
            digits++;
            all += temp;
            bonus += temp;
            break;
        case 3:
            for (i=0; i<5; i++)
                if (current_dice[i] == 3) temp += current_dice[i];
            digits++;
            all += temp;
            bonus += temp;
            break;
        case 4:
            for (i=0; i<5; i++)
                if (current_dice[i] == 4) temp += current_dice[i];
            digits++;
            all += temp;
            bonus += temp;
            break;
        case 5:
            for (i=0; i<5; i++)
                if (current_dice[i] == 5) temp += current_dice[i];
            digits++;
            all += temp;
            bonus += temp;
            break;
        case 6:
            for (i=0; i<5; i++)
                if (current_dice[i] == 6) temp += current_dice[i];
            digits++;
            all += temp;
            bonus += temp;
            break;
        case 7:
            all += 35;
            break;
        case 8: // Choice
            for (i=0; i<5; i++)
                temp += current_dice[i];
            all += temp;
            break;
        case 9: // 4 kind
            for (i=0; i<5; i++)
                tmp[current_dice[i] - 1] += 1;
            for (i=0; i<6; i++)
            {
                if (tmp[i] >= 4)
                {
                    temp = tmp[i] * (i + 1);
                    all += temp;
                }
            }
            break;
        case 10: // Full House
            for (i=0; i<5; i++)
                tmp[current_dice[i] - 1] += 1;
            for (i=0; i<6; i++)
            {
                if (tmp[i] == 2)
                {
                    for (int index=0; index<6; index++)
                    {
                        if (tmp[index] == 3)
                        {
                            temp = tmp[i]*(i+1) + tmp[index]*(index+1);
                            all += temp;
                        }
                    }
                }
            }
            break;
        case 11: // S. Straight
            for (i=0; i<5; i++)
                tmp[current_dice[i] - 1] += 1;
            for (i=0; i<6; i++)
                if (tmp[i] == 1) check_num++;
                else if (tmp[i] == 2 && flag1){
                    check_num++;
                    flag1 = false;
                }
            if (check_num >= 4)
                temp = 15;
            all += temp;
            break;
        case 12: // L. Straight
            for (i=0; i<5; i++)
                tmp[current_dice[i] - 1] += 1;
            for (i=0; i<6; i++)
                if (tmp[i] == 1) check_num++;
            if (check_num == 5)
                temp = 30;
            all += temp;
            break;
        case 13: // Yahtzee
            for (i=0; i<5; i++){
                if (current_dice[i] == 0 || current_dice[0] != current_dice[i])
                    return 0;
            }
            temp = 50;
            all += temp;
            break;
    }
    return temp;
}

int user_score:: calc_current_score(int flag, user_score& usr1, user_score& usr2)
{
    int i, check_num = 0, temp = 0;
    int tmp[] = {0, 0, 0, 0, 0, 0};
    bool flag1 = true;
    switch(flag)
    {
    case 0:
            for (i=0; i<5; i++)
                if (current_dice[i] == 1) temp += current_dice[i];
            break;
    case 1:
            for (i=0; i<5; i++)
                if (current_dice[i] == 2) temp += current_dice[i];
            break;
    case 2:
            for (i=0; i<5; i++)
                if (current_dice[i] == 3) temp += current_dice[i];
            break;
    case 3:
            for (i=0; i<5; i++)
                if (current_dice[i] == 4) temp += current_dice[i];
            break;
    case 4:
            for (i=0; i<5; i++)
                if (current_dice[i] == 5) temp += current_dice[i];
            break;
    case 5:
            for (i=0; i<5; i++)
                if (current_dice[i] == 6) temp += current_dice[i];
            break;
    case 6: // Choice
            for (i=0; i<5; i++)
                temp += current_dice[i];
            break;
    case 7: // 4 kind
            for (i=0; i<5; i++)
                tmp[current_dice[i] - 1] += 1;
            for (i=0; i<6; i++)
            {
                if (tmp[i] >= 4)
                {
                    temp = tmp[i] * (i + 1);
                }
            }
            break;
    case 8: // Full House
            for (i=0; i<5; i++)
                tmp[current_dice[i] - 1] += 1;
            for (i=0; i<6; i++)
            {
                if (tmp[i] == 2)
                {
                    for (int index=0; index<6; index++)
                    {
                        if (tmp[index] == 3)
                        {
                            temp = tmp[i]*(i+1) + tmp[index]*(index+1);
                        }
                    }
                }
            }
            break;
    case 9: // S. Straight
            for (i=0; i<5; i++)
                tmp[current_dice[i] - 1] += 1;
            for (i=0; i<6; i++)
                if (tmp[i] == 1) check_num++;
                else if (tmp[i] == 2 && flag1){
                    check_num++;
                    flag1 = false;
                }
            if (check_num >= 4)
                temp = 15;
            break;
    case 10: // L. Straight
            for (i=0; i<5; i++)
                tmp[current_dice[i] - 1] += 1;
            for (i=0; i<6; i++)
                if (tmp[i] == 1) check_num++;
            if (check_num == 5)
                temp = 30;
            break;
    case 11: // Yahtzee
            for (i=0; i<5; i++){
                if (current_dice[i] == 0 || current_dice[0] != current_dice[i])
                    return 0;
            }
            temp = 50;
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

int calc_score(user_score usr1, user_score usr2)
{
    if (usr1.all > usr2.all) return 0;
    else if (usr1.all < usr2.all) return 1;
    else return 2;
}

void user_score:: reset_variable()
{
    all=0, bonus=0, chance=0, fourkind=0, digits=0;
    for (int i=0; i<5; i++)
    {
        current_dice[i] = 0;
        check_keep[i] = "0";
    }
    for (int i=0; i<12; i++)
        blank_flag[i] = 0;
}
