#include "pixel.hpp"

Pixel::Pixel(int R, int G, int B) : r(R), g(G), b(B) {}

Pixel& Pixel::operator=(const Pixel& other) {
    if (this == &other) {
        return *this;
    }
    r = other.r;
    g = other.g;
    b = other.b;
    return *this;
}