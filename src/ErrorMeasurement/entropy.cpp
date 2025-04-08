#include <iostream>
#include <vector>
#include <cmath>
#include "../pixel.hpp"

int count(const std::vector<Pixel>& blok, char color, int p){
    int hasil = 0;
    for (int i = 0; i < blok.size(); i++) {
        const Pixel& pixel = blok[i];
        if (color == 'r' && pixel.r == p) hasil++;
        else if (color == 'g' && pixel.g == p) hasil++;
        else if (color == 'b' && pixel.b == p) hasil++;
    }
    return hasil;
}

double entropyR(const std::vector<Pixel>& blok){
    double total = 0;
    for (int i = 0; i < 256; i++){
        double jumlah = count(blok, 'r', i);
        if(jumlah != 0){
        	double prob = jumlah / blok.size();
        	total += prob * log(prob) / log(2);
		}
    }
    return -1 * total;
}

double entropyG(const std::vector<Pixel>& blok){
    double total = 0;
    for (int i = 0; i < 256; i++){
        double jumlah = count(blok, 'g', i);
        if(jumlah != 0){
        	double prob = jumlah / blok.size();
        	total += prob * log(prob) / log(2);
		}
    }
    return -1 * total;
}

double entropyB(const std::vector<Pixel>& blok){
    double total = 0;
    for (int i = 0; i < 256; i++){
        double jumlah = count(blok, 'b', i);
        if(jumlah != 0){
        	double prob = jumlah / blok.size();
        	total += prob * log(prob) / log(2);
		}
    }
    return -1 * total;
}

double entropyError(const std::vector<Pixel>& blok) {
    return (entropyR(blok) + entropyG(blok) + entropyB(blok))/3;
}
