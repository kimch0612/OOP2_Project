# Yahztee Dice Program Description

## 목차
1. [1. GUI 파트에서 사용한 Object들의 Object-Name 설명](#1-gui-파트에서-사용한-object들의-object-name-설명)
2. [2. 프로젝트에서 사용한 변수 설명](#2-프로젝트에서-사용한-변수-설명)
3. [3. 프로젝트에서 사용한 함수 설명](#3-프로젝트에서-사용한-함수-설명)
4. [4. user_socre class 설명](#4-user_score-class-설명)

---
### 1. GUI 파트에서 사용한 Object의 Object Name 설명
| Name | Purpose |
|:---|:---|
| OS | Windows 7 |
---
### 2. 프로젝트에서 사용한 변수 설명
#### mainwindow.cpp file
| Type | Name | Purpose |
|:---|:---|:---|
| int | turn | 현재 누구의 턴인지 확인하기 위한 변수 |
| int | current_turn | 주사위를 몇번 더 굴릴 수 있는지 확인하기 위한 변수 |
| int | timer | 30초 시간제한을 사용하기 위한 변수 |
| int | cheat | 치트모드를 활성화하기 위한 변수 |
| int | all | Total Score의 Label값을 변경하기 위해 사용하는 지역변수 |
| int | score | 현재 취득한 값을 Score section에 반영하기 위해 사용하는 지역변수 |
| int | bonus | digits dice score에서 bonus label을 업데이트하기 위한 지역변수 |
| string | temp | 함수 내에서 임시적으로 string문을 처리하기 위한 지역변수 |
#### functions.cpp file
| Type | Name | Purpose |
|:---|:---|:---|
| - | - | - |
---
### 3. 프로젝트에서 사용한 함수 설명
---
### 4. user_score class 설명
```c++
class user_score{
public:
    /*
    all: 점수의 총 합이 저장되어있음
    bonus: 1부터 6까지의 점수가 더해져있음
    digits: digit dice section에서 1부터 6까지 점수가 다 들어갔는지 판별하는 용도로 사용됨
    */
    int all, bonus, digits;
    int sum_digit(int flag, user_score& usr1, user_score& usr2); // 점수를 계산해 저장하기 위한 함수
    int calc_current_score(int flag, user_score& usr1, user_score& usr2); // 현재 가지고있는 주사위로 취득할 수 있는 점수가 몇점인지 확인하는 함수
    void reset_variable(); // 게임을 restart 할때 class에 저장된 값들을 리셋시키기 위한 함수
    int current_dice[5] = {0, 0, 0, 0, 0}; // 현재 주사위가 각각 몇점(눈금)인지 저장해두는 배열
    int blank_flag[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // score section에서 점수를 기입해둔 곳은 button이 활성화되지 않게끔 막는 배열
    string check_keep[5] = {"0", "0", "0", "0", "0"}; // 주사위를 hold했는지 여부를 저장해두는 배열
};
``` 
---