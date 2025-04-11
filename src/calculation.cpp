#include <vector>
#include "calculation.hpp"
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

void normalize(std::vector<Pixel>& blok) {
    Pixel avg = averageColor(blok);
    for (int i = 0; i < blok.size(); i++) {
        blok[i] = avg;
    }
}