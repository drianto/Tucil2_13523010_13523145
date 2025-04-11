#ifndef PIXEL_HPP
#define PIXEL_HPP

struct Pixel {
    int r, g, b;
    Pixel(int R, int G, int B);
    Pixel& operator=(const Pixel& other);
};

#endif
