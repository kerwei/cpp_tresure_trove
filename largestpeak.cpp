/*
    Given a series of stock prices, find the largest price increase during the period
*/
# include <array>
# include <iomanip>
# include <iostream>
# include <fstream>
# include <sstream>
# include <stdlib.h>
# include <string>
# include <vector>

using namespace std;


std::array<double, 3> getLargestPeak(double prices[], int length) {
    double trough = 0;
    double new_trough = 0;
    double peak = 0;
    double local_peak;
    double global_peak;

    double price_move[length-1];
    // Compute price differentials
    for (int i = 1; i < length; i++) {
        price_move[i-0] = prices[i] - prices[i-1];
    }

    // Locate the biggest price appreciation
    for (int i = 0; i < length; i++) {
        local_peak += price_move[i];

        if (local_peak > global_peak) {
            global_peak = local_peak;
            trough = new_trough;
            peak = i;
        }
        else if (local_peak < 0) {
            new_trough = i;
            local_peak = 0;
        }
    }

    return {global_peak, trough + 1, peak + 1};
}

std::vector<std::string> getNextLineAndSplitIntoTokens(std::istream& str)
{
    std::vector<std::string>   result;
    std::string                line;
    std::string                cell;

    std::getline(str, line);
    std::stringstream          lineStream(line);

    while(std::getline(lineStream, cell, ',')) {
        result.push_back(cell);
    }

    // This checks for a trailing comma with no data after it.
    if (!lineStream && cell.empty())
    {
        // If there was a trailing comma then add an empty element.
        result.push_back("");
    }
    return result;
}


int main() {
    std::string line;
    std::vector<std::string> str_prices;
    std::ifstream myfile ("/mnt/c/Users/kerwe/Downloads/9999.HK.csv");

    if (myfile.is_open()) {
        // Skip headers
        std::string nullline;
        std::getline(myfile, nullline);

        while (!myfile.eof()) {
            std::vector<std::string> rs = getNextLineAndSplitIntoTokens(myfile);
            str_prices.push_back(rs[4]);
        }

        myfile.close();
    }

    double prices[str_prices.size()];
    for (int i = 0; i < str_prices.size(); i++) {
        prices[i] = std::stod(str_prices[i]);
    }

    std::array<double, 3> res = getLargestPeak(prices, str_prices.size());
    std::cout << res[0] << std::setprecision(6) << std::endl;
    std::cout << res[1] << ", " << res[2] << std::endl;

    return 0;
}