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
class One{
public:
    int one(void)
    {
        for (i=0; i<5; i++) if (current_dice[i] == 1) 
            temp += current_dice[i];
    }
}
class Two : public One{
public:
    int two(void)
    {
        for (i=0; i<5; i++) if (current_dice[i] == 2)
            temp += current_dice[i];
    }
}
class Three : public Two{
public:
    int three(void)
    {
        for (i=0; i<5; i++) if (current_dice[i] == 3)
            temp += current_dice[i];
    }
}
class Four : public Three{
public:
    int four(void)
    {
        for (i=0; i<5; i++) if (current_dice[i] == 4)
            temp += current_dice[i];
        return temp;
    }
}
class Five : public Four{
public:
    int five(void)
    {
        for (i=0; i<5; i++) if (current_dice[i] == 5)
            temp += current_dice[i];
    }
}
class Six : public Five{
public:
    int six(void)
    {
        for (i=0; i<5; i++) if (current_dice[i] == 6)
            temp += current_dice[i];
    }
}
class Bonus : public Six{
public:
    int bonus(void)
    {
        all += 35;
    }
}
class score_template{
public:
    int all, bonus, chance, fourkind, digits;
    int current_dice[5] = {0, 0, 0, 0, 0};
    int blank_flag[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    string check_keep[5] = {"0", "0", "0", "0", "0"};
}
class user_score : public score_template {
public:
    int sum_digit(int flag);
    int calc_current_score(int flag);
    void reset_variable();
};
int dice_gen();
int calc_score(user_score usr1, user_score usr2);
#endif
