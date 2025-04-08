#include <iostream>
#include "ErrorMeasurement/variance.cpp"
#include "ErrorMeasurement/mad.cpp"
#include "ErrorMeasurement/mpd.cpp"
#include "ErrorMeasurement/entropy.cpp"
#include "image.cpp"
#include "menu.cpp"

int main() {
    std::cout << "Masukan alamat gambar yang ingin dikompresi: " << std::endl;
    inputFile();
    checkInput();
    imageToRGB();

    // Pilih Error Measurement
    inputMeasurement();

    // Pilih ambang batas
    inputThreshold();

    // Pilih ukuran blok minimum
    inputBlockMinimum();

    std::cout << "Masukan alamat gambar hasil kompresi: " << std::endl;

    return 0;
}