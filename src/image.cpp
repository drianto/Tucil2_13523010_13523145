#include <iostream>
#include <fstream>
#include <vector>
#include <tuple>
#include "inputhandling.cpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.hpp"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.hpp"

void imageToRGB(std::string& filePath) {
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

void RGBToImage(std::vector<Pixel>& blok, std::string& outputPath, int height, int width) {
    std::vector<unsigned char> imageData(width * height * 3);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int idx = (y * width + x) * 3;
            const Pixel& pixel = blok[y * width + x];
            imageData[idx] = static_cast<unsigned char>(pixel.r);
            imageData[idx + 1] = static_cast<unsigned char>(pixel.g);
            imageData[idx + 2] = static_cast<unsigned char>(pixel.b);
        }
    }
    if (stbi_write_jpg(outputPath.c_str(), width, height, 3, imageData.data(), 100)) {
        std::cout << "Gambar berhasil disimpan ke: " << outputPath << std::endl;
    } else {
        std::cerr << "Gagal menyimpan gambar." << std::endl;
    }
}