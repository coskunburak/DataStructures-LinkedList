#include "Dugum.hpp"

/**
@file				Dugum.hpp
@description		Tek Yonlu Bagli Liste kullanip tam sayilar uzerinde cesitli fonksiyonlari kullanmak
#course				1.Ogretim B Grubu
#assignment			1.Odev
#author				Burak Coskun burakkcoskun@hotmail.com
*/

Dugum::Dugum(Sayi* sayi) : sayi(sayi), sonraki(nullptr) {}

Dugum::~Dugum() {
    delete sayi;
}