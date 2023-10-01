#include "functions.h"
#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setWindowIcon(QIcon("C:/Users/Chals/Documents/OOP2_Project/Yahtzee/icon.png"));
    setStyleSheet("background-color:blck");
    QMainWindow::setWindowFlags( Qt::WindowTitleHint |  Qt::WindowMinimizeButtonHint | Qt::WindowCloseButtonHint );
    ui->setupUi(this);
    ui -> oneonebutton -> setVisible(false);
    ui -> twoonebutton -> setVisible(false);
    ui -> threeonebutton -> setVisible(false);
    ui -> fouronebutton -> setVisible(false);
    ui -> fiveonebutton -> setVisible(false);
    ui -> sixonebutton -> setVisible(false);
    ui -> bonusonebutton -> setVisible(false);
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
    ui -> bonustwobutton -> setVisible(false);
    ui -> choicetwobutton -> setVisible(false);
    ui -> fkindtwobutton -> setVisible(false);
    ui -> fullhousetwobutton -> setVisible(false);
    ui -> sstraighttwobutton -> setVisible(false);
    ui -> lstraighttwobutton -> setVisible(false);
    ui -> yahtzeetwobutton -> setVisible(false);
    ui -> totaltwo -> setVisible(false);
    ui -> backbutton -> setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_startbutton_clicked()
{
    ui->gamestart->setVisible(false);
    ui->startbutton->setVisible(false);
    ui->howtobutton->setVisible(false);
    ui->creditsbutton->setVisible(false);
    ui->exitbutton->setVisible(false);
    ui->playingplayer->setText("Player 1 is in control...");
    ui -> oneonebutton -> setVisible(true);
    ui -> twoonebutton -> setVisible(true);
    ui -> threeonebutton -> setVisible(true);
    ui -> fouronebutton -> setVisible(true);
    ui -> fiveonebutton -> setVisible(true);
    ui -> sixonebutton -> setVisible(true);
    ui -> bonusonebutton -> setVisible(true);
    ui -> choiceonebutton -> setVisible(true);
    ui -> fkindonebutton -> setVisible(true);
    ui -> fullhouseonebutton -> setVisible(true);
    ui -> sstraightonebutton -> setVisible(true);
    ui -> lstraightonebutton -> setVisible(true);
    ui -> yahtzeeonebutton -> setVisible(true);
    ui -> totalone -> setVisible(true);
    ui -> totaltwo -> setVisible(true);
    ui -> lefttime -> setText("3 left");
}


void MainWindow::on_exitbutton_clicked()
{
    QCoreApplication::exit(0);
}


void MainWindow::on_creditsbutton_clicked()
{
    ui->gamestart->setVisible(false);
    ui->startbutton->setVisible(false);
    ui->howtobutton->setVisible(false);
    ui->creditsbutton->setVisible(false);
    ui->exitbutton->setVisible(false);
    ui->playingplayer->setText("이 프로그램에 사용한 Open Source / Copyleft Source");
    ui -> backbutton -> setVisible(true);
}


void MainWindow::on_oneonebutton_clicked()
{
    ui -> oneonebutton -> setVisible(false);
    ui -> oneone -> setText("0");
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
}

