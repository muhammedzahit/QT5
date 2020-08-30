#include "mainwindow.h"
#include "ui_mainwindow.h"
enum yonler{YUKARI,ASAGI,SAG,SOL};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Qt 5 - Yılan Oyunu");
    ui->stack->setCurrentIndex(0);
	
	// pencerinin boyutlandırılması kısıtlandırıldı.
    setFixedSize(480,360);
	
	// oyundaki bir hareket karesenin uzunluk ve genislikleri atandı.
    genislik = 20;
    uzunluk = 20;
    puan = 0;
    easy = 0; normal = 0; hard = 0;
    kayitDosyasiOku();
	
	// eğer yemin x ve y değerleri -1 i gösteriyorsa program yemin cizilmedigini anlayacak
	// ve yemi cizecektir. 
    yemX=-1;yemY=yemX;
	
	// baslangıc yonu olarak yukarı girilmistir.
    yon = YUKARI;

    timer = new QTimer(this);
	
	
    connect(timer,SIGNAL(timeout()),this,SLOT(hareketEt()));
    connect(timer,SIGNAL(timeout()),this,SLOT(update()));
    connect(timer,SIGNAL(timeout()),this,SLOT(puanGuncelle()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::kayitDosyasiOku()
{
    QString path = QDir::currentPath() + QDir::separator() + "kayit.txt";
    if (!QFile::exists(path)) return;
    QFile file(path);
    file.open(QFile::ReadOnly);
    QDataStream in(&file);
    in >> easy >> normal >> hard >> highScoreEasy >> highScoreNormal >> highScoreHard;
}

void MainWindow::kayitDosyasinaYaz()
{
    QString path = QDir::currentPath() + QDir::separator() + "kayit.txt";
    QFile file(path);
    file.open(QFile::WriteOnly);
    QDataStream out(&file);
    out << easy << normal << hard << highScoreEasy << highScoreNormal << highScoreHard;
}


void MainWindow::paintEvent(QPaintEvent *e)
{
    arkaPlanCiz(e);
    if (ui->stack->currentIndex() == 1)
    {
        yilanGuncelle(e);
        yemCiz(e);
    }
}


// oyunun arka planını olusturur.
void MainWindow::arkaPlanCiz(QPaintEvent *e)
{
    
	// bu degerler programın stabil calismasi icin sabit tutulmustur.
    xKareSayisi = 32;
    yKareSayisi = 24;
    QPainter painter(this);
    int x = 0;
    int y = 0;
    painter.setBrush(Qt::black);
    for (int i = 0 , k = 0; k < xKareSayisi; i+= genislik , k++)
        for (int j = 0 , s = 0; s < yKareSayisi ; j+= uzunluk , s++)
        {
            painter.drawRect(x+i,y+j,genislik,uzunluk);
        }
}

// oyunu başlamadan once 5 karelik bir yılan vucudu olusturuldu.
void MainWindow::yilanOlustur()
{
    yilan.uzuvEkle(16,8);
    yilan.uzuvEkle(16,9);
    yilan.uzuvEkle(16,10);
    yilan.uzuvEkle(16,11);
    yilan.uzuvEkle(16,12);
}

// yilan boyutu guncellendi.
void MainWindow::yilanGuncelle(QPaintEvent *e)
{
    QPainter painter(this);
    Vucut* temp = yilan.bas;
    QImage _image(":/images/yellow");
    QImage image = _image.scaled(genislik,uzunluk,Qt::KeepAspectRatio);
    QImage _image2(":/images/red");
    QImage image2 = _image2.scaled(genislik,uzunluk,Qt::KeepAspectRatio);
    painter.drawImage(temp->x*genislik,temp->y*uzunluk,image2);
    temp = temp->sonrakiUzuv;
    while (temp != nullptr){
        painter.drawImage(temp->x*genislik,temp->y*uzunluk,image);
        temp = temp->sonrakiUzuv;
    }
}

// bu fonksiyon yilanın yemi yiyip yemedigini kontrol eder.
bool MainWindow::ustUsteMi(int yemX, int yemY)
{
    Vucut* temp = yilan.bas;
    while (temp){
        if (temp->x == yemX && temp->y == yemY) return true;
        temp = temp->sonrakiUzuv;
    }
    return false;
}

// bu fonksiyon bir yem cizer ve yemin yılanın vucuda denk gelip gelmedigini kontrol eder.
void MainWindow::yemCiz(QPaintEvent* e)
{
    if (yemX == -1 && yemY == -1)
    {
        int x = QRandomGenerator::global()->bounded(0,32);
        int y = QRandomGenerator::global()->bounded(0,24);
        while (ustUsteMi(x,y))
        {
            x = QRandomGenerator::global()->bounded(0,32);
            y = QRandomGenerator::global()->bounded(0,24);
        }
        yemX = x; yemY = y;
    }
    QPainter painter(this);
    QImage image(":/images/yem");
    QImage image2 = image.scaled(uzunluk,genislik,Qt::KeepAspectRatio);
    painter.drawImage(yemX*uzunluk,yemY*genislik,image2);
}

// klavyede hangi tusa basildigini algilar.
void MainWindow::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_Up)
        yon = YUKARI;
    if (e->key() == Qt::Key_Down)
        yon = ASAGI;
    if (e->key() == Qt::Key_Right)
        yon = SAG;
    if (e->key() == Qt::Key_Left)
        yon = SOL;
}

