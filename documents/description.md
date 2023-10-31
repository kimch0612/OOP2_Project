# Yahztee Dice Program Description

## 목차
1. [GUI 파트에서 사용한 Object들의 Object-Name 설명](#1-gui-파트에서-사용한-object의-object-name-설명)
2. [프로젝트에서 사용한 변수 설명](#2-프로젝트에서-사용한-변수-설명)
3. [프로젝트에서 사용한 함수 설명](#3-프로젝트에서-사용한-함수-설명)
---
### 1. GUI 파트에서 사용한 Object의 Object Name 설명
| Section | Type | Name | Purpose |
|:---|:---|:---|:---|
| - | - | - | - |
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
| int | dice[5] | dice_gen() 함수를 통해 생성한 난수를 저장해두기 위한 지역배열 |
| string | temp | 함수 내에서 임시적으로 string문을 처리하기 위한 지역변수 |
| string | check_keep | 이 주사위가 현재 hold되어있는지 확인하는 지역 문자열 |
#### functions.cpp file
| Type | Name | Purpose |
|:---|:---|:---|
| int | temp | sum_digit()함수에서 값을 return하기 전까지 결괏값을 임시 저장하는 지역변수 |
| int | check_num | straight 시리즈에서 값이 유효한지 확인하기 위한 지역변수 |
| int | tmp[] | - |
| bool | flag1 | - |
#### functions.h file
| Type | Name | Purpose |
|:---|:---|:---|
| int | all | 점수의 총 합이 저장되어있는 변수 |
| int | bonus | 1부터 6까지의 점수가 더해져있는 변수 |
| int | digits | digit dice section에서 1부터 6까지 점수가 다 들어갔는지 판별하는 용도로 사용하는 변수 |
| int | current_dice[5] | 현재 주사위가 각각 몇점(눈금)인지 저장해두는 배열 |
| int | blank_flag[12] | score section에서 점수를 기입해둔 곳은 button이 활성화되지 않게끔 막는 배열 |
| string | check_keep[5] | 주사위를 hold했는지 여부를 저장해두는 배열 |
---
### 3. 프로젝트에서 사용한 함수 설명
mainwindow.cpp file
```c++
``` 
functions.cpp file
#### user_score:: sum_digit(int flag, user_score& usr1, user_score& usr2)
```c++
int user_score:: sum_digit(int flag, user_score& usr1, user_score& usr2)
{
    int i, check_num = 0, temp = 0;
    int tmp[] = {0, 0, 0, 0, 0, 0};
    bool flag1 = true;
    switch(flag) // 인자로 받은 int형 flag에 따라 어떤 연산을 진행할지 결정한다.
    {
        /*
        Aces ~ Sixes까지의 연산 Algorithm
        i번째 current_dice가 n인 경우에만 temp에 값을 더하고, 그 값을 all에도 똑같이 더해준다.
        그 후, bonus 계산을 위해 digits를 1만큼 더하고 bonus에 취득한 점수를 더해준다.
        bonus에 대한 계산은 mainwindow.cpp 파일 내에 있는 set_next_turn() 멤버 함수에서 진행된다.
        */
        case 1: // Aces
            for (i=0; i<5; i++)
                if (current_dice[i] == 1) temp += current_dice[i];
            digits++;
            all += temp;
            bonus += temp;
            break;
        // 중략
        case 7: // Bonus
            all += 35;
            break;
        case 8: // Choice
        /* Choice의 경우에는 현재 갖고있는 주사위를 모두 더해주면 되기에 
        current_dice의 값을 모두 temp에 더해준다.*/
            for (i=0; i<5; i++)
                temp += current_dice[i]; 
            all += temp;
            break;
        case 9: // 4 kind
        /*4 kind의 경우에는 주사위 4개가 동일해야 하므로 
        tmp배열에 '주사위 눈금 - 1'칸에 1씩 값을 더해 주사위의 개수를 카운트한다.*/
            for (i=0; i<5; i++)
                tmp[current_dice[i] - 1] += 1;
            for (i=0; i<6; i++)
            {
                if (tmp[i] >= 4) // 만약 합이 4개가 넘는 경우가 존재한다면,
                {
                    /*temp에 '주사위 눈금 + 1'을 곱해 원래 주사위로 복원한 값을 더해준다
                    ex) 주사위가 3이 4개, 6이 1개가 나왔다고 가정하면
                    tmp[2] == 4이고, tmp[5] == 1이 나올 것이며,
                    복원 작업을 통해 각각 tmp[2] * (2 + 1) == 12
                    tmp[5] * (5 + 1) == 6이므로 temp에는 총 18이 들어간다.*/
                    for (int index=0; index<6; index++)
                        temp += tmp[index] * (index + 1);
                }
            }
            all += temp;
            break;
        case 10: // Full House
            for (i=0; i<5; i++) // 4 kind와 마찬가지로 주사위의 개수를 카운트한다.
                tmp[current_dice[i] - 1] += 1;
            for (i=0; i<6; i++)
            {
                if (tmp[i] == 2) // 만약 주사위의 개수가 2개인 경우가 존재한다면,
                {
                    for (int index=0; index<6; index++) // 다시 처음부터 for문을 돌린다
                    {
                        /*주사위의 개수가 3개인 경우가 존재한다면
                        즉, 주사위의 개수가 2개도 만족하면서 3개도 만족하는 경우가 존재한다면,*/
                        if (tmp[index] == 3)
                        {
                            temp = tmp[i]*(i+1) + tmp[index]*(index+1);
                            // 4 kind와 마찬가지로 temp에 복원작업을 통해 점수를 기입한다.
                            all += temp;
                        }
                    }
                }
            }
            break;
        case 11: // S. Straight
            for (i=0; i<5; i++)
                tmp[current_dice[i] - 1] += 1; // 주사위의 개수를 카운트한다.
            for (i=0; i<6; i++)
                // 주사위의 개수가 1인 경우 check_num에 1을 더한다.
                if (tmp[i] == 1) check_num++;
                /*만약 주사위가 2인 경우 1회에 한해 허용해줘야 하므로
                (ex. 주사위가 1 1 2 3 4 인 경우에도 S. Straight가 성립함.)
                check_num에 1을 더하고 flag1를 꺾는다.
                이후에 또 주사위가 2개인 경우가 나타나다면 flag1이 꺾여있는 상태이므로
                조건을 만족하지 못해 else if문을 돌지 못한다.
                */
                else if (tmp[i] == 2 && flag1){
                    check_num++;
                    flag1 = false;
                }
            // 만약 check_num이 4보다 크거나 같은 경우 temp에 15를 대입한다.
            if (check_num >= 4)
                temp = 15;
            all += temp;
            break;
        case 12: // L. Straight
            /*전체적인 구조는 S. Straight와 동일하나, L. Striaght는 중복을 허용하지 않으므로
            S. Striaght에 있던 else if문이 존재하지 않으며, check_num 또한 5개로 고정된다.*/
            for (i=0; i<5; i++)
                tmp[current_dice[i] - 1] += 1;
            for (i=0; i<6; i++)
                if (tmp[i] == 1) check_num++;
            if (check_num == 5)
                temp = 30; // 조건을 만족했다면 temp에 30점을 대입한다.
            all += temp;
            break;
        case 13: // Yahtzee
            for (i=0; i<5; i++){
                // 맨 첫번째 주사위와 i번째 주사위가 다르다면 Yahtzee의 조건을 만족하지 못하므로 0을 return한다.
                if (current_dice[i] == 0 || current_dice[0] != current_dice[i])
                    return 0;
            }
            temp = 50; // 첫번째부터 마지막까지 모두 동일한 주사위라 for문을 통과했다면 temp에 50을 대입한다.
            all += temp;
            break;
    }
    return temp; // 계산한 값을 label에도 적용해줘야 하므로 temp값을 return 해준다.
}
``` 
#### user_score:: calc_current_score(int flag, user_score& usr1, user_score& usr2)
```c++
/*작동 방식은 sum_digit 함수와 완전히 동일하고, 점수를 반영할 필요가 없으므로
all에 값을 더하는 작업만 삭제된 함수이다.*/
``` 
#### int dice_gen(void)
```c++
int dice_gen(void)
{
    random_device rd; // 랜덤 값을 생성하기 위해 시드 값(랜덤 시드)를 생성한다.
    mt19937 gen(rd()); // Mersenne Twister 19937 엔진을 초기화하고 시드 값을 사용한다.
    // 균등 분포에서 1부터 6까지의 정수를 생성하는 객체를 생성한다.
    uniform_int_distribution<int> dis(1, 6); 
    return dis(gen); // 생성한 객체를 return한다.
}
``` 
---
