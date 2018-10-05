#ifndef LEVEL4_H
#define LEVEL4_H
#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QMouseEvent>
#include <role.h>
#include <prize.h>
#include "music.h"
#include <level5.h>
#include <movie.h>
namespace Ui {
class level4;
}
class level4 : public QWidget
{
    Q_OBJECT

public:
    void win();
    explicit level4(QWidget *parent = 0);
    ~level4();
    void renew();
    Music *bgm;
    Music *coinmus[3];
    QTimer *cointimer;
    QTimer *ttimer;
private:
    int iswin;
    Ui::level4 *ui;
    ROLE *man;
    prize *coin[20];
    int temp;
    int cointmp;
    int score;
    int secleft,minleft;
    level5 le5;
    movie *m;
private slots:
    void getcoin();
    void time();
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);	//鍵盤事件
};

#endif // LEVEL4_H
