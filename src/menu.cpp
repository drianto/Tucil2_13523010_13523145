#include <iostream>

int choiceMeasurement;
double choiceThreshold;
double choiceBlockMinimum;

void inputMeasurement() {
    std::cout << "Pilih metode perhitungan error" << std::endl;
    std::cout << "1. Variance" << std::endl;
    std::cout << "2. Mean Absolute Deviation (MAD)" << std::endl;
    std::cout << "3. Max Pixel Difference" << std::endl;
    std::cout << "4. Entropy" << std::endl;
    std::cout << "Masukan nomor: ";
    std::cin >> choiceMeasurement;

    if (choiceMeasurement == 1) {
        std::cout << "Anda memilih Variance" << std::endl << std::endl;
    } else if (choiceMeasurement == 2) {
        std::cout << "Anda memilih Mean Absolute Deviation" << std::endl << std::endl; 
    } else if (choiceMeasurement == 3) {
        std::cout << "Anda memilih Max Pixel Difference" << std::endl << std::endl;
    } else if (choiceMeasurement == 4) {
        std::cout << "Anda memilih Entropy" << std::endl << std::endl << std::endl;
    } else {
        std::cout << "\nAngka tersebut tidak ada dalam pilihan, silahkan pilih lagi." << std::endl;
        inputMeasurement();
    }
}

void inputThreshold() {
    std::cout << "Masukan ambang batas: ";
    std::cin >> choiceThreshold;
    std::cout << std::endl;
}

void inputBlockMinimum() {
    std::cout << "Masukan ukuran blok minimum: ";
    std::cin >> choiceBlockMinimum;
    std::cout << std::endl;
}