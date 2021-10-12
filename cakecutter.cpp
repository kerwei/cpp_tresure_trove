#define _USE_MATH_DEFINES

#include <array>
#include <iomanip>
#include <iostream>
#include <math.h>


double round(double var) 
{ 
    // 37.66666 * 100 =3766.66 
    // 3766.66 + .5 =3767.16    for rounding off value 
    // then type cast to int so value is 3767 
    // then divided by 100 so the value converted into 37.67 
    double value = (int)(var * 100 + .5); 
    return (double)value / 100; 
}


bool cutCake(double cake_area[], int L, int N, double Z) {
    int cutcount = 0;
    // Decide if N slices of size Z can be cut into Z slices
    for (int i = 0; i < L; i++) {
        cutcount += std::floor(cake_area[i] / Z);

        if (cutcount >= N) {
            return true;
        }
    }

    return false;
}


double cutEvenSize(double cake_radius[], int L, int N) {
    // Use binary search to determine the largest slice that can be cut out of the
    // given cakes into N equal slices

    // NOTE: Possible sizes range between 0.0 and and the full size of the largest cake
    double cake_area[L];
    double upper_bound = 0;
    for (int i = 0; i < L; i++) {
        cake_area[i] = M_PI * cake_radius[i] * cake_radius[i];

        if (cake_area[i] > upper_bound) {
            upper_bound = cake_area[i];
        }
    }

    // Start off with the middle size between the max and the min (min size is 0)
    double guess = upper_bound/2;
    double lower_bound = 0;

    while (round(upper_bound) > round(lower_bound)) {
        std::cout << guess << std::endl;
        bool enough = cutCake(cake_area, L, N, guess);

        if (enough) {
            // Try to increase the size of the cut
            lower_bound = guess;
        }
        else {
            upper_bound = guess;
        }
        guess = (lower_bound + upper_bound)/2;
    }

    return guess;
}


int main() {
    int Ncuts = 8;
    double cake_radius[5] = {1.5, 2.0, 2.5, 4.0, 6.0};

    double size = cutEvenSize(cake_radius, 5, Ncuts);
    std::cout << size << std::setprecision(4) << std::endl;

    return 0;
}