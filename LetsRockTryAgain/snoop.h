#ifndef SNOOP_H
#define SNOOP_H

#include <QDialog>
#include <QMediaPlayer> //Library for music- and video-streaming
#include <QVideoWidget> //Library to create a video-widget

namespace Ui {
class snoop;
}

class snoop : public QDialog{
    Q_OBJECT

public:
    explicit snoop(QWidget *parent = 0); //Default constructor for class
    ~snoop(); //Default destructor for class
    void snoopit(); //D O DOUBLE-G

private:
    Ui::snoop *ui;
};

#endif // SNOOP_H
