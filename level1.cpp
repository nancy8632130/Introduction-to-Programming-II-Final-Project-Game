#include "level1.h"
#include "ui_level1.h"
#include<QPainter>
#include<QPixmap>
level1::level1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::level1)
{
    ui->setupUi(this);
    man=new ROLE(this);
    man->move(0,40);
    for(int i=0;i<20;i++)coin[i]=new prize(this);
    coin[0]->move(440,40);
    coin[1]->move(160,80);
    coin[2]->move(480,120);
    coin[3]->move(320,160);
    coin[4]->move(160,200);
    coin[5]->move(400,200);
    coin[6]->move(720,200);
    coin[7]->move(120,280);
    coin[8]->move(200,280);
    coin[9]->move(40,320);
    coin[10]->move(520,320);
    coin[11]->move(680,320);
    coin[12]->move(640,200);
    coin[13]->move(280,360);
    coin[14]->move(600,360);
    coin[15]->move(280,440);
    coin[16]->move(440,440);
    coin[17]->move(120,480);
    coin[18]->move(240,520);
    coin[19]->move(680,520);
    bgm=new Music("musicfile/music.wav",80,1);
    coinmus[0]=new Music("musicfile/coin.mp3",100,0);
    coinmus[1]=new Music("musicfile/coin.mp3",100,0);
    coinmus[2]=new Music("musicfile/coin.mp3",100,0);
    temp=0;
    //bgm->play();
    cointimer =new QTimer(this);
    connect(cointimer,SIGNAL(timeout()),this,SLOT(getcoin()));
    ttimer=new QTimer(this);
    connect(ttimer,SIGNAL(timeout()),this,SLOT(time()));
    cointmp=0;
    score=0;
    minleft=0;
    secleft=30;
    iswin=0;
}
void level1::renew()
{
    iswin=0;
    man->move(0,40);
    for(int i=0;i<20;i++){
        coin[i]->hided =0;
        coin[i]->show();
    }
    temp=0;
    cointmp=0;
    score =0;
    minleft=0;
    secleft=30;
}
level1::~level1()
{
    delete ui;
    delete man;
    for(int i=0;i<20;i++){
        delete coin[i];
    }
    bgm->stop();
    delete bgm;
    cointimer->stop();
    delete cointimer;
    delete coinmus[0];
    delete coinmus[1];
    delete coinmus[2];
    delete ttimer;
}
void level1::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap bbg;
    painter.setPen(Qt::white);
    painter.setFont(QFont("Segoe UI Black",25));
    update();
    bbg.load(":/Image/levelbgblack.jpg");
    painter.drawPixmap(0,0,800 ,600,bbg);
    painter.drawText(570,50,"SCORE");
    painter.drawText(620,90,QString::number(score)+"/50");
    if(secleft>9)painter.drawText(570,140,"TIME "+QString::number(minleft)+":"+QString::number(secleft));
    else painter.drawText(570,140,"TIME "+QString::number(minleft)+":0"+QString::number(secleft));
}
void level1::keyPressEvent(QKeyEvent *event)
{
    int n1=man->pos().x();
    int n2=man->pos().y();
    int up=0,down=0,right=0,left=0;
    if(n1==0)left=1;
    if(n1==760)right=1;
    //up
    if (n2==40&&(n1==0||n1==40||n1==80||n1==440||n1==480))up=1;
    else if (n2==80&&(n1==160||n1==200||n1==240||n1==280||n1==320||n1==360||n1==400))up=1;
    else if (n2==120&&(n1==440))up=1;
    else if (n2==160&&(n1==120||n1==160||n1==200))up=1;
    else if (n2==200&&(n1==400||n1==440||n1==480||n1==520||n1==560||n1==600||n1==640||n1==680||n1==720))up=1;
    else if (n2==240&&(n1==280||n1==320||n1==360))up=1;
    else if (n2==280&&(n1==120))up=1;
    else if (n2==320&&(n1==520))up=1;
    else if (n2==360&&(n1==200||n1==240||n1==280||n1==360||n1==400||n1==480||n1==600))up=1;
    else if (n2==440&&(n1==160||n1==280||n1==440||n1==480))up=1;
    else if (n2==520&&(n1==80||n1==160||n1==200||n1==240||n1==400||n1==440||n1==480||n1==520||n1==560||n1==760))up=1;
    //down
    if ((n1==0||n1==440)&&n2==40)down=1;
    else if (n2==80&&(n1==160||n1==200||n1==280||n1==360))down=1;
    else if (n2==120&&(n1==400||n1==440||n1==480))down=1;
    else if (n2==160&&(n1==320))down=1;
    else if (n2==200&&(n1==80||n1==120||n1==160))down=1;
    else if (n2==240&&(n1==480||n1==520||n1==560))down=1;
    else if (n2==280&&(n1==200||n1==240||n1==280||n1==320||n1==360||n1==400||n1==600||n1==640))down=1;
    else if (n2==360&&(n1==240||n1==280||n1==400||n1==440||n1==480))down=1;
    else if (n2==440&&(n1==160||n1==200||n1==440||n1==480||n1==520))down=1;
    else if (n2==520&&(n1==40||n1==80||n1==120||n1==160||n1==200||n1==240||n1==280||n1==360||n1==400||n1==440||n1==480||n1==520||n1==560||n1==600||n1==680||n1==720||n1==760))down=1;
    //right
    if (n1==40&&(n2==240||n2==280||n2==320||n2==360||n2==400||n2==440||n2==480))right=1;
    else if (n1==80&&(n2==40||n2==80||n2==120))right=1;
    else if (n1==120&&(n2==280||n2==320||n2==360||n2==400||n2==480))right=1;
    else if (n1==200&&(n2==400||n2==440))right=1;
    else if (n1==240&&(n2==120||n2==160||n2==200))right=1;
    else if (n1==280&&(n2==360||n2==440||n2==480||n2==520))right=1;
    else if (n1==320&&(n2==120||n2==160))right=1;
    else if (n1==360&&(n2==400||n2==440||n2==480))right=1;
    else if (n1==400&&(n2==80))right=1;
    else if (n1==440&&(n2==280||n2==320))right=1;
    else if (n1==480&&(n2==40||n2==80||n2==120))right=1;
    else if (n1==520&&(n2==320||n2==360||n2==400||n2==440))right=1;
    else if (n1==600&&(n2==360||n2==400||n2==440||n2==480||n2==520))right=1;
    else if (n1==720&&(n2<520))right=1;
    //left
    if (n1==40&&(n2>=80))left=1;
    else if (n1==120&&(n2==280||n2==320||n2==360||n2==400||n2==440||n2==480))left=1;
    else if (n1==160&&(n2==80))left=1;
    else if (n1==200&&(n2==240||n2==280||n2==360||n2==400))left=1;
    else if (n1==240&&(n2==120))left=1;
    else if (n1==280&&(n2==440||n2==480))left=1;
    else if (n1==320&&(n2==120||n2==160))left=1;
    else if (n1==360&&(n2==360||n2==400||n2==440||n2==480||n2==520||n2==580))left=1;
    else if (n1==400&&(n2==120||n2==200))left=1;
    else if (n1==440&&(n2==40||n2==320||n2==440))left=1;
    else if (n1==480&&(n2==80))left=1;
    else if (n1==520&&(n2==320||n2==400))left=1;
    else if (n1==600&&(n2==280||n2==360||n2==400||n2==440||n2==480))left=1;
    else if (n1==680&&(n2>=320))left=1;
    if (event->key()==Qt::Key_Up)
    {
        if(up!=1)man->move(man->pos().x(),man->pos().y()-40);
        man->direction=1;
    }
    else if (event->key()==Qt::Key_Down)
    {
        if (down!=1)man->move(man->pos().x(),man->pos().y()+40);
        man->direction=2;
    }
    else if (event->key()==Qt::Key_Right)
    {
        if(right!=1)man->move(man->pos().x()+40,man->pos().y());
        man->direction=4;
    }
    else if (event->key()==Qt::Key_Left)
    {
        if(left!=1)man->move(man->pos().x()-40,man->pos().y());
        man->direction=3;
    }
    else if (event->key()==Qt::Key_Escape){
        bgm->stop();
        close();
    }
    else if (event->key()==Qt::Key_Z)
    {
        if(temp==0)
        {
            bgm->play();
            temp=1;
        }
        else if(temp==1)
        {
            bgm->pause();
            temp=0;
        }
   }
}
void level1::getcoin(){
    for(int i=0;i<20;i++){
        if(coin[i]->hided==0&&man->pos()==coin[i]->pos()){
            coin[i]->hided=1;
            coin[i]->hide();
            coinmus[cointmp]->play();
            cointmp++;
            cointmp%=3;
            score+=10;
        }
    }
}
void level1::time(){
    if(secleft)secleft--;
    else if(minleft){
    secleft=59;
    minleft--;
    }
    if(secleft<=0&&minleft<=0){
        if (man->x()!=760||man->y()!=520)
        {
            bgm->stop();
            close();
        }
        else if (score<50){
            bgm->stop();
            close();
        }
        else {
            close();
            win();
        }
    }else if (man->x()==760&&man->y()==520&&score>=50){
        close();
        win();
        }
}
void level1::win(){
    iswin=1;
    cointimer->stop();
    ttimer->stop();
    m=new movie();
    bgm->stop();
    m->time=14;
    m->playList->setCurrentIndex(0);
    update();
    //m->show();
}
