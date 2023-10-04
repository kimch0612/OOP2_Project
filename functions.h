#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <windows.h>
using namespace std;
int dice_gen();
char score_section();
char dice_section();
char final_score();
class user_score{
public:
    int all, digit;
    int one, two, three, four, five, six;
    int sum_digit(int digit);
}
#endif
