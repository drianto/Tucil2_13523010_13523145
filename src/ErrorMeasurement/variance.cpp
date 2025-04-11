#include <iostream>
#include <vector>
#include <cmath>
#include "../pixel.hpp"
#include "../calculation.hpp"

// double rataRata(const std::vector<Pixel>& blok, char color) {
//     double sum = 0;
//     for (int i = 0; i < blok.size(); i++) {
//         const Pixel& pixel = blok[i];
//         if (color == 'r') sum += pixel.r;
//         else if (color == 'g') sum += pixel.g;
//         else if (color == 'b') sum += pixel.b;
//     }
//     return sum / blok.size();
// }

double varians(const std::vector<Pixel>& blok, char color, double mean) {
    double sum = 0;
    for (int i = 0; i < blok.size(); i++) {
        const Pixel& pixel = blok[i];
		if (color == 'r'){
            sum += (pixel.r - mean) * (pixel.r - mean);
        }
        else if (color == 'g'){
            sum += (pixel.g - mean) * (pixel.g - mean);
        }
        else if (color == 'b'){
            sum += (pixel.b - mean) * (pixel.b - mean);
        }
    }
    return sum / blok.size();
}

double varianceError(const std::vector<Pixel>& blok) {
    double meanR = rataRata(blok, 'r');
    double meanG = rataRata(blok, 'g');
    double meanB = rataRata(blok, 'b');
    double varR = varians(blok, 'r', meanR);
    double varG = varians(blok, 'g', meanG);
    double varB = varians(blok, 'b', meanB);
    double error = (varR + varG + varB) / 3;
    return error;
}
