
/**
@file				Sayi.hpp
@description		Tek Yonlu Bagli Liste kullanip tam sayilar uzerinde cesitli fonksiyonlari kullanmak
#course				1.Ogretim B Grubu
#assignment			1.Odev
#author				Burak Coskun burakkcoskun@hotmail.com
*/
#include "Sayi.hpp"
#include <iostream>
Sayi::Sayi() : basamak(nullptr) {}

Sayi::~Sayi() {
    Basamak* gec = basamak;
    while (gec) {
        Basamak* temp = gec;
        gec = gec->sonraki;
        delete temp;
    }
}

void Sayi::yazdir() {
    Basamak* current = basamak;
    while (current) {
        cout << current->deger << " ";
        current = current->sonraki;
    }
    cout << std::endl;
}
void Sayi::tamSayiYazdir() const {
    Basamak* current = basamak;
    while (current) {
        cout << current->deger;
        current = current->sonraki;
    }
}
void Sayi::basamakEkle(int deger) {
    Basamak* yeniBasamak = new Basamak(deger);
    yeniBasamak->sonraki = basamak;
    basamak = yeniBasamak;
}