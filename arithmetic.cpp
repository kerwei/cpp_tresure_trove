#include <iostream>
#include <math.h>
#include <time.h>

using namespace std;


int randintoflen(int n) {
    int low{(int) pow(10, n-1)};

    return low + std::rand() % (int) (pow(10, n) - low) + 1;
}


int main(int argc, char* argv[]) {
    srand(time(NULL));

    int x{0}; 
    int y{0};
    int diff{1};
    int answer{0};

    int i{0};
    while (i < 2) {
        x = randintoflen(diff);
        y = randintoflen(diff);

        std::cout << x << " + " << y << std::endl;
        std::cin >> answer;

        if (x + y == answer) {
            std::cout << "correct" << std::endl;
        }
        else {
            std::cout << "wrong" << std::endl;
        }

        i++;
    }


    return 0;
}