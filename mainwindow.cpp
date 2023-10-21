#include "functions.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

int turn=0, current_turn=3;
user_score usr1;
user_score usr2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon(":/icon/images/icon.png"));
    setStyleSheet("background-color:blck");
    QMainWindow::setWindowFlags( Qt::WindowTitleHint |  Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint );
    ui->setupUi(this);
    ui -> oneonebutton -> setVisible(false);
    ui -> twoonebutton -> setVisible(false);
    ui -> threeonebutton -> setVisible(false);
    ui -> fouronebutton -> setVisible(false);
    ui -> fiveonebutton -> setVisible(false);
    ui -> sixonebutton -> setVisible(false);
    ui -> choiceonebutton -> setVisible(false);
    ui -> fkindonebutton -> setVisible(false);
    ui -> fullhouseonebutton -> setVisible(false);
    ui -> sstraightonebutton -> setVisible(false);
    ui -> lstraightonebutton -> setVisible(false);
    ui -> yahtzeeonebutton -> setVisible(false);
    ui -> totalone -> setVisible(false);
    ui -> onetwobutton -> setVisible(false);
    ui -> twotwobutton -> setVisible(false);
    ui -> threetwobutton -> setVisible(false);
    ui -> fourtwobutton -> setVisible(false);
    ui -> fivetwobutton -> setVisible(false);
    ui -> sixtwobutton -> setVisible(false);
    ui -> choicetwobutton -> setVisible(false);
    ui -> fkindtwobutton -> setVisible(false);
    ui -> fullhousetwobutton -> setVisible(false);
    ui -> sstraighttwobutton -> setVisible(false);
    ui -> lstraighttwobutton -> setVisible(false);
    ui -> yahtzeetwobutton -> setVisible(false);
    ui -> totaltwo -> setVisible(false);
    ui -> backbutton -> setVisible(false);
    ui -> reroll -> setVisible(false);
    ui -> keep1 -> setVisible(false);
    ui -> keep2 -> setVisible(false);
    ui -> keep3 -> setVisible(false);
    ui -> keep4 -> setVisible(false);
    ui -> keep5 -> setVisible(false);
    ui -> keep1b -> setVisible(false);
    ui -> keep2b -> setVisible(false);
    ui -> keep3b -> setVisible(false);
    ui -> keep4b -> setVisible(false);
    ui -> keep5b -> setVisible(false);
    ui -> backbutton -> setVisible(true);
    ui -> creditone -> setText("<a href=\"https://www.pngwing.com/en/free-png-sptdk/\">Program Title icon</a>");
    ui -> creditone -> setTextFormat(Qt::RichText);
    ui -> creditone -> setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui -> creditone -> setOpenExternalLinks(true);
    ui -> creditone -> setVisible(false);
    ui -> backbutton -> setVisible(false);
    ui -> bonusone -> setVisible(false);
    ui -> bonustwo -> setVisible(false);
    ui -> bonusonebutton -> setVisible(false);
    ui -> pushButton -> setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startbutton_clicked()
{
    bool flag = true;
    ui->gamestart->setVisible(false);
    ui->startbutton->setVisible(false);
    ui->howtobutton->setVisible(false);
    ui->creditsbutton->setVisible(false);
    ui->exitbutton->setVisible(false);
    ui -> oneonebutton -> setVisible(true);
    ui -> twoonebutton -> setVisible(true);
    ui -> threeonebutton -> setVisible(true);
    ui -> fouronebutton -> setVisible(true);
    ui -> fiveonebutton -> setVisible(true);
    ui -> sixonebutton -> setVisible(true);
    ui -> choiceonebutton -> setVisible(true);
    ui -> fkindonebutton -> setVisible(true);
    ui -> fullhouseonebutton -> setVisible(true);
    ui -> sstraightonebutton -> setVisible(true);
    ui -> lstraightonebutton -> setVisible(true);
    ui -> yahtzeeonebutton -> setVisible(true);
    ui -> totalone -> setVisible(true);
    ui -> totaltwo -> setVisible(true);
    ui -> reroll -> setVisible(true);
    ui -> keep1 -> setVisible(true);
    ui -> keep2 -> setVisible(true);
    ui -> keep3 -> setVisible(true);
    ui -> keep4 -> setVisible(true);
    ui -> keep5 -> setVisible(true);
    ui -> keep1b -> setVisible(true);
    ui -> keep2b -> setVisible(true);
    ui -> keep3b -> setVisible(true);
    ui -> keep4b -> setVisible(true);
    ui -> keep5b -> setVisible(true);
    ui -> bonusone -> setVisible(true);
    ui -> bonustwo -> setVisible(true);

    if (turn == 27)
        final_score();

    turn++;
    if (turn % 2 == 1)
        ui->playingplayer->setText("Player 1 is in control...");
    else if (turn % 2 == 0)
        ui->playingplayer->setText("Player 2 is in control...");

    init_dice();

    ui -> lefttime -> setText("3 left");
    ui -> category -> setText("← Choose category");
}

