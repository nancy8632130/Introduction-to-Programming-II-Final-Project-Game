#ifndef LEVEL3_H
#define LEVEL3_H
#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QMouseEvent>
#include <role.h>
#include <prize.h>
#include "music.h"
#include <level4.h>
#include <movie.h>
namespace Ui {
class level3;
}
class level3 : public QWidget
{
    Q_OBJECT

public:
    void win();
    explicit level3(QWidget *parent = 0);
    ~level3();
    void renew();
    Music *bgm;
    Music *coinmus[3];
    QTimer *cointimer;
    QTimer *ttimer;
private:
    int iswin;
    Ui::level3 *ui;
    ROLE *man;
    prize *coin[20];
    int temp;
    int cointmp;
    int score;
    int secleft,minleft;
    level4 le4;
    movie *m;
private slots:
    void getcoin();
    void time();
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);	//鍵盤事件
};

#endif // LEVEL3_H
