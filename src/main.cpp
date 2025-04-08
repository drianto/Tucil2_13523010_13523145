#include <iostream>
#include "inputhandling.cpp"
#include "ErrorMeasurement/variance.cpp"
#include "ErrorMeasurement/mad.cpp"
#include "ErrorMeasurement/mpd.cpp"
#include "ErrorMeasurement/entropy.cpp"

int main() {
    std::cout << "Masukan alamat gambar yang ingin dikompresi: " << std::endl;
    input();
    checkInput();

    std::cout << "Masukan nomor metode perhitungan error: " << std::endl;
    std::cout << "1. Variance" << std::endl;
    std::cout << "2. Mean Absolute Deviation (MAD)" << std::endl;
    std::cout << "3. Max Pixel Difference" << std::endl;
    std::cout << "4. Entropy" << std::endl;

    std::cout << "Masukan ambang batas: " << std::endl;

    std::cout << "Masukan ukuran blok minimum: " << std::endl;

    std::cout << "Masukan target persentase kompresi" << std::endl;

    std::cout << "Masukan alamat gambar hasil kompresi: " << std::endl;

    return 0;
}