void MainWindow::on_exitbutton_clicked()
{
    QCoreApplication::exit(0);
}


void MainWindow::on_creditsbutton_clicked()
{
    ui->playingplayer->setText("이 프로그램에 사용한 Open Source / Copyleft Source");
    ui->gamestart->setVisible(false);
    ui->startbutton->setVisible(false);
    ui->howtobutton->setVisible(false);
    ui->creditsbutton->setVisible(false);
    ui->exitbutton->setVisible(false);
    ui -> creditone -> setVisible(true);
    ui -> backbutton -> setVisible(true);
}

void MainWindow::on_backbutton_clicked()
{
    ui->gamestart->setVisible(true);
    ui->startbutton->setVisible(true);
    ui->howtobutton->setVisible(true);
    ui->creditsbutton->setVisible(true);
    ui->exitbutton->setVisible(true);
    ui->playingplayer->setText("");
    ui -> backbutton -> setVisible(false);
    ui -> creditone -> setVisible(false);
}

void MainWindow::set_next_turn()
{
    string temp;
    turn++;
    if (turn % 2 == 1)
    {
        ui->playingplayer->setText("Player 1 is in control...");
        for (int i=0; i<5; i++)
        {
            usr1.check_keep[i] = "0";
            usr1.current_dice[i] = 0;
        }
    }
    else if (turn % 2 == 0)
    {
        ui->playingplayer->setText("Player 2 is in control...");
        for (int i=0; i<5; i++)
        {
            usr2.check_keep[i] = "0";
            usr2.current_dice[i] = 0;
        }
    }
    current_turn = 3;
    temp = to_string(current_turn) + " left";
    QString lefttime_qstr = QString::fromStdString(temp);
    ui -> lefttime -> setText(lefttime_qstr);
    init_dice();
    refresh_keep();
    refresh_player_button();
}

void MainWindow::on_oneonebutton_clicked()
{
    int score, all, bonus;

    score = usr1.sum_digit(1, turn, usr1, usr2);
    all = usr1.all;
    bonus = usr1.bonus;
    usr1.blank_flag[0] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    QString bonus_qstr = QString::fromStdString(to_string(bonus));
    ui -> oneone -> setText(text_qstr);
    ui -> totalone -> setText(all_qstr);
    ui -> bonusone -> setText(bonus_qstr);
    ui -> oneonebutton -> setVisible(false);
    set_next_turn();
}

void MainWindow::on_twoonebutton_clicked()
{
    int score, all, bonus;

    score = usr1.sum_digit(2, turn, usr1, usr2);
    all = usr1.all;
    bonus = usr1.bonus;
    usr1.blank_flag[1] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    QString bonus_qstr = QString::fromStdString(to_string(bonus));
    ui -> twoone -> setText(text_qstr);
    ui -> totalone -> setText(all_qstr);
    ui -> bonusone -> setText(bonus_qstr);
    ui -> twoonebutton -> setVisible(false);
    set_next_turn();
}

void MainWindow::on_threeonebutton_clicked()
{
    int score, all, bonus;

    score = usr1.sum_digit(3, turn, usr1, usr2);
    all = usr1.all;
    bonus = usr1.bonus;
    usr1.blank_flag[2] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    QString bonus_qstr = QString::fromStdString(to_string(bonus));
    ui -> threeone -> setText(text_qstr);
    ui -> totalone -> setText(all_qstr);
    ui -> bonusone -> setText(bonus_qstr);
    ui -> threeonebutton -> setVisible(false);
    set_next_turn();
}


