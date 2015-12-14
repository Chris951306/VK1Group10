#include "snoop.h"
#include "ui_snoop.h"

snoop::snoop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::snoop){
    ui->setupUi(this);
    snoopit();
}

snoop::~snoop(){
    delete ui;
}

void snoop::snoopit(){
    QMediaPlayer* audio = new QMediaPlayer(this, QMediaPlayer::StreamPlayback);
    audio->setMedia(QUrl::fromLocalFile("song.mp3"));
    audio->setVolume(50);
    audio->play();
    QMediaPlayer* video = new QMediaPlayer(this, QMediaPlayer::StreamPlayback);
    video->setMedia(QUrl::fromLocalFile("giphy.gif"));
    video->setVideoOutput(ui->video_player);
    ui->video_player->show();
    video->play();
}
