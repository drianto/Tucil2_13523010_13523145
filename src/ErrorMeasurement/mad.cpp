#include <iostream>
#include <vector>
#include <cmath>
#include "../pixel.hpp"
#include "../calculation.hpp"

double difference(const std::vector<Pixel>& blok, char color, double mean) {
    double sum = 0;
    for (int i = 0; i < blok.size(); i++) {
        const Pixel& pixel = blok[i];
		if (color == 'r'){
            sum += fabs(pixel.r - mean);
        }
        else if (color == 'g'){
            sum += fabs(pixel.g - mean);
        }
        else if (color == 'b'){
            sum += fabs(pixel.b - mean);
        }
    }
    return sum / blok.size();
}

double madError(const std::vector<Pixel>& blok) {
    double meanR = rataRata(blok, 'r');
    double meanG = rataRata(blok, 'g');
    double meanB = rataRata(blok, 'b');
    double varR = difference(blok, 'r', meanR);
    double varG = difference(blok, 'g', meanG);
    double varB = difference(blok, 'b', meanB);
    double error = (varR + varG + varB) / 3;
    return error;
}