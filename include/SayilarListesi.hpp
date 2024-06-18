#ifndef SAYILARLISTESI_HPP
#define SAYILARLISTESI_HPP

#include "Dugum.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
/**
@file				SayilarListesi.hpp
@description		Tek Yonlu Bagli Liste kullanip tam sayilar uzerinde cesitli fonksiyonlari kullanmak
#course				1.Ogretim B Grubu
#assignment			1.Odev
#author				Burak Coskun burakkcoskun@hotmail.com
*/
class SayilarListesi {
public:
    Dugum* baslangic;
    SayilarListesi();
    ~SayilarListesi(); 

	void sayiEkle(Sayi* sayi);
    void yazdir();
	void tekDegerDugumleriBasaTasi();
	void enBuyuguCikart();
    void basamaklariYerDegistir();
	string sonUcBasamak (void* adres) const;
	int basamakSayisi(int sayi) const;


};

#endif 