void MainWindow::on_fouronebutton_clicked()
{
    int score, all, bonus;

    score = usr1.sum_digit(4, turn, usr1, usr2);
    all = usr1.all;
    bonus = usr1.bonus;
    usr1.blank_flag[3] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    QString bonus_qstr = QString::fromStdString(to_string(bonus));
    ui -> fourone -> setText(text_qstr);
    ui -> totalone -> setText(all_qstr);
    ui -> bonusone -> setText(bonus_qstr);
    ui -> fouronebutton -> setVisible(false);
    set_next_turn();
}


void MainWindow::on_fiveonebutton_clicked()
{
    int score, all, bonus;

    score = usr1.sum_digit(5, turn, usr1, usr2);
    all = usr1.all;
    bonus = usr1.bonus;
    usr1.blank_flag[4] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    QString bonus_qstr = QString::fromStdString(to_string(bonus));
    ui -> fiveone -> setText(text_qstr);
    ui -> totalone -> setText(all_qstr);
    ui -> bonusone -> setText(bonus_qstr);
    ui -> fiveonebutton -> setVisible(false);
    set_next_turn();
}


void MainWindow::on_sixonebutton_clicked()
{
    int score, all, bonus;

    score = usr1.sum_digit(6, turn, usr1, usr2);
    all = usr1.all;
    bonus = usr1.bonus;
    usr1.blank_flag[5] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    QString bonus_qstr = QString::fromStdString(to_string(bonus));
    ui -> sixone -> setText(text_qstr);
    ui -> totalone -> setText(all_qstr);
    ui -> bonusone -> setText(bonus_qstr);
    ui -> sixonebutton -> setVisible(false);
    set_next_turn();
}


void MainWindow::on_choiceonebutton_clicked()
{
    ui -> choiceonebutton -> setVisible(false);
}


void MainWindow::on_fkindonebutton_clicked()
{
    ui -> fkindonebutton -> setVisible(false);
}


void MainWindow::on_fullhouseonebutton_clicked()
{
    ui -> fullhouseonebutton -> setVisible(false);
}


void MainWindow::on_sstraightonebutton_clicked()
{
    ui -> sstraightonebutton -> setVisible(false);
}


void MainWindow::on_lstraightonebutton_clicked()
{
    ui -> lstraightonebutton -> setVisible(false);
}


void MainWindow::on_yahtzeeonebutton_clicked()
{
    ui -> yahtzeeonebutton -> setVisible(false);
}


void MainWindow::on_onetwobutton_clicked()
{
    int score, all, bonus;

    score = usr2.sum_digit(1, turn, usr1, usr2);
    all = usr2.all;
    bonus = usr2.bonus;
    usr2.blank_flag[0] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    QString bonus_qstr = QString::fromStdString(to_string(bonus));
    ui -> onetwo -> setText(text_qstr);
    ui -> totaltwo -> setText(all_qstr);
    ui -> bonustwo -> setText(bonus_qstr);
    ui -> onetwobutton -> setVisible(false);
    set_next_turn();
}


void MainWindow::on_twotwobutton_clicked()
{
    int score, all, bonus;

    score = usr2.sum_digit(2, turn, usr1, usr2);
    all = usr2.all;
    bonus = usr2.bonus;
    usr2.blank_flag[1] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    QString bonus_qstr = QString::fromStdString(to_string(bonus));
    ui -> twotwo -> setText(text_qstr);
    ui -> totaltwo -> setText(all_qstr);
    ui -> bonustwo -> setText(bonus_qstr);
    ui -> twotwobutton -> setVisible(false);
    set_next_turn();
}


void MainWindow::on_threetwobutton_clicked()
{
    int score, all, bonus;

    score = usr2.sum_digit(3, turn, usr1, usr2);
    all = usr2.all;
    bonus = usr2.bonus;
    usr2.blank_flag[2] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    QString bonus_qstr = QString::fromStdString(to_string(bonus));
    ui -> threetwo -> setText(text_qstr);
    ui -> totaltwo -> setText(all_qstr);
    ui -> bonustwo -> setText(bonus_qstr);
    set_next_turn();
    ui -> threetwobutton -> setVisible(false);
}


