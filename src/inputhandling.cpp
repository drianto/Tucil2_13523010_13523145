#include <iostream>
#include <string>
#include <filesystem>

std::string filePath;
bool isImageFormat(const std::string directory);

void inputFile() {
    std::getline(std::cin, filePath);
}

void checkInput() {
    while (true) {
        if (std::filesystem::exists(filePath) && isImageFormat(filePath)) {
            std::cout << "File ditemukan" << std::endl << std::endl;
            break;
        } else if (std::filesystem::exists(filePath) && !isImageFormat(filePath)) {
            std::cout << "File bukan merupakan format gambar (.jpg, .png, .jpeg)" << std::endl;
        } else {
            std::cout << "File tidak ditemukan" << std::endl << std::endl;
        }

        std::cout << "Masukan alamat gambar yang ingin dikompresi: " << std::endl;
        std::getline(std::cin, filePath); 
    }
}

bool isImageFormat(const std::string directory) {
    std::filesystem::path filePath(directory);
    std::string format = filePath.extension().string();

    return format == ".jpg" || format == ".png" || format == ".jpeg";
}

std::string checkOutput() {
    std::string outputPath;
    while (true) {
        std::cout << "Masukan alamat gambar hasil kompresi: " << std::endl;
        std::cin.ignore();
        std::getline(std::cin, outputPath);

        std::filesystem::path folderPath = std::filesystem::path(outputPath).parent_path();

        if (std::filesystem::exists(folderPath)) {
            return outputPath;
        } else {
            std::cout << "Folder tidak ditemukan. Pastikan folder sudah ada." << std::endl << std::endl;
        }
    }
}
