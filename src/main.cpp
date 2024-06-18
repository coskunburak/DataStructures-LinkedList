#include "SayilarListesi.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

/**
@file				main.cpp
@description		Tek Yonlu Bagli Liste kullanip tam sayilar uzerinde cesitli fonksiyonlari kullanmak
#course				1.Ogretim B Grubu
#assignment			1.Odev
#author				Burak Coskun burakkcoskun@hotmail.com
*/
void dosyadanOkuVeEkle(const std::string& Sayilar, SayilarListesi& liste) {
    ifstream dosya(Sayilar);
    if (!dosya.is_open()) {
        cerr << "Dosya acilamadi!" << std::endl;
        return;
    }

    string satir;
    while (std::getline(dosya, satir)) {
        istringstream ss(satir);
        int sayi;
        while (ss >> sayi) {
            Sayi* yeniSayi = new Sayi();
            while (sayi > 0) {
                int basamak = sayi % 10;
                yeniSayi->basamakEkle(basamak);
                sayi /= 10;
            }
            liste.sayiEkle(yeniSayi);
        }
    }
}

int main() {
    SayilarListesi liste;
    dosyadanOkuVeEkle("Sayilar.txt", liste);

    std::cout << "SayilarListesi'nin Baslangic Durumu:\n";
    liste.yazdir();
    std::cout << "-------------------------------\n";

    int secim;
    do {
        std::cout << "Menu:\n"
                  << "1. Tek degerli dugumleri basa tasi\n"
                  << "2. Basamak dugumleri sondan basa yer degistir\n"
                  << "3. En buyuk sayiyi cikart\n"
                  << "4. Listeyi yazdir\n"
                  << "0. Cikis\n"
                  << "Seciminiz: ";
        std::cin >> secim;

        switch (secim) {
            case 1:
                liste.tekDegerDugumleriBasaTasi();
                cout << "Tek degerli dugumler basa tasindi:\n";
                liste.yazdir();
                std::cout << "-------------------------------\n";
                break;
            case 2:
                liste.basamaklariYerDegistir();
                cout << "Basamak Dugumleri Sondan Basa Yer Degistirdi:\n";
                liste.yazdir();
                cout << "-------------------------------\n";
                break;
            case 3:
                liste.enBuyuguCikart();
                cout << "En buyuk Sayi cikartildi:\n";
                liste.yazdir();
                cout << "-------------------------------\n";
                break;
            case 4:
                liste.yazdir();
                break;
            case 0:
                cout << "Programdan Cikiliyor.\n";
                break;
            default:
                cout << "Gecersiz secim. Lutfen tekrar deneyin.\n";
                break;
        }
    } while (secim != 0);

    return 0;
}