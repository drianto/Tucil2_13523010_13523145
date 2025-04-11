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
    uintmax_t inputSize = getFileSize(filePath);
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

    std::string outputPath = checkOutput();
    RGBToImage(blok, outputPath, height, width);
    uintmax_t outputSize = getFileSize(outputPath);

    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << "Waktu eksekusi: " << duration.count() << "ms" << std::endl;
    std::cout << "Ukuran file awal: " << inputSize/1024 << "kb" << std::endl;
    std::cout << "Ukuran file akhir: " << outputSize/1024 << "kb" << std::endl;
    std::cout << "Besar kompresi: " << (inputSize - outputSize) * 100 / inputSize << "%" << std::endl;
    std::cout << "Jumlah simpul: " << simpul << std::endl;
    std::cout << "Kedalaman pohon: " << maxDepth << std::endl;
    return 0;
}