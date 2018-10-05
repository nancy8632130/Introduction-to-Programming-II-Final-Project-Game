#include "info.h"
#include "ui_info.h"
#include<QPainter>
#include<QPixmap>
info::info(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::info)
{
    ui->setupUi(this);
}

info::~info()
{
    delete ui;
}

void info::on_pushButton_clicked()
{
    this->hide();
}
void info::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap bbg;
    bbg.load(":/Image/menubg.jpg");
    painter.drawPixmap(0,0,800 ,600,bbg);
}
