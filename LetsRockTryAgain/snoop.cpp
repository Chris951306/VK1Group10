#include "snoop.h"
#include "ui_snoop.h"

//Default constructor for class
snoop::snoop(QWidget *parent) : QDialog(parent), ui(new Ui::snoop){
    ui->setupUi(this);
    snoopit();
}

//Default destructor for class
snoop::~snoop(){
    delete ui;
}

//D O DOUBLE-G
void snoop::snoopit(){
    //Creates a QMediaPlayer for audio streaming
    QMediaPlayer* audio = new QMediaPlayer(this, QMediaPlayer::StreamPlayback);
    //Sets the song equal to a local file, in this case the song Next Episode by Dr. Dre and Snoop Dogg(We claim no ownership to this file, the title or any other element regarding this file)
    audio->setMedia(QUrl::fromLocalFile("nextepisode.mp3"));
    //Sets volume
    audio->setVolume(50);
    //Plays file
    audio->play();
    //Creates a QMediaPlayer for video streaming
    QMediaPlayer* video = new QMediaPlayer(this, QMediaPlayer::StreamPlayback);
    //Sets the video equal to a local file, in this case a looped gif, downloaded from giphy.com
    video->setMedia(QUrl::fromLocalFile("snoop.gif"));
    //Sets the output of the video to the QVideoWidget names video_player
    video->setVideoOutput(ui->video_player);
    //Makes the video_player show it's contents
    ui->video_player->show();
    //Plays file
    video->play();
}
