#ifndef ROLE_H
#define ROLE_H

#include <QWidget>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <math.h>

class ROLE : public QWidget
{
    Q_OBJECT
public:
    explicit ROLE(QWidget *parent = 0);
    ~ROLE();
    int direction=4;
protected:
    void paintEvent(QPaintEvent *);

private:
    QString src[4];

};

#endif // ROLE_H
