#include "level4.h"
#include "ui_level4.h"
#include<QPainter>
#include<QPixmap>
level4::level4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::level4)
{
    ui->setupUi(this);
    man=new ROLE(this);
    man->move(0,20);
    for(int i=0;i<20;i++)coin[i]=new prize(this);
    coin[0]->move(160,20);
    coin[1]->move(240,40);
    coin[2]->move(320,120);
    coin[3]->move(180,160);
    coin[4]->move(340,200);
    coin[5]->move(420,200);
    coin[6]->move(660,180);
    coin[7]->move(320,280);
    coin[8]->move(440,280);
    coin[9]->move(20,320);
    coin[10]->move(640,320);
    coin[11]->move(740,320);
    coin[12]->move(580,180);
    coin[13]->move(240,360);
    coin[14]->move(540,360);
    coin[15]->move(160,440);
    coin[16]->move(700,420);
    coin[17]->move(40,480);
    coin[18]->move(20,540);
    coin[19]->move(560,520);
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
    minleft=2;
    secleft=0;
    iswin=0;
}

level4::~level4()
{
    iswin=0;
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
void level4::renew()
{
    man->move(0,20);
    for(int i=0;i<20;i++){
        coin[i]->hided =0;
        coin[i]->show();
    }
    temp=0;
    cointmp=0;
    score =0;
    minleft=2;
    secleft=0;
}
void level4::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap bbg;
    painter.setPen(Qt::white);
    painter.setFont(QFont("Segoe UI Black",25));
    update();
    bbg.load(":/Image/levelbgblack.jpg");
    painter.drawPixmap(0,0,800 ,600,bbg);
    painter.drawText(570,50,"SCORE");
    painter.drawText(620,90,QString::number(score)+"/140");
    if(secleft>9)painter.drawText(570,140,"TIME "+QString::number(minleft)+":"+QString::number(secleft));
    else painter.drawText(570,140,"TIME "+QString::number(minleft)+":0"+QString::number(secleft));
}
void level4::keyPressEvent(QKeyEvent *event)
{
    int n1=man->pos().x();
    int n3=n1+20;
    int n2=man->pos().y();
    int n4=man->pos().y()+20;
    int n5=n3-20;
    int up=0,down=0,right=0,left=0;
    if((n1==760||n1==740)&&n2==560){
        right=1;
        down=1;
    }
    //up
    if (n2==20)up=1;
    else if (n2==40&&(n1==60||n1==80||n1==140||n1==280))up=1;
    else if (n2==40&&(n3==60||n3==80||n3==140||n3==280))up=1;
    else if (n2==60&&(n1==300||n1==320||n1==340||n1==360||n1==380||n1==400||n1==420||n1==440||n1==460||n1==480))up=1;
    else if (n2==60&&(n3==300||n3==320||n3==340||n3==360||n3==380||n3==400||n3==420||n3==440||n3==460||n3==480))up=1;
    else if (n2==80&&(n1==200||n1==220))up=1;
    else if (n2==80&&(n3==200||n3==220))up=1;
    else if (n2==120&&(n1==20||n1==40||n1==60||n1==100))up=1;
    else if (n2==120&&(n3==20||n3==40||n3==60||n3==100))up=1;
    else if (n2==140&&(n1==80))up=1;
    else if (n2==140&&(n3==80))up=1;
    else if (n2==160&&(n1==140||n1==160||n1==180||n1==200))up=1;
    else if (n2==160&&(n3==140||n3==160||n3==180||n3==200))up=1;
    else if (n2==180&&(n1==640||n1==580||n1==600||n1==660||n1==680))up=1;
    else if (n2==180&&(n3==640||n3==580||n3==600||n3==660||n3==680))up=1;
    else if (n2==200&&(n1==300||n1==320||n1==340||n1==360||n1==380||n1==420||n1==480||n1==500||n1==740||n1==760))up=1;
    else if (n2==200&&(n3==300||n3==320||n3==340||n3==360||n3==380||n3==420||n3==480||n3==500||n3==740||n3==760))up=1;
    else if (n2==220&&(n1==220||n1==240||n1==540||n1==560||n1==620))up=1;
    else if (n2==220&&(n3==220||n3==240||n3==540||n3==560||n3==620))up=1;
    else if (n2==260&&(n1==80||n1==360||n1==380||n1==420||n1==440||n1==700||n1==720||n1==740||n1==760))up=1;
    else if (n2==260&&(n3==80||n3==360||n3==380||n3==420||n3==440||n3==700||n3==720||n3==740||n3==760))up=1;
    else if (n2==280&&(n1==220||n1==240||n1==260||n1==400||n1==620||n1==640))up=1;
    else if (n2==280&&(n3==220||n3==240||n3==260||n3==400||n3==620||n3==640))up=1;
    else if (n2==300&&(n1==480||n1==500))up=1;
    else if (n2==300&&(n3==480||n3==500))up=1;
    else if (n2==320&&(n1==80))up=1;
    else if (n2==320&&(n3==80))up=1;
    else if (n2==340&&(n1==240||n1==260||n1==280||n1==300||n1==340||n1==380||n1==420||n1==460||n1==500||n1==520))up=1;
    else if (n2==340&&(n3==240||n3==260||n3==280||n3==300||n3==340||n3==380||n3==420||n3==460||n3==500||n3==520))up=1;
    else if (n2==360&&(n1==60||n1==80||n1==100||n1==120||n1==140||n1==160||n1==180||n1==200||n1==220||n1==720))up=1;
    else if (n2==360&&(n3==60||n3==80||n3==100||n3==120||n3==140||n3==160||n3==180||n3==200||n3==220||n3==720))up=1;
    else if (n2==380&&(n1==320||n1==360||n1==400||n1==440||n1==480||n1==580||n1==600))up=1;
    else if (n2==380&&(n3==320||n3==360||n3==400||n3==440||n3==480||n3==580||n3==600))up=1;
    else if (n2==400&&(n1==520))up=1;
    else if (n2==400&&(n3==520))up=1;
    else if (n2==420&&(n1==20||n1==40||n1==60||n1==140||n1==680||n1==700||n1==720))up=1;
    else if (n2==420&&(n3==20||n3==40||n3==60||n3==140||n3==680||n3==700||n3==720))up=1;
    else if (n2==440&&(n1==160))up=1;
    else if (n2==440&&(n3==160))up=1;
    else if (n2==460&&(n1==260||n1==280||n1==300||n1==320||n1==340||n1==360||n1==400||n1==500||n1==520||n1==540||n1==560||n1==580||n1==600||n1==620))up=1;
    else if (n2==460&&(n3==260||n3==280||n3==300||n3==320||n3==340||n3==360||n3==400||n3==500||n3==520||n3==540||n3==560||n3==580||n3==600||n3==620))up=1;
    else if (n2==480&&(n1==740||n1==760))up=1;
    else if (n2==480&&(n3==740||n3==760))up=1;
    else if (n2==520&&(n1==240||n1==540||n1==560||n1==580))up=1;
    else if (n2==520&&(n3==240||n3==540||n3==560||n3==580))up=1;
    else if (n2==540&&(n1==20||n1==40||n1==60||n1==80||n1==100||n1==360||n1==380||n1==400||n1==420||n1==440||n1==600||n1==620||n1==640||n1==660||n1==680||n1==700))up=1;
    else if (n2==540&&(n3==20||n3==40||n3==60||n3==80||n3==100||n3==360||n3==380||n3==400||n3==420||n3==440||n3==600||n3==620||n3==640||n3==660||n3==680||n3==700))up=1;
    //down
    if (n4==40&&(n1==0||n1==200))down=1;
    else if (n4==60&&(n1==20||n1==40||n1==60||n1==80||n1==100))down=1;
    else if (n4==80&&(n1==360||n1==380||n1==400||n1==420||n1==500||n1==520))down=1;
    else if (n4==100&&(n1==220||n1==240||n1==480))down=1;
    else if (n4==120&&(n1==140||n1==160||n1==180||n1==200||n1==300))down=1;
    else if (n4==140&&(n1==320||n1==340))down=1;
    else if (n4==160&&(n1==60||n1==80))down=1;
    else if (n4==180&&(n1==140||n1==160))down=1;
    else if (n4==220&&(n1==360||n1==380||n1==420||n1==440))down=1;
    else if (n4==240&&(n1==220||n1==240||n1==260||n1==580||n1==600||n1==620||n1==640))down=1;
    else if (n4==260&&(n1==480||n1==500))down=1;
    else if (n4==280&&(n1==80||n1==720))down=1;
    else if (n4==300&&(n1==240||n1==260||n1==280||n1==300||n1==320||n1==340||n1==360||n1==380||n1==400||n1==420||n1==440||n1==460||n1==480||n1==500||n1==680))down=1;
    else if (n4==320&&(n1==80||n1==100||n1==120||n1==140||n1==160||n1==180||n1==200||n1==220))down=1;
    else if (n4==360&&(n1==500||n1==520))down=1;
    else if (n4==380&&(n1==20||n1==40||n1==60||n1==140||n1==160||n1==240||n1==700||n1==720||n1==740||n1==760))down=1;
    else if (n4==400&&(n1==440))down=1;
    else if (n4==420&&(n1==260||n1==280||n1==300||n1==320||n1==340||n1==360||n1==380||n1==400||n1==520||n1==540||n1==560||n1==580||n1==600||n1==620))down=1;
    else if (n4==460&&(n1==80||n1==160||n1==180||n1==680))down=1;
    else if (n4==480&&(n1==20||n1==100||n1==520||n1==540||n1==560||n1==580||n1==600))down=1;
    else if (n4==500&&(n1==40||n1==60||n1==320||n1==340||n1==360||n1==380||n1==400||n1==420||n1==660||n1==640||n1==620||n1==700))down=1;
    else if (n4==540&&(n1==240||n1==260||n1==280||n1==300))down=1;
    else if (n4==560&&n1<740)down=1;
    else if (n4==40&&(n3==200))down=1;
    else if (n4==60&&(n3==20||n3==40||n3==60||n3==80||n3==100))down=1;
    else if (n4==80&&(n3==360||n3==380||n3==400||n3==420||n3==500||n3==520))down=1;
    else if (n4==100&&(n3==220||n3==240||n3==480))down=1;
    else if (n4==120&&(n3==140||n3==160||n3==180||n3==200||n3==300))down=1;
    else if (n4==140&&(n3==320||n3==340))down=1;
    else if (n4==160&&(n3==60||n3==80))down=1;
    else if (n4==180&&(n3==140||n3==160))down=1;
    else if (n4==220&&(n3==360||n3==380||n3==420||n3==440))down=1;
    else if (n4==240&&(n3==220||n3==240||n3==260||n3==580||n3==600||n3==620||n3==640))down=1;
    else if (n4==260&&(n3==480||n3==500))down=1;
    else if (n4==280&&(n3==80||n3==720))down=1;
    else if (n4==300&&(n3==240||n3==260||n3==280||n3==300||n3==320||n3==340||n3==360||n3==380||n3==400||n3==420||n3==440||n3==460||n3==480||n3==500||n3==680))down=1;
    else if (n4==320&&(n3==80||n3==100||n3==120||n3==140||n3==160||n3==180||n3==200||n3==220))down=1;
    else if (n4==360&&(n3==500||n3==520))down=1;
    else if (n4==380&&(n3==20||n3==40||n3==60||n3==140||n3==160||n3==240||n3==700||n3==720||n3==740||n3==760))down=1;
    else if (n4==400&&(n3==440))down=1;
    else if (n4==420&&(n3==260||n3==280||n3==300||n3==320||n3==340||n3==360||n3==380||n3==400||n3==520||n3==540||n3==560||n3==580||n3==600||n3==620))down=1;
    else if (n4==460&&(n3==80||n3==160||n3==180||n3==680))down=1;
    else if (n4==480&&(n3==20||n3==100||n3==520||n3==540||n3==560||n3==580||n3==600))down=1;
    else if (n4==500&&(n3==40||n3==60||n3==320||n3==340||n3==360||n3==380||n3==400||n3==420||n3==420||n3==660||n3==640||n3==620||n3==700))down=1;
    else if (n4==540&&(n3==240||n3==260||n3==280||n3==300))down=1;
    else if (n4==560&&n3<740)down=1;
    //right
    if (n3==40&&(n2==20||n2==180||n2==200||n2==220||n2==240||n2==260||n2==280||n2==300||n2==320||n2==340))right=1;
    else if (n3==60&&(n2==120||n2==480||n2==500))right=1;
    else if (n3==120&&(n2==20||n2==140||n2==200||n2==220||n2==240||n2==400))right=1;
    else if (n3==140&&(n2==420||n2==480||n2==500||n2==520||n2==540||n2==560))right=1;
    else if (n3==180&&(n2==60))right=1;
    else if (n3==200&&(n2==20||n2==40||n2==120||n2==160||n2==180||n2==200||n2==260))right=1;
    else if (n3==220&&(n2==320||n2==400||n2==420||n2==440||n2==460||n2==480||n2==500||n2==560))right=1;
    else if (n3==260&&(n2==20))right=1;
    else if (n3==280&&(n2==40||n2==140||n2==160||n2==180))right=1;
    else if (n3==300&&(n2==340||n2==360||n2==520||n2==540))right=1;
    else if (n3==340&&(n2==100||n2==120||n2==140||n2==240||n2==340||n2==360))right=1;
    else if (n3==380&&(n2==200||n2==220||n2==260||n2==340||n2==360))right=1;
    else if (n3==420&&(n2==340||n2==360||n2==420||n2==440||n2==460||n2==480||n2==500))right=1;
    else if (n3==460&&(n2==120||n2==140||n2==160||n2==180||n2==280||n2==340||n2==360))right=1;
    else if (n3==480&&(n2==100||n2==380||n2==400||n2==420||n2==440))right=1;
    else if (n3==500&&(n2==200||n2==220||n2==240||n2==240||n2==260||n2==300||n2==500||n2==520||n2==540||n2==560))right=1;
    else if (n3==520&&(n2==20||n2==40||n2==60||n2==80))right=1;
    else if (n3==560&&(n2==260||n2==280||n2==300||n2==320||n2==340||n2==360))right=1;
    else if (n3==580&&(n2==520))right=1;
    else if (n3==600&&(n2==180||n2==200))right=1;
    else if (n3==660&&(n2==320||n2==340||n2==360||n2==380||n2==400||n2==480||n2==500))right=1;
    else if (n3==680&&(n2==180||n2==200||n2==220||n2==240))right=1;
    else if (n3==700&&(n2==300||n2==320||n2==340))right=1;
    else if (n3==720&&(n2==420||n2==440||n2==460))right=1;
    else if (n3==760&&(n2<=540))right=1;
    else if (n3==40&&(n4==20||n4==180||n4==200||n4==220||n4==240||n4==260||n4==280||n4==300||n4==320||n4==340))right=1;
    else if (n3==60&&(n4==120||n4==480||n4==500))right=1;
    else if (n3==120&&(n4==20||n4==140||n4==200||n4==220||n4==240||n4==400))right=1;
    else if (n3==140&&(n4==420||n4==480||n4==500||n4==520||n4==540||n4==560))right=1;
    else if (n3==180&&(n4==60))right=1;
    else if (n3==200&&(n4==20||n4==40||n4==120||n4==160||n4==180||n4==200||n4==260))right=1;
    else if (n3==220&&(n4==320||n4==400||n4==420||n4==440||n4==460||n4==480||n4==500||n4==560))right=1;
    else if (n3==260&&(n4==20))right=1;
    else if (n3==280&&(n4==40||n4==140||n4==160||n4==180))right=1;
    else if (n3==300&&(n4==340||n4==360||n4==520||n4==540))right=1;
    else if (n3==340&&(n4==100||n4==120||n4==140||n4==240||n4==340||n4==360))right=1;
    else if (n3==380&&(n4==200||n4==220||n4==260||n4==340||n4==360))right=1;
    else if (n3==420&&(n4==340||n4==360||n4==420||n4==440||n4==460||n4==480||n4==500))right=1;
    else if (n3==460&&(n4==120||n4==140||n4==160||n4==180||n4==280||n4==340||n4==360))right=1;
    else if (n3==480&&(n4==100||n4==380||n4==400||n4==420||n4==440))right=1;
    else if (n3==500&&(n4==200||n4==220||n4==240||n4==240||n4==260||n4==300||n4==500||n4==520||n4==540||n4==560))right=1;
    else if (n3==520&&(n4==20||n4==40||n4==60||n4==80))right=1;
    else if (n3==560&&(n4==260||n4==280||n4==300||n4==320||n4==340||n4==360))right=1;
    else if (n3==580&&(n4==520))right=1;
    else if (n3==600&&(n4==180||n4==200))right=1;
    else if (n3==660&&(n4==320||n4==340||n4==360||n4==380||n4==400||n4==480||n4==500))right=1;
    else if (n3==680&&(n4==180||n4==200||n4==220||n4==240))right=1;
    else if (n3==700&&(n4==300||n4==320||n4==340))right=1;
    else if (n3==720&&(n4==420||n4==440||n4==460))right=1;
    else if (n3==760&&(n4<=540))right=1;

    //left
    if (n1==0)left=1;
    else if (n1==20)left=1;
    else if (n5==40&&(n2==500))left=1;
    else if (n5==80&&(n2==260||n2==280||n2==320||n2==400))left=1;
    else if (n5==100&&(n2==20||n2==120||n2==180||n2==200||n2==220||n2==240||n2==300||n2==480))left=1;
    else if (n5==120&&(n2==80||n2==100||n2==500||n2==520))left=1;
    else if (n5==160&&(n2==20))left=1;
    else if (n5==180&&(n2==200||n2==220||n2==240||n2==400||n2==420))left=1;
    else if (n5==200&&(n2>=480))left=1;
    else if (n5==240&&(n2==20||n2==40||n2==60||n2==340))left=1;
    else if (n5==260&&(n2==120||n2==140||n2==160||n2==180||n2==200||n2==400||n2==420||n2==460||n2==480||n2==500))left=1;
    else if (n5==280&&(n2==260))left=1;
    else if (n5==320&&(n2==140))left=1;
    else if (n5==360&&(n2==540||n2==560))left=1;
    else if (n5==420&&(n2==200||n2==220||n2==260))left=1;
    else if (n5==440&&(n2==100||n2==120||n2==140||n2==160||n2==180))left=1;
    else if (n5==460&&(n2==240||n2==420||n2==440||n2==460||n2==480||n2==500||n2==520))left=1;
    else if (n5==500&&(n2==20||n2==40||n2==340||n2==360))left=1;
    else if (n5==520&&(n2==400||n2==420))left=1;
    else if (n5==540&&(n2==220||n2==240||n2==260||n2==280||n2==300||n2==320||n2==380||n2==520||n2==540||n2==560))left=1;
    else if (n5==580&&(n2==180||n2==200))left=1;
    else if (n5==620&&(n2==280||n2==300||n2==320||n2==340||n2==360||n2==500))left=1;
    else if (n5==640&&(n2==180||n2==200||n2==440))left=1;
    else if (n5==660&&(n2==260))left=1;
    else if (n5==700&&(n2==320||n2==340||n2==360||n2==380||n2==480||n2==500))left=1;
    else if (n5==720&&(n2==520))left=1;
    else if (n5==740&&(n2==300||n2==320||n2==340||n2==580))left=1;
    else if (n1==0)left=1;
    else if (n5==40&&(n4==500))left=1;
    else if (n5==80&&(n4==260||n4==280||n4==320||n4==400))left=1;
    else if (n5==100&&(n4==20||n4==120||n4==180||n4==200||n4==220||n4==240||n4==300||n4==480))left=1;
    else if (n5==120&&(n4==80||n4==100||n4==500||n4==520))left=1;
    else if (n5==160&&(n4==20))left=1;
    else if (n5==180&&(n4==200||n4==220||n4==240||n4==400||n4==420))left=1;
    else if (n5==200&&(n4>=480))left=1;
    else if (n5==240&&(n4==20||n4==40||n4==60||n4==340))left=1;
    else if (n5==260&&(n4==120||n4==140||n4==160||n4==180||n4==200||n4==400||n4==420||n4==460||n4==480||n4==500))left=1;
    else if (n5==280&&(n4==260))left=1;
    else if (n5==320&&(n4==140))left=1;
    else if (n5==360&&(n4==540||n4==560))left=1;
    else if (n5==420&&(n4==200||n4==220||n4==260))left=1;
    else if (n5==440&&(n4==100||n4==120||n4==140||n4==160||n4==180))left=1;
    else if (n5==460&&(n4==240||n4==420||n4==440||n4==460||n4==480||n4==500||n4==520))left=1;
    else if (n5==500&&(n4==20||n4==40||n4==340||n4==360))left=1;
    else if (n5==520&&(n4==400||n4==420))left=1;
    else if (n5==540&&(n4==220||n4==240||n4==260||n4==280||n4==300||n4==320||n4==380||n4==520||n4==540||n4==560))left=1;
    else if (n5==580&&(n4==180||n4==200))left=1;
    else if (n5==620&&(n4==280||n4==300||n4==320||n4==340||n4==360||n4==500))left=1;
    else if (n5==640&&(n4==180||n4==200||n4==440))left=1;
    else if (n5==660&&(n4==260))left=1;
    else if (n5==700&&(n4==320||n4==340||n4==360||n4==380||n4==480||n4==500))left=1;
    else if (n5==720&&(n4==520))left=1;
    else if (n5==740&&(n4==300||n4==320||n4==340||n4==580))left=1;

    if (event->key()==Qt::Key_Up)
    {
        if(up!=1)man->move(man->pos().x(),man->pos().y()-20);
        man->direction=1;
    }
    else if (event->key()==Qt::Key_Down)
    {
        if(down!=1)man->move(man->pos().x(),man->pos().y()+20);
        man->direction=2;
    }
    else if (event->key()==Qt::Key_Right)
    {
        if(right!=1)man->move(man->pos().x()+20,man->pos().y());
        man->direction=4;
    }
    else if (event->key()==Qt::Key_Left)
    {
        if(left!=1)man->move(man->pos().x()-20,man->pos().y());
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
void level4::getcoin(){
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

void level4::time(){
    if(secleft)secleft--;
    else if(minleft){
    secleft=59;
    minleft--;
    }
    if(secleft<=0&&minleft<=0){
        if (man->x()!=740||man->y()!=560)
        {
            bgm->stop();
            close();
        }
        else if (score<140){
            bgm->stop();
            close();
        }
        else {
            close();
            win();
        }
    }else if (man->x()==740&&man->y()==560&&score>=140){
        close();
        win();
        }
}
void level4::win(){
    iswin=1;
    cointimer->stop();
    ttimer->stop();
    m=new movie();
    m->time=7;
    bgm->stop();
    m->playList->setCurrentIndex(3);
    update();
    //m->show();
}
