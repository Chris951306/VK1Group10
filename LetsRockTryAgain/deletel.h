#ifndef DELETEL_H
#define DELETEL_H

#include <QDialog>
#include <service.h>

namespace Ui {
class deletel;
}

class deletel : public QDialog
{
    Q_OBJECT

public:
    explicit deletel(QWidget *parent = 0);
    ~deletel();
    void displayLinks(std::vector<link> links);

private slots:
    void on_pushButton_clicked();

private:
    Ui::deletel *ui;
};

#endif // DELETEL_H