// bu fonksiyon oyundaki kaybetme mekanizmasını olusturur.
bool MainWindow::yanlisHareketKontrol(int x, int y)
{
    if (!yilan.bas) return false;
    int x2 = yilan.bas->x + x;
    int y2 = yilan.bas->y + y;
    Vucut* temp = yilan.bas->sonrakiUzuv;
    while (temp){
        if (temp->x == x2 && temp->y == y2) return true;
        temp = temp->sonrakiUzuv;
    }
    return false;
}

// yem yenilirse true değeri döner.
bool MainWindow::yemKontrol(int x, int y)
{
    if (!yilan.bas) return false;
    int x2 = yilan.bas->x + x;
    int y2 = yilan.bas->y + y;
    if (x2 == yemX && y2 == yemY) return true;
    return false;
}

// oyuncu yuksek puan yaparsa yuksek puanlar sekmesindeki değerler güncellenir.
void MainWindow::yuksekPuanKontrol(int puan)
{
    if (ui->radioButton->isChecked())
    {
        if (puan > easy)
        {
            highScoreEasy = tr("KOLAY : ") + QString::number(puan);
            easy = puan;
        }
    }
    else if (ui->radioButton_2->isChecked())
        {
            if (puan > normal)
                {
                    highScoreNormal = tr("NORMAL : ") + QString::number(puan);
                    normal = puan;
                }
        }
    else {
            if (puan > hard)
                {
                    highScoreHard = tr("ZOR : ") + QString::number(puan);
                    hard = puan;
                }
    }
}

// oyuncu yenildiginde bilgi mesajı gösterir 
void MainWindow::mesajGoster()
{
    QString text = tr("Puanınız : ");
    QMessageBox::information(this,"GAME OVER",text + QString::number(puan));
    yuksekPuanKontrol(puan);
    ui->stack->setCurrentIndex(0);
    yilan.sifirla();
    yon = YUKARI;
    puan = 0;
}

