#include "role.h"

ROLE::ROLE(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(35,35);
    src[0]=":/Image/manup.png";
    src[1]=":/Image/mandown.png";
    src[3]=":/Image/manright.png";
    src[2]=":/Image/manleft.png";
}

ROLE::~ROLE()
{

}

void ROLE::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(src[direction-1]);
    painter.drawPixmap(0,0,35,35,pix);
}

