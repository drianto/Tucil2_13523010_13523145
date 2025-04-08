#include <iostream>
#include <string>
#include <filesystem>

std::string filePath;
bool isImageFormat(const std::string directory);

void inputFile() {
    std::getline(std::cin, filePath);
}

void checkInput() {
    if (std::filesystem::exists(filePath) && isImageFormat(filePath)) {
        std::cout << "File ditemukan" << std::endl << std::endl;
    } else if (std::filesystem::exists(filePath) && !isImageFormat(filePath)) {
        std::cout << "File bukan merupakan format gambar" << std::endl << std::endl;
    } else {
        std::cout << "File tidak ditemukan" << std::endl << std::endl;
    }
}

bool isImageFormat(const std::string directory) {
    std::filesystem::path filePath(directory);
    std::string format = filePath.extension().string();

    return format == ".jpg" || format == ".png" || format == ".bmp" || format == ".jpeg";
}