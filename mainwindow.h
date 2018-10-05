#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <level1.h>
#include <level2.h>
#include <level3.h>
#include <level4.h>
#include <level5.h>
#include <info.h>
#include <prize.h>
#include <QMainWindow>
#include "music.h"
#include<QMediaPlaylist>
#include<QMediaPlayer>
#include<QVideoWidget>
#include<QFileDialog>
#include<QProgressBar>
#include<QSlider>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Music *bgm;
    QTimer *movietimer;
private slots:
    void on_pushButton_1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_start_clicked();

    void on_pushButton_info_clicked();
private slots:
    void movieplay();

private:
    int movietime;
    QMediaPlaylist *playList;
    QMediaPlayer * player;
    QVideoWidget * vw;
    Ui::MainWindow *ui;
    level1 le1;
    level2 le2;
    level3 le3;
    level4 le4;
    level5 le5;
    info about;
    int temp;
protected:
    void keyPressEvent(QKeyEvent *event);
};

#endif // MAINWINDOW_H
