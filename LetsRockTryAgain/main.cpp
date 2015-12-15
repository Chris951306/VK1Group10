#include "mainmenu.h"
#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    MainMenu w;
    QIcon icon("icons/Logo.png");
    w.setWindowIcon(icon);
    w.show();

    return a.exec();
}
