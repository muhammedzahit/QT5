#include "yilan.h"

Yilan::Yilan()

{
    bas = nullptr;
}

Vucut *Yilan::sonUzvuBul()
{
    Vucut* temp = bas;
    while (temp->sonrakiUzuv) {
        temp = temp->sonrakiUzuv;
    }
    return temp;
}

void Yilan::uzuvEkle(int x, int y)
{
    if (!bas)
    {
        Vucut* yeniUzuv = new Vucut(x,y);
        bas = yeniUzuv;
    }
    else
    {
        Vucut* temp = sonUzvuBul();
        temp->sonrakiUzuv = new Vucut(x,y);
    }
}

void Yilan::kontrol(Vucut *temp, int sinirX, int sinirY)
{
    if (temp->x < 0) temp->x = sinirX-1;
    else if (temp->x == sinirX) temp->x = 0;
    if (temp->y < 0) temp->y = sinirY-1;
    else if (temp->y == sinirY) temp->y = 0;
}

void Yilan::sifirla()
{
    Vucut* temp = bas;
    Vucut* temp2;
    while(temp)
    {
        temp2 = temp->sonrakiUzuv;
        delete temp;
        temp = temp2;
    }
    bas = nullptr;
}

void Yilan::hareketEttir(int x, int y, int sinirX, int sinirY)
{
    if (!bas) return;
    Vucut* temp = bas;
    int tempX = temp->x;
    int tempY = temp->y;
    temp->x += x;
    temp->y += y;
    kontrol(temp,sinirX,sinirY);
    temp = temp->sonrakiUzuv;
    while (temp) {
        int tempX2 = temp->x;
        int tempY2 = temp->y;
        temp->x = tempX;
        temp->y = tempY;
        tempX = tempX2;
        tempY = tempY2;
        temp = temp->sonrakiUzuv;
    }
}



