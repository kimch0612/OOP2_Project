#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <QDesktopServices>
#include <QPixmap>
#include <QTimer>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <random>
#include <string>
#include <windows.h>
using namespace std;
class score_template{
public:
    int all, bonus, chance, fourkind, digits;
    int current_dice[5] = {0, 0, 0, 0, 0};
    int blank_flag[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string check_keep[5] = {"0", "0", "0", "0", "0"};
};

class user_score : public score_template{
public:
    int sum_digit(int flag);
    int calc_current_score(int flag);
    void reset_variable();
};
int dice_gen();
int calc_score(user_score usr1, user_score usr2);
#endif
