# Yahztee Dice Program Description

## 목차
1. [GUI 파트에서 사용한 Object들의 Object-Name 설명](#1-gui-파트에서-사용한-object들의-object-name-설명)
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
#### mainwindow.cpp file
```c++
``` 
---