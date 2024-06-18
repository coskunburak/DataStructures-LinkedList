/**
@file				SayilarListesi.cpp
@description		Tek Yonlu Bagli Liste kullanip tam sayilar uzerinde cesitli fonksiyonlari kullanmak
#course				1.Ogretim B Grubu
#assignment			1.Odev
#author				Burak Coskun burakkcoskun@hotmail.com
*/
#include "SayilarListesi.hpp"
#include <iostream>
#include <iomanip>
SayilarListesi::SayilarListesi() : baslangic(nullptr) {}

SayilarListesi::~SayilarListesi() {
    Dugum* current = baslangic;
    while (current) {
        Dugum* temp = current;
        current = current->sonraki;
        delete temp;
    }
}

void SayilarListesi::sayiEkle(Sayi* sayi) {
    Dugum* yeniDugum = new Dugum(sayi);
    yeniDugum->sonraki = baslangic;
    baslangic = yeniDugum;
}

int SayilarListesi::basamakSayisi(int sayi) const {
    int basamaklar = 0;

    if (sayi == 0) {
        return 1; // Sıfır tek basamaklıdır
    }

    while (sayi != 0) {
        sayi /= 10;
        basamaklar++;
    }

    return basamaklar;
}
string SayilarListesi::sonUcBasamak(void* adres) const{
    // Düğüm adresini stringe dönüştür
    ostringstream stream;
    stream << adres;
    string adresString = stream.str();

    // Eğer adresString'in uzunluğu 3'ten küçükse, önünde sıfır ekleyelim
    while (adresString.length() < 3) {
        adresString = "0" + adresString;
    }

    // Adresin son üç karakterini döndür
    return adresString.substr(adresString.length() - 3);
}
void SayilarListesi::yazdir() {
    Dugum* current = baslangic;

    while (current) {
        cout << "###############\t\t";

        Basamak* yildizSayi = current->sayi->basamak;
        while (yildizSayi) {
            cout << "*******  ";
            yildizSayi = yildizSayi->sonraki;
        }
        cout << endl;

        cout << "#";
        cout << setw(10) << current << "#\t\t";

        Basamak* adresSay = current->sayi->basamak;
        while (adresSay) {
            cout << "*  " << setw(3) << right << sonUcBasamak(adresSay) << "*  ";
            adresSay = adresSay->sonraki;
        }
        cout << endl;

        cout << "#-------------#\t\t";
        Basamak* yildizSayi3 = current->sayi->basamak;
        while (yildizSayi3) {
            cout << "*******  ";
            yildizSayi3 = yildizSayi3->sonraki;
        }
        cout << endl;

        cout << "#       ";
        current->sayi->tamSayiYazdir();
        cout << "#\t\t";

        Basamak* basamak = current->sayi->basamak;
        while (basamak) {
            cout << "*    " << basamak->deger << "*  ";
            basamak = basamak->sonraki;
        }
        cout << endl;

        cout << "###############\t\t";
        Basamak* yildizSayi2 = current->sayi->basamak;
        while (yildizSayi2) {
            cout << "*******  ";
            yildizSayi2 = yildizSayi2->sonraki;
        }
        cout << endl;

        current = current->sonraki;
        cout << endl << endl;
    }
}
void SayilarListesi::tekDegerDugumleriBasaTasi() {
    Dugum* simdiki = baslangic;

    while (simdiki) {
        Basamak* onceki = nullptr;
        Basamak* simdikiBasamak = simdiki->sayi->basamak;
        Basamak* basaEklenecek = nullptr;

        while (simdikiBasamak) {
            Basamak* sonraki = simdikiBasamak->sonraki;

            if (simdikiBasamak->deger % 2 == 1) {
                // Tek değerli basamağı listeden çıkar
                if (onceki) {
                    onceki->sonraki = sonraki;
                } else {
                    simdiki->sayi->basamak = sonraki;
                }

                // Çıkartılan tek değerli basamağı başa ekle
                simdikiBasamak->sonraki = basaEklenecek;
                basaEklenecek = simdikiBasamak;

                // sonUcBasamak değerlerini güncelle
                string sonUcBasamakDegeri = sonUcBasamak(simdiki);
                simdikiBasamak->sonUcBasamak = sonUcBasamak(basaEklenecek);

            } else {
                onceki = simdikiBasamak;
            }

            simdikiBasamak = sonraki;
        }

        // Başa eklenen basamakları listenin başına yerleştir
        simdikiBasamak = basaEklenecek;
        if (simdikiBasamak) {
            while (simdikiBasamak->sonraki) {
                simdikiBasamak = simdikiBasamak->sonraki;
            }
            simdikiBasamak->sonraki = simdiki->sayi->basamak;
            simdiki->sayi->basamak = basaEklenecek;
        }

        simdiki = simdiki->sonraki;
    }
}


	void SayilarListesi::basamaklariYerDegistir() {
		Dugum* simdiki = baslangic;
		
		while (simdiki) {
			Basamak* oncekiBasamak = nullptr;
			Basamak* simdikiBasamak = simdiki->sayi->basamak;

			
			// Basamakları yer değiştir
			while (simdikiBasamak) {
				Basamak* sonrakiBasamak = simdikiBasamak->sonraki;
				simdikiBasamak->sonraki = oncekiBasamak;
				oncekiBasamak = simdikiBasamak;
				simdikiBasamak = sonrakiBasamak;

			}
			
			simdiki->sayi->basamak = oncekiBasamak;
			
			simdiki = simdiki->sonraki;
		}
	}

void SayilarListesi::enBuyuguCikart() {
    Dugum* simdiki = baslangic;

    while (simdiki) {
        Basamak* oncekiBasamak = nullptr;
        Basamak* simdikiBasamak = simdiki->sayi->basamak;
        Basamak* enBuyukBasamak = nullptr;
        Basamak* oncekiEnBuyukBasamak = nullptr;

        while (simdikiBasamak) {
            if (!enBuyukBasamak || simdikiBasamak->deger > enBuyukBasamak->deger) {
                enBuyukBasamak = simdikiBasamak;
                oncekiEnBuyukBasamak = oncekiBasamak;
            }
            oncekiBasamak = simdikiBasamak;
            simdikiBasamak = simdikiBasamak->sonraki;
        }

        if (enBuyukBasamak) {
            
            if (oncekiEnBuyukBasamak) {
                oncekiEnBuyukBasamak->sonraki = enBuyukBasamak->sonraki;
            } else {
                simdiki->sayi->basamak = enBuyukBasamak->sonraki;
            }

  
            if (enBuyukBasamak->sonraki != nullptr && enBuyukBasamak->sonraki->sonraki != nullptr && enBuyukBasamak->sonraki->sonraki->sonraki != nullptr) {
                enBuyukBasamak->sonUcBasamak = sonUcBasamak(enBuyukBasamak->sonraki->sonraki->sonraki);
            }

            delete enBuyukBasamak; 
        }

        simdiki = simdiki->sonraki;
    }
}


	
	