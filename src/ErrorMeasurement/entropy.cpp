#include <iostream>
#include <vector>
#include <cmath>

struct Pixel {
    int r, g, b;
    Pixel(int R, int G, int B) : r(R), g(G), b(B) {}
};

int count(const std::vector<Pixel>& blok, char channel, int p){
    int hasil = 0;
    for (int i = 0; i < blok.size(); i++) {
        const Pixel& pixel = blok[i];
        if (channel == 'r' && pixel.r == p) hasil++;
        else if (channel == 'g' && pixel.g == p) hasil++;
        else if (channel == 'b' && pixel.b == p) hasil++;
    }
    return hasil;
}

double entropyR(const std::vector<Pixel>& blok){
    double total = 0;
    for (int i = 0; i < 256; i++){
        double jumlah = count(blok, 'r', i);
        if(jumlah != 0){
        	double prob = jumlah / blok.size();
        	total += prob * log(prob) / log(2);
		}
    }
    return -1 * total;
}

double entropyG(const std::vector<Pixel>& blok){
    double total = 0;
    for (int i = 0; i < 256; i++){
        double jumlah = count(blok, 'g', i);
        if(jumlah != 0){
        	double prob = jumlah / blok.size();
        	total += prob * log(prob) / log(2);
		}
    }
    return -1 * total;
}

double entropyB(const std::vector<Pixel>& blok){
    double total = 0;
    for (int i = 0; i < 256; i++){
        double jumlah = count(blok, 'b', i);
        if(jumlah != 0){
        	double prob = jumlah / blok.size();
        	total += prob * log(prob) / log(2);
		}
    }
    return -1 * total;
}

double entropyError(const std::vector<Pixel>& blok) {
    return (entropyR(blok) + entropyG(blok) + entropyB(blok))/3;
}

//Testing
int main() {
    std::vector<Pixel> block;
	block.push_back(Pixel(255, 0, 0));
	block.push_back(Pixel(254, 1, 0));
	block.push_back(Pixel(253, 2, 0));
	block.push_back(Pixel(253, 2, 100));
    block.push_back(Pixel(253, 2, 100));
	double error = entropyError(block);
    std::cout << "Error dalam blok: " << error << std::endl;
    return 0;
}
