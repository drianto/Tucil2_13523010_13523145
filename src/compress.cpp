#include <iostream>
#include <vector>
#include "pixel.hpp"
#include "calculation.hpp"
#include "ErrorMeasurement/variance.cpp"
#include "ErrorMeasurement/mad.cpp"
#include "ErrorMeasurement/mpd.cpp"
#include "ErrorMeasurement/entropy.cpp"

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

void quadtree(std::vector<Pixel>& blok, int width, int height, int errorMeasurement, double threshold, int minSize) {
    double errorValue;
    if(errorMeasurement == 1){
        errorValue = varianceError(blok);
    }else if(errorMeasurement == 2){
        errorValue = madError(blok);
    }else if(errorMeasurement == 3){
        errorValue = mpdError(blok);
    }else if(errorMeasurement == 4){
        errorValue = entropyError(blok);
    }
    if(errorValue <= threshold || width * height / 4 < minSize){
        normalize(blok);
        return;
    }
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
    quadtree(q1, midX, midY, errorMeasurement, threshold, minSize);
    quadtree(q2, midX, midY, errorMeasurement, threshold, minSize);
    quadtree(q3, midX, midY, errorMeasurement, threshold, minSize);
    quadtree(q4, midX, midY, errorMeasurement, threshold, minSize);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            if (y < midY) {
                if (x < midX)
                    blok[index] = q1[y * midX + x];
                else
                    blok[index] = q2[y * midX + (x - midX)];
            } else {
                if (x < midX)
                    blok[index] = q3[(y - midY) * midX + x];
                else
                    blok[index] = q4[(y - midY) * midX + (x - midX)];
            }
        }
    }
}
