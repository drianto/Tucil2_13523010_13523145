#include <iostream>
#include <vector>
#include <cmath>

struct Pixel {
    int r, g, b;
    Pixel(int R, int G, int B) : r(R), g(G), b(B) {}
};

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

double varians(const std::vector<Pixel>& blok, char channel, double mean) {
    double sum = 0;
    for (int i = 0; i < blok.size(); i++) {
        const Pixel& pixel = blok[i];
		if (channel == 'r'){
            sum += (pixel.r - mean) * (pixel.r - mean);
        }
        else if (channel == 'g'){
            sum += (pixel.g - mean) * (pixel.g - mean);
        }
        else if (channel == 'b'){
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

/*
//Testing
int main() {
    std::vector<Pixel> block;
	block.push_back(Pixel(255, 0, 0));
	block.push_back(Pixel(254, 1, 0));
	block.push_back(Pixel(253, 2, 0));
	block.push_back(Pixel(253, 2, 100));
    double error = varianceError(block);
    std::cout << "Error dalam blok: " << error << std::endl;
    return 0;
}
*/