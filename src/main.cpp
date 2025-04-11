#include <iostream>
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

    // Hanya untuk mengetes, belum memasukkan input dari pengguna
    quadtree(blok, width, height, 1, 1000, 3000);

    std::cout << "Masukan alamat gambar hasil kompresi: " << std::endl;

    std::cin.ignore();
    std::string outputPath;
    std::getline(std::cin, outputPath);
    RGBToImage(blok, outputPath, height, width);

    return 0;
}