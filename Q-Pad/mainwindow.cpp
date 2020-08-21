#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>
#include <QtWidgets>
#include <QtGui>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    setDir("");
    ui->setupUi(this);
    this->setWindowTitle("Q-PAD");
    this->setCentralWidget(ui->textEdit);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    if (ui->textEdit->toPlainText() == "") return;
    QMessageBox::StandardButton flag;
    flag = QMessageBox::question(this,"Uyari","Kaydetmediginiz calismalar sonsuza kadar koybalacak , <b> emin misiniz ?</b>",
                          QMessageBox::Yes | QMessageBox::No);
    if (flag == QMessageBox::Yes){
        setDir("");
        ui->textEdit->setPlainText("");
    }
}

QString MainWindow::getDir() const
{
    return dir;
}

void MainWindow::setDir(const QString &value)
{
    dir = value;
}

void MainWindow::on_actionSave_triggered()
{
    if (getDir() == ""){
        QMessageBox::warning(this,"Uyari","Bir dosya acmadiginiz icin bu secenek aktif degildir. <b> Save as </b> secenegini deneyin");
    }
    else{
        QFile file(getDir());
        file.open(QIODevice::WriteOnly | QIODevice::Text);
        QTextStream stream(&file);
        stream << ui->textEdit->toPlainText();
        stream.flush();
        file.close();
    }
}

void MainWindow::on_actionOpen_triggered()
{
    setDir(QFileDialog::getOpenFileName(this,"Bir dosya aciniz"));
    QFile file(getDir());
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream stream(&file);
    ui->textEdit->setPlainText(stream.readAll());
    stream.flush();
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    setDir(QFileDialog::getSaveFileName(this,"Bir dizin seciniz"));
    on_actionSave_triggered();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}
