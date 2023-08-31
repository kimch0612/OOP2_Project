#include "yacht.h"

int main(void)
{
    int dice_user0[4], dice_user1[4];
    int reroll_flag[4], i = -1;

    while (++i < 5)
    {
        dice_user0[i] = dice_gen();
        sleep(1);
        cout << dice_user0[i] << endl;
    }
}