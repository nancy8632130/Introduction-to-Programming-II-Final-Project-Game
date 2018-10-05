#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QPainter>
#include<QPixmap>
#include <QKeyEvent>
int level=1;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    movietimer =new QTimer(this);
    connect(movietimer,SIGNAL(timeout()),this,SLOT(movieplay()));
    movietimer->start(1000);
    movietime=0;


    playList = new QMediaPlaylist;
    playList->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    // 加入兩個檔案，交叉輪播
    playList->addMedia(QUrl::fromLocalFile("Produce.avi"));
    playList->addMedia(QUrl::fromLocalFile("Produce2.avi"));

    player = new QMediaPlayer(this);
    vw = new QVideoWidget(this);
    player->setPlaylist(playList);
    player->setVideoOutput(vw);
    this->setCentralWidget(vw);
    this->setFixedSize(800,600);

    playList->setCurrentIndex(0);
    player->play();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete bgm;
}
void MainWindow::movieplay(){
    movietime++;
    if(movietime==8){
        movietime=0;
        movietimer->stop();
        ui->setupUi(this);
        bgm=new Music("musicfile/bgm.wav",100,1);
        temp=1;
        bgm->play();
    }
}

void MainWindow::on_pushButton_1_clicked()
{
    level=1;
}

void MainWindow::on_pushButton_2_clicked()
{
    level=2;
}

void MainWindow::on_pushButton_3_clicked()
{
    level=3;
}

void MainWindow::on_pushButton_4_clicked()
{
    level=4;
}

void MainWindow::on_pushButton_5_clicked()
{
    level=5;
}

void MainWindow::on_pushButton_start_clicked()
{
    bgm->stop();
    if(level==1){
        le1.renew();
        //this->hide();
        le1.bgm->play();
        le1.show();
        le1.cointimer->start(8);
        le1.ttimer->start(1000);

    }else if(level==2){
        le2.renew();
        //this->hide();
        le2.bgm->play();
        le2.show();
        le2.cointimer->start(8);
        le2.ttimer->start(1000);
    }else if(level==3){
        le3.renew();
        //this->hide();
        le3.bgm->play();
        le3.show();
        le3.cointimer->start(8);
        le3.ttimer->start(1000);
    }else if(level==4){
        le4.renew();
        //this->hide();
        le4.bgm->play();
        le4.show();
        le4.cointimer->start(8);
        le4.ttimer->start(1000);
    }else if(level==5){
        le5.renew();
        //this->hide();
        le5.bgm->play();
        le5.show();
        le5.cointimer->start(8);
        le5.ttimer->start(1000);
    }
}

void MainWindow::on_pushButton_info_clicked()
{
    about.show();
}
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key()==Qt::Key_Z)
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
    else if (event->key()==Qt::Key_Escape){
        close();
    }
}
