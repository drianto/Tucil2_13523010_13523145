#include <iostream>
#include <vector>
#include "ErrorMeasurement/variance.cpp"
#include "ErrorMeasurement/mad.cpp"
#include "ErrorMeasurement/mpd.cpp"
#include "ErrorMeasurement/entropy.cpp"
#include "pixel.hpp"

double rataRata(const std::vector<Pixel>& blok, char channel) {
    double sum = 0;
    for (int i = 0; i < blok.size(); i++) {
        const Pixel& pixel = blok[i];
        if (channel == 'r') sum += pixel.r;
        else if (channel == 'g') sum += pixel.g;
        else if (channel == 'b') sum += pixel.b;
    }
    return sum / blok.size();
}

Pixel averageColor(const std::vector<Pixel>& blok){
    return Pixel(rataRata(blok,'r'), rataRata(blok,'g'), rataRata(blok,'b'));
}

void normalize(const std::vector<Pixel>& blok) {
    Pixel avg = averageColor(blok);
    for (int i = 0; i < blok.size(); i++) {
        blok[i] = Pixel;
    }
}

void split(const std::vector<Pixel>& blok, int width, int height) {
    int midX = width / 2;
    int midY = height / 2;
    std::vector<Pixel> q1;
    std::vector<Pixel> q2;
    std::vector<Pixel> q3;
    std::vector<Pixel> q4;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            if (y < midY) {
                if (x < midX)
                    q1.push_back(blok[index]);
                else
                    q2.push_back(blok[index]);
            } else {
                if (x < midX)
                    q3.push_back(blok[index]);
                else
                    q4.push_back(blok[index]);
            }
        }
    }
    /*
    CEK SETIAP KUADRAN UDH MEMENUHI SYARAT ATAU BELUM
    KALO BELUM TAMBAHIN REKURSI
    */
}
