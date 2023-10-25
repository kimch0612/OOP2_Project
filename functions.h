#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <QPixmap>
#include <list>
#include <string>
#include <windows.h>
#include <random>
#include <QDesktopServices>
using namespace std;
class user_score{
public:
    int all, bonus, chance, fourkind, digits;
    int sum_digit(int flag, int current_turn, user_score& usr1, user_score& usr2);
    int current_dice[5] = {0, 0, 0, 0, 0};
    int blank_flag[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string check_keep[5] = {"0", "0", "0", "0", "0"};
};
int dice_gen();
int calc_score(user_score usr1, user_score usr2);
#endif