void MainWindow::on_fourtwobutton_clicked()
{
    int score, all, bonus;

    score = usr2.sum_digit(4, turn, usr1, usr2);
    all = usr2.all;
    bonus = usr2.bonus;
    usr2.blank_flag[3] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    QString bonus_qstr = QString::fromStdString(to_string(bonus));
    ui -> fourtwo -> setText(text_qstr);
    ui -> totaltwo -> setText(all_qstr);
    ui -> bonustwo -> setText(bonus_qstr);
    set_next_turn();
    ui -> fourtwobutton -> setVisible(false);
}


void MainWindow::on_fivetwobutton_clicked()
{
    int score, all, bonus;

    score = usr2.sum_digit(5, turn, usr1, usr2);
    all = usr2.all;
    bonus = usr2.bonus;
    usr2.blank_flag[4] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    QString bonus_qstr = QString::fromStdString(to_string(bonus));
    ui -> fivetwo -> setText(text_qstr);
    ui -> totaltwo -> setText(all_qstr);
    ui -> bonustwo -> setText(bonus_qstr);
    set_next_turn();
    ui -> fivetwobutton -> setVisible(false);
}


void MainWindow::on_sixtwobutton_clicked()
{
    int score, all, bonus;

    score = usr2.sum_digit(6, turn, usr1, usr2);
    all = usr2.all;
    bonus = usr2.bonus;
    usr2.blank_flag[5] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    QString bonus_qstr = QString::fromStdString(to_string(bonus));
    ui -> sixtwo -> setText(text_qstr);
    ui -> totaltwo -> setText(all_qstr);
    ui -> bonustwo -> setText(bonus_qstr);
    set_next_turn();
    ui -> sixtwobutton -> setVisible(false);
}


void MainWindow::on_choicetwobutton_clicked()
{
    ui -> choicetwobutton -> setVisible(false);
}


void MainWindow::on_fkindtwobutton_clicked()
{
    ui -> fkindtwobutton -> setVisible(false);
}


void MainWindow::on_fullhousetwobutton_clicked()
{
    ui -> fullhousetwobutton -> setVisible(false);
}


void MainWindow::on_sstraighttwobutton_clicked()
{
    ui -> sstraighttwobutton -> setVisible(false);
}


void MainWindow::on_lstraighttwobutton_clicked()
{
    ui -> lstraighttwobutton -> setVisible(false);
}


void MainWindow::on_yahtzeetwobutton_clicked()
{
    ui -> yahtzeetwobutton -> setVisible(false);
}

