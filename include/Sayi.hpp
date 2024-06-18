// Sayi.hpp
#ifndef SAYI_HPP
#define SAYI_HPP

#include "Basamak.hpp"
#include<iostream>
using namespace std;
/**
@file				Sayi.hpp
@description		Tek Yonlu Bagli Liste kullanip tam sayilar uzerinde cesitli fonksiyonlari kullanmak
#course				1.Ogretim B Grubu
#assignment			1.Odev
#author				Burak Coskun burakkcoskun@hotmail.com
*/
class Sayi {
public:
    Basamak* basamak;

    Sayi();
    ~Sayi();
    void yazdir();
	void basamakEkle(int deger);
	void tamSayiYazdir() const;


};

#endif