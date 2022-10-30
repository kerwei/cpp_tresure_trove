#include <bits/stdc++.h>
#include <iostream>
#include <limits>
#include <math.h>
#include <time.h>

using namespace std;


int randintoflen(int n) {
    int low{(int) pow(10, n-1)};

    return low + std::rand() % (int) (pow(10, n) - low) + 1;
}


int main(int argc, char* argv[]) {
    srand(time(NULL));

    // Set difficulty
    std::string sdiff{""};
    std::cout << "Enter the difficulty: (1) 1-digit (2) 2-digits ..." << std::endl;
    std::cin >> sdiff;

    // Set intensity (number of questions)
    std::string sintense{""};
    std::cout << "Enter the intensity: (1) 10 questions (2) 20 questions ..." << std::endl;
    std::cin >> sintense;

    int x{0}; 
    int y{0};
    int answer{0};
    int diff{stoi(sdiff)};
    int intense{stoi(sintense) * 10};

    int i{0};
    int res{0};

    time_t t_start = time(NULL);
    while (i < intense) {
        x = randintoflen(diff);
        y = randintoflen(diff);

        std::cout << x << " + " << y << std::endl;
        std::cin >> answer;

        if (x + y == answer) {
            std::cout << "correct" << std::endl;
            res++;
        }
        else {
            std::cout << "wrong" << std::endl;
        }

        i++;
    }

    long elapsed = time(NULL) - t_start;
    double speed = std::numeric_limits<double>::infinity();

    if (res > 0) {
        speed = (double) elapsed/res;
    }

    std::cout << "Elapsed: " << elapsed << " seconds" << std::endl;
    std::cout << "Score: " << res << "/" << intense << std::endl;
    std::cout << "Speed: " << fixed << setprecision(5) << speed << " seconds per hit" << std::endl;

    return 0;
}