void MainWindow::init_dice()
{
    int dice[6];

    for (int i=0; i < 5; i++)
        dice[i] = dice_gen();

    QPixmap pix_one(":/dice/images/one.png");
    QPixmap pix_two(":/dice/images/two.png");
    QPixmap pix_three(":/dice/images/three.png");
    QPixmap pix_four(":/dice/images/four.png");
    QPixmap pix_five(":/dice/images/five.png");
    QPixmap pix_six(":/dice/images/six.png");
    if (dice[0] == 1)
        ui -> diceone -> setPixmap(pix_one.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[0] == 2)
        ui -> diceone -> setPixmap(pix_two.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[0] == 3)
        ui -> diceone -> setPixmap(pix_three.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[0] == 4)
        ui -> diceone -> setPixmap(pix_four.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[0] == 5)
        ui -> diceone -> setPixmap(pix_five.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[0] == 6)
        ui -> diceone -> setPixmap(pix_six.scaled(50, 50, Qt::KeepAspectRatio));
    if (dice[1] == 1)
        ui -> dicetwo -> setPixmap(pix_one.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[1] == 2)
        ui -> dicetwo -> setPixmap(pix_two.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[1] == 3)
        ui -> dicetwo -> setPixmap(pix_three.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[1] == 4)
        ui -> dicetwo -> setPixmap(pix_four.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[1] == 5)
        ui -> dicetwo -> setPixmap(pix_five.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[1] == 6)
        ui -> dicetwo -> setPixmap(pix_six.scaled(50, 50, Qt::KeepAspectRatio));

    if (dice[2] == 1)
        ui -> dicethree -> setPixmap(pix_one.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[2] == 2)
        ui -> dicethree -> setPixmap(pix_two.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[2] == 3)
        ui -> dicethree -> setPixmap(pix_three.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[2] == 4)
        ui -> dicethree -> setPixmap(pix_four.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[2] == 5)
        ui -> dicethree -> setPixmap(pix_five.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[2] == 6)
        ui -> dicethree -> setPixmap(pix_six.scaled(50, 50, Qt::KeepAspectRatio));

    if (dice[3] == 1)
        ui -> dicefour -> setPixmap(pix_one.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[3] == 2)
        ui -> dicefour -> setPixmap(pix_two.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[3] == 3)
        ui -> dicefour -> setPixmap(pix_three.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[3] == 4)
        ui -> dicefour -> setPixmap(pix_four.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[3] == 5)
        ui -> dicefour -> setPixmap(pix_five.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[3] == 6)
        ui -> dicefour -> setPixmap(pix_six.scaled(50, 50, Qt::KeepAspectRatio));

    if (dice[4] == 1)
        ui -> dicefive -> setPixmap(pix_one.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[4] == 2)
        ui -> dicefive -> setPixmap(pix_two.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[4] == 3)
        ui -> dicefive -> setPixmap(pix_three.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[4] == 4)
        ui -> dicefive -> setPixmap(pix_four.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[4] == 5)
        ui -> dicefive -> setPixmap(pix_five.scaled(50, 50, Qt::KeepAspectRatio));
    else if (dice[4] == 6)
        ui -> dicefive -> setPixmap(pix_six.scaled(50, 50, Qt::KeepAspectRatio));
    for (int i=0; i<5; i++)
    {
        if (turn % 2 == 1)
            usr1.current_dice[i] = dice[i];
        else
            usr2.current_dice[i] = dice[i];
    }
}

void MainWindow::refresh_dice()
{
    int i, dice[5];

    if (turn % 2 == 1)
    {
        for (i=0; i < 5; i++)
        {
            if (usr1.check_keep[i] != "1")
                dice[i] = dice_gen();
            else
                dice[i] = usr1.current_dice[i];
        }
    }
    else
    {
        for (i=0; i < 5; i++)
        {
            if (usr2.check_keep[i] != "1")
                dice[i] = dice_gen();
            else
                dice[i] = usr2.current_dice[i];
        }
    }

    QPixmap pix_one(":/dice/images/one.png");
    QPixmap pix_two(":/dice/images/two.png");
    QPixmap pix_three(":/dice/images/three.png");
    QPixmap pix_four(":/dice/images/four.png");
    QPixmap pix_five(":/dice/images/five.png");
    QPixmap pix_six(":/dice/images/six.png");

    i = -1;
    while (dice[++i])
    {
        if (dice[i] == 0)
            continue;
        else
        {
            switch(i)
            {
            case 0:
                if (dice[0] == 1)
                    ui -> diceone -> setPixmap(pix_one.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[0] == 2)
                    ui -> diceone -> setPixmap(pix_two.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[0] == 3)
                    ui -> diceone -> setPixmap(pix_three.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[0] == 4)
                    ui -> diceone -> setPixmap(pix_four.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[0] == 5)
                    ui -> diceone -> setPixmap(pix_five.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[0] == 6)
                    ui -> diceone -> setPixmap(pix_six.scaled(50, 50, Qt::KeepAspectRatio));
                break;
            case 1:
                if (dice[1] == 1)
                    ui -> dicetwo -> setPixmap(pix_one.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[1] == 2)
                    ui -> dicetwo -> setPixmap(pix_two.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[1] == 3)
                    ui -> dicetwo -> setPixmap(pix_three.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[1] == 4)
                    ui -> dicetwo -> setPixmap(pix_four.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[1] == 5)
                    ui -> dicetwo -> setPixmap(pix_five.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[1] == 6)
                    ui -> dicetwo -> setPixmap(pix_six.scaled(50, 50, Qt::KeepAspectRatio));
                break;
            case 2:
                if (dice[2] == 1)
                    ui -> dicethree -> setPixmap(pix_one.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[2] == 2)
                    ui -> dicethree -> setPixmap(pix_two.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[2] == 3)
                    ui -> dicethree -> setPixmap(pix_three.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[2] == 4)
                    ui -> dicethree -> setPixmap(pix_four.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[2] == 5)
                    ui -> dicethree -> setPixmap(pix_five.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[2] == 6)
                    ui -> dicethree -> setPixmap(pix_six.scaled(50, 50, Qt::KeepAspectRatio));
                break;
            case 3:
                if (dice[3] == 1)
                    ui -> dicefour -> setPixmap(pix_one.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[3] == 2)
                    ui -> dicefour -> setPixmap(pix_two.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[3] == 3)
                    ui -> dicefour -> setPixmap(pix_three.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[3] == 4)
                    ui -> dicefour -> setPixmap(pix_four.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[3] == 5)
                    ui -> dicefour -> setPixmap(pix_five.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[3] == 6)
                    ui -> dicefour -> setPixmap(pix_six.scaled(50, 50, Qt::KeepAspectRatio));
                break;
            case 4:
                if (dice[4] == 1)
                    ui -> dicefive -> setPixmap(pix_one.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[4] == 2)
                    ui -> dicefive -> setPixmap(pix_two.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[4] == 3)
                    ui -> dicefive -> setPixmap(pix_three.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[4] == 4)
                    ui -> dicefive -> setPixmap(pix_four.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[4] == 5)
                    ui -> dicefive -> setPixmap(pix_five.scaled(50, 50, Qt::KeepAspectRatio));
                else if (dice[4] == 6)
                    ui -> dicefive -> setPixmap(pix_six.scaled(50, 50, Qt::KeepAspectRatio));
                break;
            }
        }
    }
    for (i=0; i<5; i++)
    {
        if (turn % 2 == 1)
            usr1.current_dice[i] = dice[i];
        else
            usr2.current_dice[i] = dice[i];
    }
}

