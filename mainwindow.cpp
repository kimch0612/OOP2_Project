#include "functions.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

int turn=1, current_turn=3, timer=29, cheat=0;
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
    QList<QWidget*> widgetsToHide = {
        ui->oneonebutton, ui->twoonebutton, ui->threeonebutton, ui->fouronebutton, ui->fiveonebutton, ui->sixonebutton,
        ui->choiceonebutton, ui->fkindonebutton, ui->fullhouseonebutton, ui->sstraightonebutton, ui->lstraightonebutton, ui->yahtzeeonebutton,
        ui->totalone, ui->onetwobutton, ui->twotwobutton, ui->threetwobutton, ui->fourtwobutton, ui->fivetwobutton, ui->sixtwobutton,
        ui->choicetwobutton, ui->fkindtwobutton, ui->fullhousetwobutton, ui->sstraighttwobutton, ui->lstraighttwobutton, ui->yahtzeetwobutton,
        ui->totaltwo, ui->backbutton, ui->reroll, ui->keep1, ui->keep2, ui->keep3, ui->keep4, ui->keep5,
        ui->keep1b, ui->keep2b, ui->keep3b, ui->keep4b, ui->keep5b, ui->creditone, ui->backbutton, ui->bonusone, ui->bonustwo,
        ui->bonusonebutton, ui->pushButton, ui->backbutton, ui->restart, ui->pushButton_2
    };
    for (QWidget* widget : widgetsToHide) {
        widget->setVisible(false);
    }
    ui -> creditone -> setText("<a href=\"https://www.pngwing.com/en/free-png-sptdk/\">Program Title icon</a>");
    ui -> creditone -> setTextFormat(Qt::RichText);
    ui -> creditone -> setTextInteractionFlags(Qt::TextBrowserInteraction);
    ui -> creditone -> setOpenExternalLinks(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startbutton_clicked()
{
    QList<QWidget*> widgetsToHide = {ui->gamestart, ui->startbutton, ui->howtobutton, ui->creditsbutton, ui->exitbutton, ui->backbutton};
    for (QWidget* widget : widgetsToHide) {
        widget->setVisible(false);
    }
    QList<QWidget*> widgetsToShow = {
        ui->oneonebutton, ui->twoonebutton, ui->threeonebutton, ui->fouronebutton, ui->fiveonebutton, ui->sixonebutton,
        ui->choiceonebutton, ui->fkindonebutton, ui->fullhouseonebutton, ui->sstraightonebutton, ui->lstraightonebutton, ui->yahtzeeonebutton,
        ui->totalone, ui->totaltwo, ui->reroll, ui->keep1, ui->keep2, ui->keep3, ui->keep4, ui->keep5,
        ui->keep1b, ui->keep2b, ui->keep3b, ui->keep4b, ui->keep5b, ui->bonusone, ui->bonustwo
    };
    for (QWidget* widget : widgetsToShow) {
        widget->setVisible(true);
    }

    if (turn % 2 == 1)
        ui->playingplayer->setText("Player 1 is in control...");
    else if (turn % 2 == 0)
        ui->playingplayer->setText("Player 2 is in control...");

    init_dice();
    ui -> lefttime -> setText("3 left");
    ui -> category -> setText("← Choose category");
    Calc_Current_Score();
    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(timeout()));
    Timer->start(30000);
    Timer_label = new QTimer(this);
    connect(Timer_label, SIGNAL(timeout()), this, SLOT(timer_update()));
    Timer_label->start(1000);
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

    if (++turn <= 24)
    {
        if (turn % 2 == 1)
        {
            ui->playingplayer->setText("Player 1 is in control...");
            for (int i=0; i<5; i++)
            {
                usr1.check_keep[i] = "0";
                usr1.current_dice[i] = 0;
            }
            if (usr2.digits == 6 || usr2.bonus >= 63)
            {
                if (usr2.bonus >= 63)
                {
                    ui -> bonustwo -> setText("✓");
                    usr2.all += 35;
                    QString all_qstr = QString::fromStdString(to_string(usr2.all));
                    ui -> totaltwo -> setText(all_qstr);
                    usr2.digits = 0;
                }
                else
                {
                    ui -> bonustwo -> setText("X");
                    usr2.digits = 0;
                }
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
            if (usr1.digits == 6 || usr1.bonus >= 63)
            {
                if (usr1.bonus >= 63)
                {
                    usr1.all += 35;
                    ui -> bonusone -> setText("✓");
                    QString all_qstr = QString::fromStdString(to_string(usr1.all));
                    ui -> totalone -> setText(all_qstr);
                    usr1.digits = 0;
                }
                else
                {
                    ui -> bonusone -> setText("X");
                    usr1.digits = 0;
                }
            }
        }
        current_turn = 3;
        temp = to_string(current_turn) + " left";
        QString lefttime_qstr = QString::fromStdString(temp);
        ui -> lefttime -> setText(lefttime_qstr);
        init_dice();
        refresh_keep();
        refresh_player_button();
        Calc_Current_Score();
        timer = 29;
        Timer->stop();
        Timer_label->stop();
        Timer->start(30000);
        Timer_label->start(1000);
    } else {
        Final_Score();
    }
}

void MainWindow::on_oneonebutton_clicked()
{
    int score, all, bonus;

    score = usr1.sum_digit(1, usr1, usr2);
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

    score = usr1.sum_digit(2, usr1, usr2);
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

    score = usr1.sum_digit(3, usr1, usr2);
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

    score = usr1.sum_digit(4, usr1, usr2);
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

    score = usr1.sum_digit(5, usr1, usr2);
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

    score = usr1.sum_digit(6, usr1, usr2);
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
    int score, all, bonus;

    score = usr1.sum_digit(8, usr1, usr2);
    all = usr1.all;
    usr1.blank_flag[6] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    ui -> choiceone -> setText(text_qstr);
    ui -> totalone -> setText(all_qstr);
    set_next_turn();
    ui -> choiceonebutton -> setVisible(false);
}


void MainWindow::on_fkindonebutton_clicked()
{
    int score, all, bonus;

    score = usr1.sum_digit(9, usr1, usr2);
    all = usr1.all;
    usr1.blank_flag[7] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    ui -> fkindone -> setText(text_qstr);
    ui -> totalone -> setText(all_qstr);
    set_next_turn();
    ui -> fkindonebutton -> setVisible(false);
}


void MainWindow::on_fullhouseonebutton_clicked()
{
    int score, all, bonus;

    score = usr1.sum_digit(10, usr1, usr2);
    all = usr1.all;
    usr1.blank_flag[8] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    ui -> fullhouseone -> setText(text_qstr);
    ui -> totalone -> setText(all_qstr);
    set_next_turn();
    ui -> fullhouseonebutton -> setVisible(false);
}


void MainWindow::on_sstraightonebutton_clicked()
{
    int score, all, bonus;

    score = usr1.sum_digit(11, usr1, usr2);
    all = usr1.all;
    usr1.blank_flag[9] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    ui -> sstraightone -> setText(text_qstr);
    ui -> totalone -> setText(all_qstr);
    set_next_turn();
    ui -> sstraightonebutton -> setVisible(false);
}


void MainWindow::on_lstraightonebutton_clicked()
{
    int score, all, bonus;

    score = usr1.sum_digit(12, usr1, usr2);
    all = usr1.all;
    usr1.blank_flag[10] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    ui -> lstraightone -> setText(text_qstr);
    ui -> totalone -> setText(all_qstr);
    set_next_turn();
    ui -> lstraightonebutton -> setVisible(false);
}


void MainWindow::on_yahtzeeonebutton_clicked()
{
    int score, all, bonus;

    score = usr1.sum_digit(13, usr1, usr2);
    all = usr1.all;
    usr1.blank_flag[11] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    ui -> yahtzeeone -> setText(text_qstr);
    ui -> totalone -> setText(all_qstr);
    set_next_turn();
    ui -> yahtzeeonebutton -> setVisible(false);
}


void MainWindow::on_onetwobutton_clicked()
{
    int score, all, bonus;

    score = usr2.sum_digit(1, usr1, usr2);
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

    score = usr2.sum_digit(2, usr1, usr2);
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

    score = usr2.sum_digit(3, usr1, usr2);
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

    score = usr2.sum_digit(4, usr1, usr2);
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

    score = usr2.sum_digit(5, usr1, usr2);
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

    score = usr2.sum_digit(6, usr1, usr2);
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
    int score, all, bonus;

    score = usr2.sum_digit(8, usr1, usr2);
    all = usr2.all;
    usr2.blank_flag[6] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    ui -> choicetwo -> setText(text_qstr);
    ui -> totaltwo -> setText(all_qstr);
    set_next_turn();
    ui -> choicetwobutton -> setVisible(false);
}


void MainWindow::on_fkindtwobutton_clicked()
{
    int score, all, bonus;

    score = usr2.sum_digit(9, usr1, usr2);
    all = usr2.all;
    usr2.blank_flag[7] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    ui -> fkindtwo -> setText(text_qstr);
    ui -> totaltwo -> setText(all_qstr);
    set_next_turn();
    ui -> fkindtwobutton -> setVisible(false);
}


void MainWindow::on_fullhousetwobutton_clicked()
{
    int score, all, bonus;

    score = usr2.sum_digit(10, usr1, usr2);
    all = usr2.all;
    usr2.blank_flag[8] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    ui -> fullhousetwo -> setText(text_qstr);
    ui -> totaltwo -> setText(all_qstr);
    set_next_turn();
    ui -> fullhousetwobutton -> setVisible(false);
}


void MainWindow::on_sstraighttwobutton_clicked()
{
    int score, all, bonus;

    score = usr2.sum_digit(11, usr1, usr2);
    all = usr2.all;
    usr2.blank_flag[9] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    ui -> sstraighttwo -> setText(text_qstr);
    ui -> totaltwo -> setText(all_qstr);
    set_next_turn();
    ui -> sstraighttwobutton -> setVisible(false);
}


void MainWindow::on_lstraighttwobutton_clicked()
{
    int score, all, bonus;

    score = usr2.sum_digit(12, usr1, usr2);
    all = usr2.all;
    usr2.blank_flag[10] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    ui -> lstraighttwo -> setText(text_qstr);
    ui -> totaltwo -> setText(all_qstr);
    set_next_turn();
    ui -> lstraighttwobutton -> setVisible(false);
}


void MainWindow::on_yahtzeetwobutton_clicked()
{
    int score, all, bonus;

    score = usr2.sum_digit(13, usr1, usr2);
    all = usr2.all;
    usr2.blank_flag[11] = 1;

    QString text_qstr = QString::fromStdString(to_string(score));
    QString all_qstr = QString::fromStdString(to_string(all));
    ui -> yahtzeetwo -> setText(text_qstr);
    ui -> totaltwo -> setText(all_qstr);
    set_next_turn();
    ui -> yahtzeetwobutton -> setVisible(false);
}

void MainWindow::init_dice()
{
    QPixmap dice_images[6];
    dice_images[0].load(":/dice/images/one.png");
    dice_images[1].load(":/dice/images/two.png");
    dice_images[2].load(":/dice/images/three.png");
    dice_images[3].load(":/dice/images/four.png");
    dice_images[4].load(":/dice/images/five.png");
    dice_images[5].load(":/dice/images/six.png");
    int dice[5];

    for (int i = 0; i < 5; i++) {
        dice[i] = dice_gen();
        QLabel* diceLabel = nullptr;

        switch (i) {
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
            diceLabel->setPixmap(dice_images[dice[i] - 1].scaled(50, 50, Qt::KeepAspectRatio));

            if (turn % 2 == 1) {
                usr1.current_dice[i] = dice[i];
            } else {
                usr2.current_dice[i] = dice[i];
            }
        }
    }
}

void MainWindow::refresh_dice()
{
    QPixmap dice_images[6];
    dice_images[0].load(":/dice/images/one.png");
    dice_images[1].load(":/dice/images/two.png");
    dice_images[2].load(":/dice/images/three.png");
    dice_images[3].load(":/dice/images/four.png");
    dice_images[4].load(":/dice/images/five.png");
    dice_images[5].load(":/dice/images/six.png");
    int dice[5];
    user_score& currentUser = (turn % 2 == 1) ? usr1 : usr2;

    QLabel* diceLabels[5] = {
        ui->diceone,
        ui->dicetwo,
        ui->dicethree,
        ui->dicefour,
        ui->dicefive
    };

    for (int i = 0; i < 5; i++)
    {
        if (currentUser.check_keep[i] != "1")
            dice[i] = dice_gen();
        else
            dice[i] = currentUser.current_dice[i];

        int diceValue = dice[i];
        if (diceValue >= 1 && diceValue <= 6)
            diceLabels[i]->setPixmap(dice_images[diceValue - 1].scaled(50, 50, Qt::KeepAspectRatio));
    }
    for (int i = 0; i < 5; i++)
        currentUser.current_dice[i] = dice[i];
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
        Calc_Current_Score();
    }
}

