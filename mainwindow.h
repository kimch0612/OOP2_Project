#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_startbutton_clicked();
    void on_exitbutton_clicked();
    void on_creditsbutton_clicked();
    void on_oneonebutton_clicked();
    void on_backbutton_clicked();
    void on_bonusonebutton_clicked();
    void on_twoonebutton_clicked();
    void on_threeonebutton_clicked();
    void on_fouronebutton_clicked();
    void on_fiveonebutton_clicked();
    void on_sixonebutton_clicked();
    void on_choiceonebutton_clicked();
    void on_fkindonebutton_clicked();
    void on_fullhouseonebutton_clicked();
    void on_sstraightonebutton_clicked();
    void on_lstraightonebutton_clicked();
    void on_yahtzeeonebutton_clicked();
    void on_onetwobutton_clicked();
    void on_twotwobutton_clicked();
    void on_threetwobutton_clicked();
    void on_fourtwobutton_clicked();
    void on_fivetwobutton_clicked();
    void on_sixtwobutton_clicked();
    void on_choicetwobutton_clicked();
    void on_fkindtwobutton_clicked();
    void on_fullhousetwobutton_clicked();
    void on_sstraighttwobutton_clicked();
    void on_lstraighttwobutton_clicked();
    void on_yahtzeetwobutton_clicked();
    void init_dice();
    void refresh_dice();
    void set_next_turn();
    void refresh_keep();
    void refresh_player_button();

    void on_reroll_clicked();

    void on_pushButton_clicked();

    void on_keep1b_clicked();

    void on_keep2b_clicked();

    void on_keep3b_clicked();

    void on_keep4b_clicked();

    void on_keep5b_clicked();

    void on_howtobutton_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