void MainWindow::on_reroll_clicked()
{
    if (current_turn > 0)
    {
        string temp;
        refresh_dice();
        current_turn--;
        temp = to_string(current_turn) + " left";
        QString lefttime_qstr = QString::fromStdString(temp);
        ui -> lefttime -> setText(lefttime_qstr);
    }
}

void MainWindow::refresh_keep()
{
    ui -> keep1 -> setText("");
    ui -> keep1b -> setVisible(true);
    ui -> keep2 -> setText("");
    ui -> keep2b -> setVisible(true);
    ui -> keep3 -> setText("");
    ui -> keep3b -> setVisible(true);
    ui -> keep4 -> setText("");
    ui -> keep4b -> setVisible(true);
    ui -> keep5 -> setText("");
    ui -> keep5b -> setVisible(true);
}

void MainWindow::refresh_player_button()
{
    if (turn % 2 == 1)
    {
        ui -> onetwobutton -> setVisible(false);
        ui -> twotwobutton -> setVisible(false);
        ui -> threetwobutton -> setVisible(false);
        ui -> fourtwobutton -> setVisible(false);
        ui -> fivetwobutton -> setVisible(false);
        ui -> sixtwobutton -> setVisible(false);
        ui -> choicetwobutton -> setVisible(false);
        ui -> fkindtwobutton -> setVisible(false);
        ui -> fullhousetwobutton -> setVisible(false);
        ui -> sstraighttwobutton -> setVisible(false);
        ui -> lstraighttwobutton -> setVisible(false);
        ui -> yahtzeetwobutton -> setVisible(false);

        if (usr1.blank_flag[0] != 1)
            ui -> oneonebutton -> setVisible(true);
        if (usr1.blank_flag[1] != 1)
            ui -> twoonebutton -> setVisible(true);
        if (usr1.blank_flag[2] != 1)
            ui -> threeonebutton -> setVisible(true);
        if (usr1.blank_flag[3] != 1)
            ui -> fouronebutton -> setVisible(true);
        if (usr1.blank_flag[4] != 1)
            ui -> fiveonebutton -> setVisible(true);
        if (usr1.blank_flag[5] != 1)
            ui -> sixonebutton -> setVisible(true);
        if (usr1.blank_flag[6] != 1)
            ui -> choiceonebutton -> setVisible(true);
        if (usr1.blank_flag[7] != 1)
            ui -> fkindonebutton -> setVisible(true);
        if (usr1.blank_flag[8] != 1)
            ui -> fullhouseonebutton -> setVisible(true);
        if (usr1.blank_flag[9] != 1)
            ui -> sstraightonebutton -> setVisible(true);
        if (usr1.blank_flag[10] != 1)
            ui -> lstraightonebutton -> setVisible(true);
        if (usr1.blank_flag[11] != 1)
            ui -> yahtzeeonebutton -> setVisible(true);
    }
    else
    {
        ui -> oneonebutton -> setVisible(false);
        ui -> twoonebutton -> setVisible(false);
        ui -> threeonebutton -> setVisible(false);
        ui -> fouronebutton -> setVisible(false);
        ui -> fiveonebutton -> setVisible(false);
        ui -> sixonebutton -> setVisible(false);
        ui -> choiceonebutton -> setVisible(false);
        ui -> fkindonebutton -> setVisible(false);
        ui -> fullhouseonebutton -> setVisible(false);
        ui -> sstraightonebutton -> setVisible(false);
        ui -> lstraightonebutton -> setVisible(false);
        ui -> yahtzeeonebutton -> setVisible(false);

        if (usr2.blank_flag[0] != 1)
            ui -> onetwobutton -> setVisible(true);
        if (usr2.blank_flag[1] != 1)
            ui -> twotwobutton -> setVisible(true);
        if (usr2.blank_flag[2] != 1)
            ui -> threetwobutton -> setVisible(true);
        if (usr2.blank_flag[3] != 1)
            ui -> fourtwobutton -> setVisible(true);
        if (usr2.blank_flag[4] != 1)
            ui -> fivetwobutton -> setVisible(true);
        if (usr2.blank_flag[5] != 1)
            ui -> sixtwobutton -> setVisible(true);
        if (usr2.blank_flag[6] != 1)
            ui -> choicetwobutton -> setVisible(true);
        if (usr2.blank_flag[7] != 1)
            ui -> fkindtwobutton -> setVisible(true);
        if (usr2.blank_flag[8] != 1)
            ui -> fullhousetwobutton -> setVisible(true);
        if (usr2.blank_flag[9] != 1)
            ui -> sstraighttwobutton -> setVisible(true);
        if (usr2.blank_flag[10] != 1)
            ui -> lstraighttwobutton -> setVisible(true);
        if (usr2.blank_flag[11] != 1)
            ui -> yahtzeetwobutton -> setVisible(true);
    }
}

