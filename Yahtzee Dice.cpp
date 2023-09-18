#include "yahtzee.h"

int main()
{
    int dice_user0[5], dice_user1[5];
    int *reroll_flag[4] = { 0 }, i = -1;

    while (++i < 5)
    {
        dice_user0[i] = dice_gen();
        Sleep(1000);
        cout << dice_user0[i];
    }
    cout << "\n" << endl;
    return (0);
}