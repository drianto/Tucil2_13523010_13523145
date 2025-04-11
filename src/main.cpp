#include <iostream>
#include <chrono>
#include "compress.cpp"
#include "image.cpp"
#include "menu.cpp"
#include "pixel.hpp"

extern std::vector<Pixel> blok;
extern int width, height;

int main() {
    std::cout << "Masukan alamat gambar yang ingin dikompresi: " << std::endl;
    inputFile();
    checkInput();
    imageToRGB(filePath);

    // Pilih Error Measurement
    inputMeasurement();

    // Pilih ambang batas
    inputThreshold();

    // Pilih ukuran blok minimum
    inputBlockMinimum();

    auto start = std::chrono::high_resolution_clock::now();
    int simpul=0;
    int maxDepth=0;
    quadtree(blok, width, height, choiceMeasurement, choiceThreshold, choiceBlockMinimum, simpul, 0, maxDepth);
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Masukan alamat gambar hasil kompresi: " << std::endl;

    std::cin.ignore();
    std::string outputPath;
    std::getline(std::cin, outputPath);
    RGBToImage(blok, outputPath, height, width);

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Waktu eksekusi: " << duration.count() << "ms" << std::endl;

    return 0;
}