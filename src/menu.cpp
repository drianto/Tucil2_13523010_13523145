#include <iostream>

int choiceMeasurement;
int choiceThreshold;
int choiceBlockMinimum;

void inputMeasurement() {
    std::cout << "Pilih metode perhitungan error" << std::endl;
    std::cout << "1. Variance" << std::endl;
    std::cout << "2. Mean Absolute Deviation (MAD)" << std::endl;
    std::cout << "3. Max Pixel Difference" << std::endl;
    std::cout << "4. Entropy" << std::endl;
    std::cout << "Masukan nomor: ";
    std::cin >> choiceMeasurement;

    if (choiceMeasurement == 1) {
        std::cout << "Ini Variance" << std::endl;
    } else if (choiceMeasurement == 2) {
        std::cout << "Ini MAD" << std::endl; 
    } else if (choiceMeasurement == 3) {
        std::cout << "Ini MPD" << std::endl;
    } else if (choiceMeasurement == 4) {
        std::cout << "Ini Entropy" << std::endl;
    } else {
        std::cout << "\nAngka tersebut tidak ada dalam pilihan, silahkan pilih lagi." << std::endl;
        inputMeasurement();
    }
}

void inputThreshold() {
    std::cout << "Masukan ambang batas: ";
    std::cin >> choiceThreshold;
}

void inputBlockMinimum() {
    std::cout << "Masukan ukuran blok minimum: ";
    std::cin >> choiceBlockMinimum;
}