void MainWindow::Calc_Current_Score()
{
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
    if (turn%2==1)
    {
        for (int i=0; i<12; i++)
        {
            QString tmp_qstr = QString::fromStdString(to_string(usr1.calc_current_score(i, usr1, usr2)));
            usr1_buttons[i]->setText(tmp_qstr);
        }
    }
    else
    {
        for (int i=0; i<12; i++)
        {
            QString tmp_qstr = QString::fromStdString(to_string(usr2.calc_current_score(i, usr1, usr2)));
            usr2_buttons[i]->setText(tmp_qstr);
        }
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
    if (turn % 2 == 1) {
        /*
        함수포인터를 이용해서 코드를 최적화함.
        https://github.com/kimch0612/OOP2_Project/commit/3aa930bcb2ee8e69e83b7ac70dc1077a4f46ce75
        */
        for (QPushButton* button : usr2_buttons)
            button->setVisible(false);
        for (int i = 0; i < 12; i++) {
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

void MainWindow::on_keep1b_clicked()
{
    /*
    삼항연산자를 이용해서 코드를 최적화함.
    https://github.com/kimch0612/OOP2_Project/commit/504bcc9730df1c0c0766fda9070860a7a0c94cf2
    */
    string& CheckKeep = (turn % 2 == 1) ? usr1.check_keep[0] : usr2.check_keep[0];

    if (CheckKeep == "0") {
        ui->keep1->setText("hold");
        CheckKeep = "1";
    } else {
        ui->keep1->setText("");
        CheckKeep = "0";
    }
}

void MainWindow::on_keep2b_clicked()
{
    string& CheckKeep = (turn % 2 == 1) ? usr1.check_keep[1] : usr2.check_keep[1];

    if (CheckKeep == "0") {
        ui->keep2->setText("hold");
        CheckKeep = "1";
    } else {
        ui->keep2->setText("");
        CheckKeep = "0";
    }
}


void MainWindow::on_keep3b_clicked()
{
    string& CheckKeep = (turn % 2 == 1) ? usr1.check_keep[2] : usr2.check_keep[2];

    if (CheckKeep == "0") {
        ui->keep3->setText("hold");
        CheckKeep = "1";
    } else {
        ui->keep3->setText("");
        CheckKeep = "0";
    }
}


void MainWindow::on_keep4b_clicked()
{
    string& CheckKeep = (turn % 2 == 1) ? usr1.check_keep[3] : usr2.check_keep[3];

    if (CheckKeep == "0") {
        ui->keep4->setText("hold");
        CheckKeep = "1";
    } else {
        ui->keep4->setText("");
        CheckKeep = "0";
    }
}


void MainWindow::on_keep5b_clicked()
{
    string& CheckKeep = (turn % 2 == 1) ? usr1.check_keep[4] : usr2.check_keep[4];

    if (CheckKeep == "0") {
        ui->keep5->setText("hold");
        CheckKeep = "1";
    } else {
        ui->keep5->setText("");
        CheckKeep = "0";
    }
}


void MainWindow::on_howtobutton_clicked()
{
    QDesktopServices::openUrl(QUrl("https://github.com/kimch0612/OOP2_Project/blob/master/documents/manual.md", QUrl::TolerantMode));
    if (++cheat==3) ui->pushButton_2->setVisible(true);
}

void MainWindow::Final_Score()
{
    QList<QWidget*> widgetsToHide = {
        ui->category, ui->playingplayer, ui->diceone,
        ui->dicetwo, ui->dicethree, ui->dicefour,
        ui->dicefive, ui->keep1b, ui->keep2b,
        ui->keep3b, ui->keep4b, ui->keep5b,
        ui->reroll, ui->lefttime, ui->keep1,
        ui->keep2, ui->keep3, ui->keep4,
        ui->keep5
    };
    for (QWidget* widget : widgetsToHide) {
        widget->setVisible(false);
    }
    ui->gamestart->setVisible(true);
    ui->gamestart->setText("Game Set!");
    if (calc_score(usr1, usr2) == 0)
        ui->gameset->setText("User 1 Win!");
    else if (calc_score(usr1, usr2) == 1)
        ui->gameset->setText("User 2 Win!");
    else
        ui->gameset->setText("Draw");
    ui->restart->setVisible(true);
    ui->exitbutton->setVisible(true);
}


void MainWindow::on_bonusonebutton_clicked(){}


void MainWindow::on_pushButton_clicked(){}


void MainWindow::on_pushButton_2_clicked(){ refresh_dice(); Calc_Current_Score(); }


void MainWindow::restart_game()
{

}

void MainWindow:: timer_update()
{
    timer--;
    string temp = "⏳" + to_string(timer) + "sec";
    QString lefttimer = QString::fromStdString(temp);
    ui->timer_label->setText(lefttimer);
}

void MainWindow:: timeout()
{
    current_turn = 0;
    string temp = "timeout!";
    QString lefttime_qstr = QString::fromStdString(temp);
    ui -> lefttime -> setText(lefttime_qstr);
    Timer_label->stop();
}
