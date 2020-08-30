#ifndef YILAN_H
#define YILAN_H

#include "vucut.h"

class Yilan
{
public:
    Yilan();
    Vucut* bas;
    Vucut* sonUzvuBul();
    void uzuvEkle(int x,int y);
    void hareketEttir(int x,int y,int sinirX,int sinirY);
    void kontrol(Vucut* temp,int sinirX,int sinirY);
    void sifirla();
};

#endif // YILAN_H
