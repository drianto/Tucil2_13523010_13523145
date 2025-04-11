#ifndef CALCULATION_HPP
#define CALCULATION_HPP

#include <vector>
#include "pixel.hpp"

double rataRata(const std::vector<Pixel>& blok, char channel);
Pixel averageColor(const std::vector<Pixel>& blok);
void normalize(std::vector<Pixel>& blok);

#endif
