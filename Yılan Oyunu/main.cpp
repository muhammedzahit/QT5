#include "mainwindow.h"
#include <QApplication>
#include <QTranslator>
#include <QInputDialog>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t;
    t.load(":/translations/english");
    QStringList diller;
    diller << "Turkce" << "English";
	// kullanıcıdan bir dil secmesi istenir. 
    QString dil = QInputDialog::getItem(NULL,"Dil","Dil Seç",diller);
    if (dil == "English")
        a.installTranslator(&t);
    MainWindow w;
    w.show();
    return a.exec();
}
