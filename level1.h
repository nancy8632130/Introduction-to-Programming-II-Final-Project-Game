#ifndef LEVEL1_H
#define LEVEL1_H
#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QMouseEvent>
#include <role.h>
#include <prize.h>
#include "music.h"
#include <level2.h>
#include <movie.h>
namespace Ui {
class level1;
}
class level1 : public QWidget
{
    Q_OBJECT

public:
    void win();
    explicit level1(QWidget *parent = 0);
    ~level1();
    void renew();
    Music *bgm;
    Music *coinmus[3];
    QTimer *cointimer;
    QTimer *ttimer;
private:
    int iswin;
    Ui::level1 *ui;
    ROLE *man;
    prize *coin[20];
    int temp;
    int cointmp;
    int score;
    int secleft,minleft;
    level2 le2;
    movie *m;
private slots:
    void getcoin();
    void time();
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);	//鍵盤事件
};

#endif // LEVEL1_H
