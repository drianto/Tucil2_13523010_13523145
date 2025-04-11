#include <iostream>
#include <vector>
#include <cmath>
#include "../pixel.hpp"
#include "../calculation.hpp"

double mpdError(const std::vector<Pixel>& blok) {
    double maksR;
    double maksG;
    double maksB;
    double minR;
    double minG;
    double minB;
    for (int i = 0; i < blok.size(); i++){
        const Pixel& pixel = blok[i];
        if(i==0){
            maksR = pixel.r;
            maksG = pixel.g;
            maksB = pixel.b;
            minR = pixel.r;
            minG = pixel.g;
            minB = pixel.b;
        }else{
            if(pixel.r > maksR){
                maksR = pixel.r;
            }
            if(pixel.r < minR){
                minR = pixel.r;
            }
            if(pixel.g > maksG){
                maksG = pixel.g;
            }
            if(pixel.g < minG){
                minG = pixel.g;
            }
            if(pixel.b > maksB){
                maksB = pixel.b;
            }
            if(pixel.b < minB){
                minB = pixel.b;
            }
        }
    }
    double error = (maksR + maksG + maksB - minR - minG - minB)/3;
    //std::cout << "Error dalam blok: " << error << std::endl;
    return error;
}