// Yılanı hareket ettirir. Ve yemin yenilip yenilmeyecegini kontrol eder. Aynı
// zamanda oyuncu oyunu kaybederse hata mesajı gosterir.
void MainWindow::hareketEt()
{
    if (yon == YUKARI)
    {
        if (yanlisHareketKontrol(0,-1))
        {
            mesajGoster();

        }
        else if (yemKontrol(0,-1))
        {
            puan += 10;
            Vucut* yeniBas = new Vucut(yemX,yemY);
            yeniBas->sonrakiUzuv = yilan.bas;
            yilan.bas = yeniBas;
            yemX = -1; yemY = yemX;
        }
        else yilan.hareketEttir(0,-1,xKareSayisi,yKareSayisi);
    }
    else if (yon == ASAGI)
    {
        if (yanlisHareketKontrol(0,1))
        {
            mesajGoster();

        }
        else if (yemKontrol(0,1))
        {
            puan += 10;
            Vucut* yeniBas = new Vucut(yemX,yemY);
            yeniBas->sonrakiUzuv = yilan.bas;
            yilan.bas = yeniBas;
            yemX = -1; yemY = yemX;
        }
        else yilan.hareketEttir(0,1,xKareSayisi,yKareSayisi);
    }
    else if (yon == SAG)
    {
        if (yanlisHareketKontrol(1,0))
        {
            mesajGoster();
        }
        else if (yemKontrol(1,0))
        {
            puan += 10;
            Vucut* yeniBas = new Vucut(yemX,yemY);
            yeniBas->sonrakiUzuv = yilan.bas;
            yilan.bas = yeniBas;
            yemX = -1; yemY = yemX;
        }
        else yilan.hareketEttir(1,0,xKareSayisi,yKareSayisi);
    }
    else
    {
        if (yanlisHareketKontrol(-1,0))
        {
            mesajGoster();
        }
        else if (yemKontrol(-1,0))
        {
            puan += 10;
            Vucut* yeniBas = new Vucut(yemX,yemY);
            yeniBas->sonrakiUzuv = yilan.bas;
            yilan.bas = yeniBas;
            yemX = -1; yemY = yemX;
        }
        else yilan.hareketEttir(-1,0,xKareSayisi,yKareSayisi);
    }
}

// Oyunu baslat butonuna basildiginda oyunu baslatir.
void MainWindow::on_pushButton_clicked()
{
    yilanOlustur();
    if (ui->radioButton->isChecked())
        timer->start(100);
    else if (ui->radioButton_2->isChecked())
        timer->start(50);
    else {
        timer->start(30);
    }
    ui->stack->setCurrentIndex(1);
}

// oyun penceresinin uzunluk ve genisligini ayarlar. 
// Bu degerlere gore bir oyun karesinin genislik ve 
// uzunlugunu gunceller.
void MainWindow::on_radioButton_4_clicked()
{
    genislik = 15;
    uzunluk = 15;
    setFixedSize(480,360);
}

void MainWindow::on_radioButton_5_clicked()
{
    genislik = 20;
    uzunluk = 20;
    setFixedSize(640,480);
}

void MainWindow::on_radioButton_6_clicked()
{
    genislik = 25;
    uzunluk = 25;
    setFixedSize(800,600);
}

// Oyundan cık butonuna basildiginda oyunun yuksek skorlarını "kayit.txt" adlı
// dosyaya kaydeder ve oyundan çıkar.
void MainWindow::on_pushButton_2_clicked()
{
    kayitDosyasinaYaz();
    close();
}

// Oyun oynarken sağ üste yazan puan yazısını gunceller.
void MainWindow::puanGuncelle()
{
    ui->label_4->setText(tr("Puan ") + QString::number(puan));

}

// Yüksek skorlar penceresini açar.
void MainWindow::on_pushButton_3_clicked()
{
    if (highScoreEasy == "") ui->label_easy->setText(tr("KOLAY : Bu Zorlukta oyun oynamadınız."));
    else ui->label_easy->setText(highScoreEasy);
    if (highScoreNormal == "") ui->label_normal->setText(tr("NORMAL : Bu Zorlukta oyun oynamadınız."));
    else ui->label_normal->setText(highScoreNormal);
    if (highScoreHard == "") ui->label_hard->setText(tr("ZOR : Bu Zorlukta oyun oynamadınız."));
    else ui->label_hard->setText(highScoreHard);
    ui->stack->setCurrentIndex(2);

}

// Yüksek skorlar penceresinden çıkar.
void MainWindow::on_pushButton_4_clicked()
{
     ui->stack->setCurrentIndex(0);
}
