#ifndef LEVEL5_H
#define LEVEL5_H
#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QMouseEvent>
#include <role.h>
#include <prize.h>
#include <movie.h>
#include "music.h"
namespace Ui {
class level5;
}
class level5 : public QWidget
{
    Q_OBJECT

public:
    void win();
    explicit level5(QWidget *parent = 0);
    ~level5();
    void renew();
    Music *bgm;
    Music *coinmus[3];
    QTimer *cointimer;
    QTimer *ttimer;
private:
    int iswin;
    Ui::level5 *ui;
    ROLE *man;
    prize *coin[20];
    int temp;
    int cointmp;
    int score;
    int secleft,minleft;
    movie *m;
private slots:
    void getcoin();
    void time();
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *event);	//鍵盤事件
};

#endif // LEVEL5_H
