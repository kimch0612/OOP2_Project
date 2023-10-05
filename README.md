# Object-oriented Programming Project - Yahtzee Dice
### /// 스크린샷 추가 예정 ///
## 개발 환경
| Type | Content |
|:---|:---|
| OS | Windows 11 22H2 22621.2283 |
| Architecture | amd64 |
| Compiler | Desktop Qt 6.5.2 MinGW 64-bit |
| IDE | Qt Creator 11.0.2 && Code-Server (VSCode) |

## 폴더 구조

    
    ├── CMakeLists.txt               # 빌드환경을 위한 빌드 파일을 생성하는 유틸리티입니다.
    ├── CMakeLists.txt.user          # 빌드환경을 위한 빌드 파일을 생성하는 유틸리티입니다.
    ├── functions.h                  # 프로그램의 백엔드와 같은 함수들이 담겨있는 헤더파일입니다.
    ├── icon.png                     # 프로그램의 아이콘 파일입니다.
    ├── main.cpp                     # 이 프로그램의 메인 C++ 파일로, GUI를 불러오는 역할을 합니다.
    ├── mainwindow.cpp               # 이 프로그램의 주 C++ 파일로, 프로그램의 GUI 구성 및 동작에 필요한 코드가 여기에 있습니다.
    ├── mainwindow.h                 # 이 프로그램에서 사용된 함수나 기타 기능들이 정의돼있습니다.
    ├── mainwindow.ui                # 이 프로그램의 GUI 관련 코드가 이곳에 있습니다.
    └── README.md                    # 마크다운 문법으로 작성된 프로그램의 소개 페이지입니다.

## 빌드 및 실행방법
- CMakeLists.txt 파일을 Qt Creator IDE로 실행합니다.
- 디버깅 모드로 빌드 및 실행합니다.

## To do list
구현하는데 있어서 더 높은 우선순위를 갖는 기능을 각 메뉴에서 더 상위에 위치하게끔 작성함.
- [X] README.md 파일 작성
- [X] 베이스 파일 작성
- [ ] 메인 기능 구현
  - [ ] UI 구성
    - [X] Base UI 구성
    - [ ] 현재 랜덤으로 굴린 주사위의 눈이 나올 Section
    - [ ] 현재 주사위의 족보로 취득할 수 있는 '가장 높은' 점수를 알려주는 기능
    - [ ] 현재 주사위의 족보로 취득할 수 있는 점수를 알려주는 기능
    - [ ] 게임이 끝날시 끝났다고 알려줄 UI
    - [ ] how to? UI 구현
    - [ ] credits UI 구현
  - [ ] 주사위 기능 구현
    - [X] 주사위 5개가 랜덤으로 나오는 기능
    - [ ] 랜덤으로 나온 수와 주사위 이미지를 매칭시켜서 출력하는 기능
    - [ ] 주사위의 HOLD 기능
  - [ ] Yahtzee 룰 관련 기능
    - [ ] 주사위 1~6 눈금의 합
    - [ ] Choice~Yahtzee 족보
    - [ ] 위의 총합이 63일때 추가점수
    - [ ] 라운드마다 시간제한 기능
    - [ ] 점수 비교 후 승자 결정
- [ ] 게임 종료 후 계속할 것인지 묻는 기능
- [ ] 게임의 룰을 소개하는 기능

## 예상되는 문제점
- Base UI의 크기를 유저가 임의로 조정했을때?
- 개발할때 기준으로 잡은 해상도(1920x1080)보다 크거나 작은 환경에서 구동했을때?
- 초저사양 환경에서 구동했을때?

## 주차별 활동내역
- 1주차
  - 조원 결성
  - 개발 예정작 결정; Yahtzee Dice Board Game
  - Project Repository create && initialize
- 2주차
  - 팀명 결정; Dice team
  - 대략적인 스케쥴 계획 수립
  - UI 컨셉 결정
- 3주차
  - 더 자세한 UI 컨셉 결정
  - 이후의 일정 계획 수립
  - 프로그램 동작 관련 Flow Chart 구성
  - Windows에서 더 안정적인 실행을 위해 개발 환경을 변경함; Ubuntu Server -> Windows 11
- 4주차
  - 더 안정적인 GUI 대응을 위해 최종적으로 개발 환경을 VS2022에서 Qt Creator로 변경함.
  - Base UI 제작
- 5주차
  - Base UI 확정 및 구현
  - 기본 기능중 일부의 pipeline을 GUI에 연결함
- 6주차 
  - README.md 파일을 더 자세하게 작성함
  - 주사위 관련 icon을 제작함
  - 이미지 경로를 절대경로에서 상대경로로 수정함 (resources.qrc)
