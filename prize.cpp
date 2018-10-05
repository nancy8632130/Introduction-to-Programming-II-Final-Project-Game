#include "prize.h"
int i=0;
prize::prize(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(40,40);
    src[0]=":/Image/coins1-1.png";
    src[1]=":/Image/coins1-2.png";
    src[2]=":/Image/coins1-3.png";
    src[3]=":/Image/coins1-4.png";
    src[4]=":/Image/coins1-5.png";
    src[5]=":/Image/coins1-6.png";
    src[6]=":/Image/coins1-7.png";
    hided=0;
}
prize::~prize()
{

}
void prize::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(src[i++/120]);
    i=i%840;
    painter.drawPixmap(0,0,40,40,pix);
}

