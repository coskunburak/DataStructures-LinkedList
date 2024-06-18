#ifndef DUGUM_HPP
#define DUGUM_HPP

#include "Sayi.hpp"

/**
@file				Dugum.hpp
@description		Tek Yonlu Bagli Liste kullanip tam sayilar uzerinde cesitli fonksiyonlari kullanmak
#course				1.Ogretim B Grubu
#assignment			1.Odev
#author				Burak Coskun burakkcoskun@hotmail.com
*/
class Dugum {
public:
    Sayi* sayi;
    Dugum* sonraki;
	Dugum* address;
    Dugum(Sayi* sayi);
    ~Dugum();
	    

};

#endif 