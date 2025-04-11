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

Pixel averageColor(const std::vector<Pixel>& blok) {
    return Pixel(rataRata(blok, 'r'), rataRata(blok, 'g'), rataRata(blok, 'b'));
}

void normalize(std::vector<Pixel>& blok) {
    Pixel avg = averageColor(blok);
    for (int i = 0; i < blok.size(); i++) {
        blok[i] = avg;
    }
}

void quadtree(std::vector<Pixel>& blok, int width, int height, int errorMeasurement, double threshold, double minSize, int &simpul, int depth, int &maxDepth) {
    simpul++;
    if (depth > maxDepth) {
        maxDepth = depth;
    }

    double errorValue;
    if (errorMeasurement == 1) {
        errorValue = varianceError(blok);
    } else if (errorMeasurement == 2) {
        errorValue = madError(blok);
    } else if (errorMeasurement == 3) {
        errorValue = mpdError(blok);
    } else if (errorMeasurement == 4) {
        errorValue = entropyError(blok);
    }
    
    if (errorValue <= threshold || width * height / 4 < minSize) {
        normalize(blok);
        return;
    }

    bool widthEven = (width % 2 == 0);
    bool heightEven = (height % 2 == 0);
    int midX = width / 2;
    int midY = height / 2;
    int rightWidth = widthEven ? midX : midX + 1;
    int bottomHeight = heightEven ? midY : midY + 1;

    std::vector<Pixel> q1, q2, q3, q4;

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

    quadtree(q1, midX, midY, errorMeasurement, threshold, minSize, simpul, depth + 1, maxDepth);
    quadtree(q2, rightWidth, midY, errorMeasurement, threshold, minSize, simpul, depth + 1, maxDepth);
    quadtree(q3, midX, bottomHeight, errorMeasurement, threshold, minSize, simpul, depth + 1, maxDepth);
    quadtree(q4, rightWidth, bottomHeight, errorMeasurement, threshold, minSize, simpul, depth + 1, maxDepth);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = y * width + x;
            if (y < midY) {
                if (x < midX)
                    blok[index] = q1[y * midX + x];
                else
                    blok[index] = q2[y * rightWidth + (x - midX)];
            } else {
                if (x < midX)
                    blok[index] = q3[(y - midY) * midX + x];
                else
                    blok[index] = q4[(y - midY) * rightWidth + (x - midX)];
            }
        }
    }
}

