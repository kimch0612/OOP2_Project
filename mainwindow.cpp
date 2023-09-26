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
    ui->playingplayer->setText("Player 1 is now Playing...");
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
}

