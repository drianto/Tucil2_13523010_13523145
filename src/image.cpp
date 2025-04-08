#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include "inputhandling.cpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void imageToRGB() {
    int width, height, channels;

    unsigned char* image = stbi_load(filePath.c_str(), &width, &height, &channels, 3);

    if (!image) {
        std::cerr << "Gagal membuka gambar \n";
        return;
    }

    std::vector<std::vector<std::tuple<int, int, int>>> rgbMatrix(height, std::vector<std::tuple<int, int, int>>(width));

    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            int idx = (y * width + x) * 3;
            int r = image[idx];
            int g = image[idx + 1];
            int b = image[idx + 2];
    
            rgbMatrix[y][x] = std::make_tuple(r, g, b);
        }
    }    

    stbi_image_free(image);
}
