#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "yilan.h"
#include "vucut.h"
#include <QtGui>
#include <QKeyEvent>
#include <QMessageBox>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow(); 
    // bu değerler bir oyun karesinin genişliği ve uzunluğunu tutar.

private:
    Ui::MainWindow *ui;
    int genislik;
    int uzunluk;
    int xKareSayisi;
    int yKareSayisi;
    bool yemCizildiMi;
    Yilan yilan;
    int yemX,yemY;
    int yon;
    bool ustUsteMi(int yemX,int yemY);
    bool yanlisHareketKontrol(int x,int y);
    bool yemKontrol(int x,int y);
    void mesajGoster();
    void yilanOlustur();
    void yuksekPuanKontrol(int);
    void kayitDosyasiOku();
    void kayitDosyasinaYaz();
    int hiz;
    int puan;
    QTimer* timer;
    QString highScoreEasy;
    QString highScoreNormal;
    QString highScoreHard;
    int easy,normal,hard;
protected:
    void paintEvent(QPaintEvent* e);
    void arkaPlanCiz(QPaintEvent* e); 
    void yilanGuncelle(QPaintEvent *e);
    void yemCiz(QPaintEvent *e);
    void keyPressEvent(QKeyEvent *e);
private slots:
    void hareketEt();
    void puanGuncelle();
    void on_pushButton_clicked();
    void on_radioButton_4_clicked();
    void on_radioButton_5_clicked();
    void on_radioButton_6_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
};
#endif // MAINWINDOW_H
