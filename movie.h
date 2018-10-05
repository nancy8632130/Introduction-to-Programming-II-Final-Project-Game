#ifndef MOVIE_H
#define MOVIE_H

#include<QWidget>
#include<QMediaPlaylist>
#include<QMediaPlayer>
#include<QVideoWidget>
#include<QFileDialog>
#include<QProgressBar>
#include<QSlider>
#include<QTimer>
namespace Ui {
class movie;
}

class movie : public QWidget
{
    Q_OBJECT

public:
    explicit movie(QWidget *parent = 0);
    ~movie();
    QTimer *movietimer;
    QMediaPlaylist * playList;
    int time;
private slots:
    void movieplay();

private:
    int movietime;
    QMediaPlayer * player;
    QVideoWidget * vw;
    Ui::movie *ui;

};

#endif // MOVIE_H
