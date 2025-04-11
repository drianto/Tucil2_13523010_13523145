#include <iostream>

int choiceMeasurement;
double choiceThreshold;
double choiceBlockMinimum;

void inputMeasurement() {
    try {
        std::cout << "Pilih metode perhitungan error" << std::endl;
        std::cout << "1. Variance" << std::endl;
        std::cout << "2. Mean Absolute Deviation (MAD)" << std::endl;
        std::cout << "3. Max Pixel Difference" << std::endl;
        std::cout << "4. Entropy" << std::endl;
        std::cout << "Masukan nomor: ";
        std::cin >> choiceMeasurement;

        if (std::cin.fail()) {
            throw "Input harus berupa angka";
        }

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
    } catch (...) {
        std::cout << "Input harus berupa angka" << std::endl;
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        inputMeasurement();
    }
}

void inputThreshold() {
    std::cout << "Tentukan ambang batas" << std::endl;

    double minThreshold = 0;
    double maxThreshold = 0;

    if (choiceMeasurement == 1) {
        std::cout << "Ambang batas berada pada rentang 0 - 1000" << std::endl ;
        maxThreshold = 1000;
    } else if (choiceMeasurement == 2) {
        std::cout << "Ambang batas berada pada rentang 0 - 25" << std::endl;
        maxThreshold = 25;
    } else if (choiceMeasurement == 3) {
        std::cout << "Ambang batas berada pada rentang 0 - 50" << std::endl;
        maxThreshold = 50;
    } else if (choiceMeasurement == 4) {
        std::cout << "Ambang batas berada pada rentang 0 - 2" << std::endl;
        maxThreshold = 2;
    }

    bool valid = false;

    do {
        try {
            std::cout << "Masukan ambang batas: ";
            std::cin >> choiceThreshold;

            if (std::cin.fail()) {
                throw "Input harus berupa angka";
            }

            if (choiceThreshold >= minThreshold && choiceThreshold <= maxThreshold) {
                valid = true;
            } else {
                std::cout << "Ambang batas tidak valid. Silakan coba lagi." << std::endl;
            }
        } catch (...) {
            std::cout << "Input harus berpa angka" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    } while (!valid);

    std::cout << std::endl;
}

void inputBlockMinimum() {
    std::cout << "Masukan ukuran blok minimum: ";
    std::cin >> choiceBlockMinimum;
    std::cout << std::endl;
}