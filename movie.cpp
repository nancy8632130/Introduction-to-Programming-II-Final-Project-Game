#include "movie.h"
#include "ui_movie.h"
#include<QMediaPlaylist>
#include<QMediaPlayer>
#include<QVideoWidget>
#include<QFileDialog>
#include<QProgressBar>
#include<QSlider>
movie::movie(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::movie)
{
    ui->setupUi(this);
    movietimer =new QTimer(this);
    connect(movietimer,SIGNAL(timeout()),this,SLOT(movieplay()));
    movietimer->start(1000);
    movietime=0;
    playList = new QMediaPlaylist;
    playList->setPlaybackMode(QMediaPlaylist::CurrentItemOnce);
    // 加入兩個檔案，交叉輪播
    playList->addMedia(QUrl::fromLocalFile("Produce2.avi"));
    playList->addMedia(QUrl::fromLocalFile("Produce3.avi"));
    playList->addMedia(QUrl::fromLocalFile("Produce4.avi"));
    playList->addMedia(QUrl::fromLocalFile("Produce5.avi"));
    playList->addMedia(QUrl::fromLocalFile("Produce6.avi"));
    player = new QMediaPlayer;
    vw = new QVideoWidget;
    player->setPlaylist(playList);
    player->setVideoOutput(vw);
    //this->setCentralWidget(vw);
    this->setFixedSize(800,600);
    vw->setGeometry(0,0,2000,1800);
    vw->show();
    player->play();

}

movie::~movie()
{
    delete ui;
}
void movie::movieplay(){
    movietime++;
    if(movietime==time){
        movietime=0;
        movietimer->stop();
        vw->close();
    }
}
