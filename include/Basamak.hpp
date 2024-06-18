#ifndef BASAMAK_HPP
#define BASAMAK_HPP
#include <sstream>
#include<iostream>
using namespace std;
/**
@file				Basamak.cpp
@description		Tek Yonlu Bagli Liste kullanip tam sayilar uzerinde cesitli fonksiyonlari kullanmak
#course				1.Ogretim B Grubu
#assignment			1.Odev
#author				Burak Coskun burakkcoskun@hotmail.com
*/
class Basamak {
public:
    int deger;
    Basamak* sonraki;
	Basamak* address;
    Basamak(int deger);
	string sonUc (void* adres) const;
	string sonUcBasamak;

};

#endif 