#ifndef LEVEL2_H
#define LEVEL2_H
#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QMouseEvent>
#include <role.h>
#include <prize.h>
#include "music.h"
#include <level3.h>
#include <movie.h>
namespace Ui {
class level2;
}
class level2 : public QWidget
{
    Q_OBJECT

public:
    void win();
    explicit level2(QWidget *parent = 0);
    ~level2();
    void renew();
    Music *bgm;
    Music *coinmus[3];
    QTimer *cointimer;
    QTimer *ttimer;
private:
    int iswin;
    Ui::level2 *ui;
    ROLE *man;
    prize *coin[20];
    int temp;
    int cointmp;
    int score;
    int secleft,minleft;
    level3 le3;
    movie *m;
private slots:
    void getcoin();
    void time();
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);	//鍵盤事件
};

#endif // LEVEL2_H
