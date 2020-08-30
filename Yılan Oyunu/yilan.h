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
	
    // yılanın oyun karelerinin sınırlarını aşıp aşmadığını kontrol eder 
	// eğer aştıysa yılanı düzenler.
	void kontrol(Vucut* temp,int sinirX,int sinirY); 
    
	// oyuncu yandığıda yılanın vucudunu siler.
	void sifirla();
};

#endif // YILAN_H