void MainWindow::on_keep1b_clicked()
{
    ui -> keep1 -> setText("keep");
    ui -> keep1b -> setVisible(false);
    if (turn % 2 == 1)
    {
        usr1.check_keep[0] = "1";
    }
    else
    {
        usr2.check_keep[0] = "1";
    }
}


void MainWindow::on_keep2b_clicked()
{
    ui -> keep2 -> setText("keep");
    ui -> keep2b -> setVisible(false);
    if (turn % 2 == 1)
    {
        usr1.check_keep[1] = "1";
    }
    else
    {
        usr2.check_keep[1] = "1";
    }
}


void MainWindow::on_keep3b_clicked()
{
    ui -> keep3 -> setText("keep");
    ui -> keep3b -> setVisible(false);
    if (turn % 2 == 1)
    {
        usr1.check_keep[2] = "1";
    }
    else
    {
        usr2.check_keep[2] = "1";
    }
}


void MainWindow::on_keep4b_clicked()
{
    ui -> keep4 -> setText("keep");
    ui -> keep4b -> setVisible(false);
    if (turn % 2 == 1)
    {
        usr1.check_keep[3] = "1";
    }
    else
    {
        usr2.check_keep[3] = "1";
    }
}


void MainWindow::on_keep5b_clicked()
{
    ui -> keep5 -> setText("keep");
    ui -> keep5b -> setVisible(false);
    if (turn % 2 == 1)
    {
        usr1.check_keep[4] = "1";
    }
    else
    {
        usr2.check_keep[4] = "1";
    }
}


void MainWindow::on_howtobutton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/kimch0612/OOP2_Project/blob/master/manual.md", QUrl::TolerantMode));
}


void MainWindow::on_bonusonebutton_clicked()
{

}


void MainWindow::on_pushButton_clicked()
{

}

