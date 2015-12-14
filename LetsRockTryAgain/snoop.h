#ifndef SNOOP_H
#define SNOOP_H

#include <QDialog>
#include <QMediaPlayer>
#include <QVideoWidget>

namespace Ui {
class snoop;
}

class snoop : public QDialog{
    Q_OBJECT

public:
    explicit snoop(QWidget *parent = 0);
    ~snoop();
    void snoopit();

private:
    Ui::snoop *ui;
};

#endif // SNOOP_H
