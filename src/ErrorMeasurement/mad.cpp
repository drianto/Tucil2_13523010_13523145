#include <iostream>
#include <vector>
#include <cmath>
#include "../pixel.hpp"

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

double difference(const std::vector<Pixel>& blok, char channel, double mean) {
    double sum = 0;
    for (int i = 0; i < blok.size(); i++) {
        const Pixel& pixel = blok[i];
		if (channel == 'r'){
            sum += fabs(pixel.r - mean);
        }
        else if (channel == 'g'){
            sum += fabs(pixel.g - mean);
        }
        else if (channel == 'b'){
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
/*
//Testing
int main() {
    std::vector<Pixel> block;
	block.push_back(Pixel(255, 0, 0));
	block.push_back(Pixel(254, 1, 0));
	block.push_back(Pixel(253, 2, 0));
	block.push_back(Pixel(253, 2, 100));
    double error = madError(block);
    std::cout << "Error dalam blok: " << error << std::endl;
    return 0;
}
*/