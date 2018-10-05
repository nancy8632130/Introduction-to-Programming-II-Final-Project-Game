#ifndef PRIZE_H
#define PRIZE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>

class prize:public QWidget
{
    Q_OBJECT
public:
    explicit prize(QWidget *parent = 0);
    ~prize();
    int hided;
protected:
    void paintEvent(QPaintEvent *);

private:
    QString src[7];
};

#endif // PRIZE_H
