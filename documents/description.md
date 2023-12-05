# Yahztee Dice Program Description

## INDEX
1. [Variables Part](#1-프로젝트에서-사용한-변수-설명)
2. [Functions Part](#2-프로젝트에서-사용한-함수-설명)
3. [FlowChart](#3-program의-flowchart)
---
### 1. 프로젝트에서 사용한 변수 설명
#### mainwindow.cpp
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
#### functions.cpp
| Type | Name | Purpose |
|:---|:---|:---|
| int | temp | sum_digit()함수에서 값을 return하기 전까지 결괏값을 임시 저장하는 지역변수 |
| int | check_num | straight 시리즈에서 값이 유효한지 확인하기 위한 지역변수 |
| int | tmp[] | - |
| bool | flag1 | - |
#### functions.h
| Type | Name | Purpose |
|:---|:---|:---|
| int | all | 점수의 총 합이 저장되어있는 변수 |
| int | bonus | 1부터 6까지의 점수가 더해져있는 변수 |
| int | digits | digit dice section에서 1부터 6까지 점수가 다 들어갔는지 판별하는 용도로 사용하는 변수 |
| int | current_dice[5] | 현재 주사위가 각각 몇점(눈금)인지 저장해두는 배열 |
| int | blank_flag[12] | score section에서 점수를 기입해둔 곳은 button이 활성화되지 않게끔 막는 배열 |
| string | check_keep[5] | 주사위를 hold했는지 여부를 저장해두는 배열 |
---
### 2. 프로젝트에서 사용한 함수 설명
### mainwindow.cpp
#### MainWindow::MainWindow(QWidget *parent)
```c++
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/icon/images/icon.png")); // 프로그램의 icon 설정
    setStyleSheet("background-color:blck"); // 프로그램의 배경 색 설정
    QMainWindow::setWindowFlags( Qt::WindowTitleHint |  Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint );
    ui->setupUi(this);
    QList<QWidget*> widgetsToHide = { // 처음 시작했을 때 불필요한 Object의 리스트
        ui->oneonebutton, ui->twoonebutton, ui->threeonebutton, ui->fouronebutton, ui->fiveonebutton, ui->sixonebutton,
        ui->choiceonebutton, ui->fkindonebutton, ui->fullhouseonebutton, ui->sstraightonebutton, ui->lstraightonebutton, ui->yahtzeeonebutton,
        ui->totalone, ui->onetwobutton, ui->twotwobutton, ui->threetwobutton, ui->fourtwobutton, ui->fivetwobutton, ui->sixtwobutton,
        ui->choicetwobutton, ui->fkindtwobutton, ui->fullhousetwobutton, ui->sstraighttwobutton, ui->lstraighttwobutton, ui->yahtzeetwobutton,
        ui->totaltwo, ui->backbutton, ui->reroll, ui->keep1, ui->keep2, ui->keep3, ui->keep4, ui->keep5,
        ui->keep1b, ui->keep2b, ui->keep3b, ui->keep4b, ui->keep5b, ui->creditone, ui->backbutton, ui->bonusone, ui->bonustwo,
        ui->bonusonebutton, ui->pushButton, ui->backbutton, ui->restart, ui->pushButton_2
    };
    for (QWidget* widget : widgetsToHide) {
        widget->setVisible(false); // 모두 보이지 않게끔 설정함
    }
    // credit 내에 있는 첫번째 item의 hyper link 설정
    ui -> creditone -> setText("<a href=\"https://www.pngwing.com/en/free-png-sptdk/\">Program Title icon</a>");
    ui -> creditone -> setTextFormat(Qt::RichText);
    ui -> creditone -> setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui -> creditone -> setOpenExternalLinks(true);
}
``` 
#### void MainWindow::on_startbutton_clicked()
``` c++
void MainWindow::on_startbutton_clicked() // MainWindow에 있는 Start button을 Click 했을 때 실행할 이벤트 
{
    QList<QWidget*> widgetsToHide = {ui->gamestart, ui->startbutton, ui->howtobutton, ui->creditsbutton, ui->exitbutton, ui->backbutton, ui->gamestart, ui->restart};
    for (QWidget* widget : widgetsToHide) {
        widget->setVisible(false); // 게임을 시작했을 때 불필요한 요소들을 보이지 않게끔 처리
    }
    QList<QWidget*> widgetsToShow = {
        ui->oneonebutton, ui->twoonebutton, ui->threeonebutton, ui->fouronebutton, ui->fiveonebutton, ui->sixonebutton,
        ui->choiceonebutton, ui->fkindonebutton, ui->fullhouseonebutton, ui->sstraightonebutton, ui->lstraightonebutton, ui->yahtzeeonebutton,
        ui->totalone, ui->totaltwo, ui->reroll, ui->keep1, ui->keep2, ui->keep3, ui->keep4, ui->keep5,
        ui->keep1b, ui->keep2b, ui->keep3b, ui->keep4b, ui->keep5b, ui->bonusone, ui->bonustwo
    };
    for (QWidget* widget : widgetsToShow) {
        widget->setVisible(true); // 게임을 시작했을 때 필요한 요소들을 보이게끔 처리
    }
    
    //턴이 홀수라면 Player 1, 짝수라면 Player 2가 플레이 중이라고 Label을 업데이트
    if (turn % 2 == 1)
        ui->playingplayer->setText("Player 1 is in control...");
    else if (turn % 2 == 0)
        ui->playingplayer->setText("Player 2 is in control...");

    init_dice(); // 주사위 초기값 설정
    ui -> lefttime -> setText("3 left"); // 남은 턴 횟수 표시
    ui -> category -> setText("← Choose category"); // 카테고리 관련 라벨 표시
    Calc_Current_Score(); // 현재 나온 주사위로 얻을 수 있는 점수 계산
    // Turn 종료 관련 Timer 선언 및 시작
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(timeout()));
    Timer->start(30000);
    // User에게 자신의 턴이 몇 초나 남았는지 알려주는 Timer 선언 및 시작
    Timer_label = new QTimer(this);
    connect(Timer_label, SIGNAL(timeout()), this, SLOT(timer_update()));
    Timer_label->start(1000);
}
```
#### void MainWindow::on_exitbutton_clicked()
```c++
void MainWindow::on_exitbutton_clicked() // MainWindow 내에 있는 exit 버튼 클릭 시
{
    QCoreApplication::exit(0); // 프로그램 종료
}
```
#### void MainWindow::on_creditsbutton_clicked()
```c++
void MainWindow::on_creditsbutton_clicked()
{
    // Credit에 필요한 objects는 표시, 불필요한 objects는 숨김처리 함
    ui->playingplayer->setText("이 프로그램에 사용한 Open Source / Copyleft Source");
    ui->gamestart->setVisible(false);
    ui->startbutton->setVisible(false);
    ui->howtobutton->setVisible(false);
    ui->creditsbutton->setVisible(false);
    ui->exitbutton->setVisible(false);
    ui -> creditone -> setVisible(true);
    ui -> backbutton -> setVisible(true);
}
```
#### void MainWindow::on_backbutton_clicked()
```c++
void MainWindow::on_backbutton_clicked()
{
    // Credit에 진입할 때 했던 설정을 반대로 설정해 되돌림
    ui->gamestart->setVisible(true);
    ui->startbutton->setVisible(true);
    ui->howtobutton->setVisible(true);
    ui->creditsbutton->setVisible(true);
    ui->exitbutton->setVisible(true);
    ui->playingplayer->setText("");
    ui -> backbutton -> setVisible(false);
    ui -> creditone -> setVisible(false);
}
```
#### void MainWindow::set_next_turn()
```c++
void MainWindow::set_next_turn()
{
    string temp;

    if (++turn <= 24){ // 1을 증가시킨 턴이 24보다 작거나 같다면 (게임이 끝나지 않았다면)
        if (turn % 2 == 1){ // 턴이 홀수인 경우 Player 1으로 셋팅
            ui->playingplayer->setText("Player 1 is in control...");
            for (int i=0; i<5; i++){
                // 이전 턴에서 사용한 check_keep과 current_dice를 초기화 함
                usr1.check_keep[i] = "0";
                usr1.current_dice[i] = 0;
            }
            /*만약 digits가 6이거나 (1부터 6까지 전부 점수를 채웠거나) bonus의 값이 63보다 같거나 큰 경우에 if문을 들어감
            여기서, Player 1 턴인데 왜 Player 2의 bonus를 계산하는가?
            Player1 턴으로 넘어왔다는 것은 즉, Player 2의 턴이 끝났다는 말이기도 하므로
            혹시 Player 2가 이 조건을 만족하는지 검사하는 것*/
            if (usr2.digits == 6 || usr2.bonus >= 63){ 
                if (usr2.bonus >= 63){ // digits로 조건을 만족해서 들어온 케이스를 위한 if문
                    ui -> bonustwo -> setText("✓");
                    usr2.all += 35; // usr2의 점수에 35점을 더함
                    // GUI에 사용하는 string은 일반 string이 아니므로 전용 QString으로 Casting함
                    QString all_qstr = QString::fromStdString(to_string(usr2.all));
                    ui -> totaltwo -> setText(all_qstr);
                    usr2.digits = 0; // 턴을 넘길 때마다 중복해서 if문이 실행되는 것을 막기위해 0으로 초기화
                } else { // digits가 6이었으나 bonus의 값이 63을 넘기지 못한경우
                    ui -> bonustwo -> setText("X");
                    usr2.digits = 0;
                }
            }
        }
        else if (turn % 2 == 0){ // 턴이 홀수인 경우 Player 2로 셋팅
            ui->playingplayer->setText("Player 2 is in control...");
            for (int i=0; i<5; i++){
                usr2.check_keep[i] = "0";
                usr2.current_dice[i] = 0;
            }
            if (usr1.digits == 6 || usr1.bonus >= 63){ // 위와 마찬가지로 Player 1의 bonus를 검사
                if (usr1.bonus >= 63){
                    usr1.all += 35;
                    ui -> bonusone -> setText("✓");
                    QString all_qstr = QString::fromStdString(to_string(usr1.all));
                    ui -> totalone -> setText(all_qstr);
                    usr1.digits = 0;
                } else {
                    ui -> bonusone -> setText("X");
                    usr1.digits = 0;
                }
            }
        }
        current_turn = 3; // 남은 턴의 횟수를 3으로 초기화
        temp = to_string(current_turn) + " left";
        QString lefttime_qstr = QString::fromStdString(temp);
        ui -> lefttime -> setText(lefttime_qstr);
        init_dice();  // 주사위 초기값 설정
        refresh_keep(); // hold돼 있는 설정들 초기화
        refresh_player_button(); // 현재 턴에 맞는 button 표시
        Calc_Current_Score(); // 현재 나온 주사위로 얻을 수 있는 점수 계산
        timer = 30; // timer를 30초로 다시 초기화
        // 타이머 두개를 멈췄다 다시 시작함으로 재시작 기능 구현
        Timer->stop();
        Timer_label->stop();
        Timer->start(30000);
        Timer_label->start(1000);
    } else { // 턴이 24를 넘겨 종료됐다면
        Final_Score(); // 최종 승자 결정
    }
}
```
#### MainWindow::on_oneonebutton_clicked() // Player 1의 Aces 버튼 클릭 시
```c++
/*점수를 기입하는 버튼의 Object name은 [button number][Player]button 으로 구성되어있다.
ex) oneonebutton / onetwobutton
    choiceonebutton / yahtzeetwobutton
작동하는 방식은 모두 거의 유사하므로 대표로 oneonebutton만 기술함*/
void MainWindow::on_oneonebutton_clicked()
{
    int score, all, bonus;

    score = usr1.sum_digit(1); // sum_digit에 flag 1을 주고 return받은 값을 score에 대입함
    all = usr1.all; // Player 1의 점수를 all에 저장함
    /*Player 1의 bonus 점수를 bonus에 저장함
    bonus는 1부터 6까지만 존재함*/
    bonus = usr1.bonus;
    /*Player 1이 1번째 칸에 점수를 기입했다는 뜻으로
    Aces(0)부터 Yahztee(11)까지 총 12개의 칸이 존재한다.
    이는 추후에 refresh_player_button() 함수를 호출했을 때 이미 기입한 칸에는 점수 기입 버튼이
    다시 활성화되지 않게끔 막는 역할을 한다.*/
    usr1.blank_flag[0] = 1;

    // GUI에서 사용할 수 있게끔 Casting함
    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    QString bonus_qstr = QString::fromStdString(to_string(bonus));
    // GUI의 Label값을 최신화 함
    ui -> oneone -> setText(text_qstr);
    ui -> totalone -> setText(all_qstr);
    ui -> bonusone -> setText(bonus_qstr);
    ui -> oneonebutton -> setVisible(false);
    set_next_turn(); // 다음 턴으로 전환
}
```
#### void MainWindow::init_dice()
```c++
void MainWindow::init_dice()
{
    QPixmap dice_images[6]; // 주사위 6개의 이미지를 배열로 정의함
    dice_images[0].load(":/dice/images/one.png");
    dice_images[1].load(":/dice/images/two.png");
    dice_images[2].load(":/dice/images/three.png");
    dice_images[3].load(":/dice/images/four.png");
    dice_images[4].load(":/dice/images/five.png");
    dice_images[5].load(":/dice/images/six.png");
    int dice[5]; // dice_gen()을 통해 생성한 주사위를 임시 저장할 배열 선언

    for (int i = 0; i < 5; i++) {
        dice[i] = dice_gen();
        QLabel* diceLabel = nullptr; // 포인터 변수 diceLabel 선언

        switch (i) { // 생성해서 나온 숫자를 몇번째 칸에 띄울지 매칭함
        case 0:
            diceLabel = ui->diceone;
            break;
        case 1:
            diceLabel = ui->dicetwo;
            break;
        case 2:
            diceLabel = ui->dicethree;
            break;
        case 3:
            diceLabel = ui->dicefour;
            break;
        case 4:
            diceLabel = ui->dicefive;
            break;
        }

        if (diceLabel) {
            // 매칭한 주사위 이미지의 사이즈를 셋팅하고 표시함
            diceLabel->setPixmap(dice_images[dice[i] - 1].scaled(50, 50, Qt::KeepAspectRatio));

            if (turn % 2 == 1) { // 현재 턴에 맞는 Player의 current_dice에 값을 저장함
                usr1.current_dice[i] = dice[i];
            } else {
                usr2.current_dice[i] = dice[i];
            }
        }
    }
}
```
#### void MainWindow::refresh_dice()
```c++
void MainWindow::refresh_dice()
{
    // 주사위 이미지와 값을 임시 저장해둘 dice_images와 dice 배열 선언
    QPixmap dice_images[6];
    dice_images[0].load(":/dice/images/one.png");
    dice_images[1].load(":/dice/images/two.png");
    dice_images[2].load(":/dice/images/three.png");
    dice_images[3].load(":/dice/images/four.png");
    dice_images[4].load(":/dice/images/five.png");
    dice_images[5].load(":/dice/images/six.png");
    int dice[5];
    // 삼항연산자를 통해 현재 턴이 누구인지 확인하고, currentUser에 저장함
    user_score& currentUser = (turn % 2 == 1) ? usr1 : usr2;

    QLabel* diceLabels[5] = { // 주사위의 Label 정의
        ui->diceone,
        ui->dicetwo,
        ui->dicethree,
        ui->dicefour,
        ui->dicefive
    };

    for (int i = 0; i < 5; i++){
        /*check_keep에 1이 저장돼있지 않다면 (hold 버튼을 눌러두지 않았다면)
        dice_gen() 함수를 통해 새로 생성한 값을 i번째 dice에 저장하고
        1이 저장돼있다면 i번째 current_dice의 값을 dice에 저장함*/
        if (currentUser.check_keep[i] != "1")
            dice[i] = dice_gen();
        else
            dice[i] = currentUser.current_dice[i];

        //현재의 값에 맞는 주사위를 띄움
        diceLabels[i]->setPixmap(dice_images[dice[i] - 1].scaled(50, 50, Qt::KeepAspectRatio));
    }
    for (int i = 0; i < 5; i++)
        currentUser.current_dice[i] = dice[i]; // current_dice와 dice를 동기화함
}
```
#### void MainWindow::on_reroll_clicked()
```c++
void MainWindow::on_reroll_clicked() // reroll 버튼 클릭 시
{
    if (current_turn > 0){
        string temp;
        refresh_dice(); // 주사위 재생성
        current_turn--; // 남은 턴 횟수를 1만큼 감소시킴
        temp = to_string(current_turn) + " left"; // 남은 턴을 알려주는 label에 사용할 text 정의
        QString lefttime_qstr = QString::fromStdString(temp);
        ui -> lefttime -> setText(lefttime_qstr);
        Calc_Current_Score(); // 새로 뽑은 주사위로 얻을 수 있는 점수 계산
    }
}
```
#### void MainWindow::Calc_Current_Score()
```c++
void MainWindow::Calc_Current_Score()
{
    // Player 1과 2의 버튼들을 각각 배열로 정의함
    QPushButton* usr1_buttons[] = {
        ui->oneonebutton,
        ui->twoonebutton,
        ui->threeonebutton,
        ui->fouronebutton,
        ui->fiveonebutton,
        ui->sixonebutton,
        ui->choiceonebutton,
        ui->fkindonebutton,
        ui->fullhouseonebutton,
        ui->sstraightonebutton,
        ui->lstraightonebutton,
        ui->yahtzeeonebutton
    };
    QPushButton* usr2_buttons[] = {
        ui->onetwobutton,
        ui->twotwobutton,
        ui->threetwobutton,
        ui->fourtwobutton,
        ui->fivetwobutton,
        ui->sixtwobutton,
        ui->choicetwobutton,
        ui->fkindtwobutton,
        ui->fullhousetwobutton,
        ui->sstraighttwobutton,
        ui->lstraighttwobutton,
        ui->yahtzeetwobutton
    };
    if (turn%2==1){ // Player 1의 턴이라면
        for (int i=0; i<12; i++){
            Aces부터 Yahtzee까지 쭉 돌면서 점수를 계산하고, 그 값을 button의 text에 반영함
            QString tmp_qstr = QString::fromStdString(to_string(usr1.calc_current_score(i)));
            usr1_buttons[i]->setText(tmp_qstr);
        }
    } else { // Player 2의 턴이라면
        for (int i=0; i<12; i++){ // 위와 동일
            QString tmp_qstr = QString::fromStdString(to_string(usr2.calc_current_score(i)));
            usr2_buttons[i]->setText(tmp_qstr);
        }
    }
}
```
#### void MainWindow::refresh_keep()
```c++
void MainWindow::refresh_keep()
{
    // hold가 적혀있던 label들의 값을 초기화함
    ui -> keep1 -> setText("");
    ui -> keep2 -> setText("");
    ui -> keep3 -> setText("");
    ui -> keep4 -> setText("");
    ui -> keep5 -> setText("");
}
```
#### void MainWindow::refresh_player_button()
```c++
void MainWindow::refresh_player_button()
{
    // Player 1과 2의 버튼을 배열에 정의
    QPushButton* usr1_buttons[] = {
        ui->oneonebutton,
        ui->twoonebutton,
        ui->threeonebutton,
        ui->fouronebutton,
        ui->fiveonebutton,
        ui->sixonebutton,
        ui->choiceonebutton,
        ui->fkindonebutton,
        ui->fullhouseonebutton,
        ui->sstraightonebutton,
        ui->lstraightonebutton,
        ui->yahtzeeonebutton
    };
    QPushButton* usr2_buttons[] = {
        ui->onetwobutton,
        ui->twotwobutton,
        ui->threetwobutton,
        ui->fourtwobutton,
        ui->fivetwobutton,
        ui->sixtwobutton,
        ui->choicetwobutton,
        ui->fkindtwobutton,
        ui->fullhousetwobutton,
        ui->sstraighttwobutton,
        ui->lstraighttwobutton,
        ui->yahtzeetwobutton
    };
    if (turn % 2 == 1) { // Player 1의 턴이라면
        for (QPushButton* button : usr2_buttons)
            button->setVisible(false); // Player 2의 버튼을 모두 비활성화
        for (int i = 0; i < 12; i++) {
            // blank_flag가 1이 아닌 버튼들에 한해서만 활성화
            if (usr1.blank_flag[i] != 1)
                usr1_buttons[i]->setVisible(true);
        }
    } else {
        for (QPushButton* button : usr1_buttons)
            button->setVisible(false);
        for (int i = 0; i < 12; i++) {
            if (usr2.blank_flag[i] != 1)
                usr2_buttons[i]->setVisible(true);
        }
    }
}
```
#### void MainWindow::on_keep1b_clicked() // 1번째 주사위의 hold 버튼 클릭 시
```c++
/*keep 함수는 1부터 5까지 존재하며, 각각의 작동 방식은 모두 동일함
이 문서에서는 keep1b만 예시로 설명함*/
void MainWindow::on_keep1b_clicked()
{
    // 삼항연산자로 내가 수정하고자 하는 Player의 check_keep의 주소값을 받아옴
    string& CheckKeep = (turn % 2 == 1) ? usr1.check_keep[0] : usr2.check_keep[0];

    if (CheckKeep == "0") { // 만약 값이 0이라면 keep1의 text는 hold로, 값은 1로 설정함
        ui->keep1->setText("hold");
        CheckKeep = "1";
    } else { // 값이 1이라면 keep1의 text는 지우고, 값은 0으로 설정함
        ui->keep1->setText("");
        CheckKeep = "0";
    }
}
```
#### void MainWindow::on_howtobutton_clicked()
```c++
void MainWindow::on_howtobutton_clicked() // MainWindow에서 manual 버튼을 클릭했을 때
{
    QDesktopServices::openUrl(QUrl("https://github.com/kimch0612/OOP2_Project/blob/master/documents/manual.md", QUrl::TolerantMode)); // 해당 URL로 이동하게끔 설정
    if (++cheat==3) ui->pushButton_2->setVisible(true);
}
```
#### void MainWindow::Final_Score()
```c++
void MainWindow::Final_Score()
{
    // 게임 플레이중에 사용한 label들을 모두 비활성화
    QList<QWidget*> widgetsToHide = {
        ui->category, ui->playingplayer, ui->diceone,
        ui->dicetwo, ui->dicethree, ui->dicefour,
        ui->dicefive, ui->keep1b, ui->keep2b,
        ui->keep3b, ui->keep4b, ui->keep5b,
        ui->reroll, ui->lefttime, ui->keep1,
        ui->keep2, ui->keep3, ui->keep4,
        ui->keep5, ui->timer_label
    };
    for (QWidget* widget : widgetsToHide) {
        widget->setVisible(false);
    }
    ui->gamestart->setVisible(true);
    ui->gamestart->setText("Game Set!");
    // calc_score(usr1, usr2) 함수를 실행해 나온 값을 기준으로 누가 이겼는지 표시함
    if (calc_score(usr1, usr2) == 0)
        ui->gameset->setText("User 1 Win!");
    else if (calc_score(usr1, usr2) == 1)
        ui->gameset->setText("User 2 Win!");
    else
        ui->gameset->setText("Draw");
    // restart 버튼과 exit 버튼을 활성화
    ui->restart->setVisible(true);
    ui->exitbutton->setVisible(true);
}
```
#### void MainWindow:: timer_update()
```c++
// 1초마다 Timer_label에 의해 실행되는 함수
void MainWindow:: timer_update()
{
    // timer에서 1초만큼 감소시킨 값을 Player에게 보여줌으로써 자신의 턴이 몇초가 남았는지 알려줌
    timer--;
    string temp = "⏳" + to_string(timer) + "sec";
    QString lefttimer = QString::fromStdString(temp);
    ui->timer_label->setText(lefttimer);
}
```
#### void MainWindow:: timeout()
```c++
// 30초가 지나면 Timer에 의해 실행되는 함수
void MainWindow:: timeout()
{
    current_turn = 0; // 남은 턴을 0으로 초기화
    string temp2 = "⏳0sec"; // 남은 시간을 0으로 표시
    QString lefttimer = QString::fromStdString(temp2);
    ui->timer_label->setText(lefttimer);
    string temp1 = "timeout!"; // timeout 표시
    QString lefttime_qstr = QString::fromStdString(temp1);
    ui -> lefttime -> setText(lefttime_qstr);
    Timer_label->stop(); // 같이 돌고있던 Timer_label 중지
}
```
#### void MainWindow::on_restart_clicked() // restart 버튼 클릭 시
```c++
void MainWindow::on_restart_clicked()
{
    // 값을 초기화해야 하는 label들을 배열로 정의
    QList<QLabel*> widgetsToReset = {
        ui->oneone, ui->twoone, ui->threeone, ui->fourone, ui->fiveone, ui->sixone,
        ui->choiceone, ui->fkindone, ui->fullhouseone, ui->sstraightone, ui->lstraightone, ui->yahtzeeone,
        ui->onetwo, ui->twotwo, ui->threetwo, ui->fourtwo, ui->fivetwo, ui->sixtwo,
        ui->choicetwo, ui->fkindtwo, ui->fullhousetwo, ui->sstraighttwo, ui->lstraighttwo, ui->yahtzeetwo
    };
    for (QLabel* widget : widgetsToReset) {
        widget->setText(""); // 값을 초기화
    }
    QList<QWidget*> widgetsToShow = { // 숨겨놨던 게임에 필요한 Object들을 다시 활성화
        ui->oneonebutton, ui->twoonebutton, ui->threeonebutton, ui->fouronebutton, ui->fiveonebutton, ui->sixonebutton,
        ui->choiceonebutton, ui->fkindonebutton, ui->fullhouseonebutton, ui->sstraightonebutton, ui->lstraightonebutton, ui->yahtzeeonebutton,
        ui->totalone, ui->totaltwo, ui->reroll, ui->keep1, ui->keep2, ui->keep3, ui->keep4, ui->keep5,
        ui->keep1b, ui->keep2b, ui->keep3b, ui->keep4b, ui->keep5b, ui->bonusone, ui->bonustwo, ui->category, ui->playingplayer, ui->diceone,
        ui->dicetwo, ui->dicethree, ui->dicefour, ui->dicefive, ui->keep1b, ui->keep2b, ui->keep3b, ui->keep4b, ui->keep5b,
        ui->reroll, ui->lefttime, ui->keep1, ui->keep2, ui->keep3, ui->keep4, ui->keep5, ui->timer_label
    };
    for (QWidget* widget : widgetsToShow) {
        widget->setVisible(true);
    }
    // restart 버튼과 exit 버튼을 비활성화
    ui->restart->setVisible(false);
    ui->exitbutton->setVisible(false);
    // total과 bonus의 label을 0으로 초기화
    ui->totalone->setText("0");
    ui->totaltwo->setText("0");
    ui->bonusone->setText("0");
    ui->bonustwo->setText("0");
    // 승자를 알려주던 label의 text를 삭제
    ui->gameset->setText("");
    // Player 1과 2의 멤버 변수들을 초기화
    usr1.reset_variable();
    usr2.reset_variable();
    // 턴과 현재 남은 턴을 초기화
    turn=1, current_turn=3;
    // 두개의 Timer를 정지
    Timer->stop();
    Timer_label->stop();
    // 맨 처음에 start 버튼을 누른 것과 동일하게 게임을 시작
    on_startbutton_clicked();
}
```
### functions.cpp
#### int user_score:: sum_digit(int flag)
```c++
int user_score:: sum_digit(int flag)
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
                조건을 만족하지 못해 else if문을 돌지 못한다.*/
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
#### int user_score:: calc_current_score(int flag)
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
#### int calc_score(user_score usr1, user_score usr2)
```c++
int calc_score(user_score usr1, user_score usr2)
{
    if (usr1.all > usr2.all) return 0; // usr1의 점수가 usr2의 점수보다 높다면 0을 리턴한다.
    else if (usr1.all < usr2.all) return 1; // 그 반대라면 1을 리턴한다.
    else return 2; // 점수가 동일한 경우 2를 리턴한다.
}
``` 
#### void user_score:: reset_variable()
```c++
void user_score:: reset_variable()
{
    // functions.h에서 선언한 멤버 변수들을 초기화해준다.
    all=0, bonus=0, digits=0;
    for (int i=0; i<5; i++)
    {
        current_dice[i] = 0;
        check_keep[i] = "0";
    }
    for (int i=0; i<12; i++)
        blank_flag[i] = 0;
}
``` 
---
### 3. Program의 FlowChart
![image](https://github.com/kimch0612/OOP2_Project/assets/10193967/6225d834-0f2f-4350-a48c-66202d53c841)


---
끝.
