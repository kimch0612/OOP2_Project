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
int dice_gen();
char score_section();
char dice_section();
char final_score();
class user_score{
public:
    int all, digit;
    int one, two, three, four, five, six;
    int chance, fourkind;
    int sum_digit(int digit);
    int current_dice[5];
    string check_keep[5] = {"0", "0", "0", "0", "0"};
};
#endif
