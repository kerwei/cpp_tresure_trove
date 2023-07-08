/**
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists in a one sorted list. 

    Constraints:
        a. The number of nodes in both lists is in the range [0, 50].
        b. -100 <= Node.val <= 100
        c. Both list1 and list2 are sorted in non-decreasing order.
 **/
#include <iostream>
#include <vector>

#include "cmdutils.h"

using namespace std;


template <class T, std::size_t N>
constexpr std::size_t size(const T (&array)[N]) noexcept {
    return N;
}


int* mergeTwoList(std::vector<int> list1, std::vector<int> list2, int* res) {
    int i = list1.size();
    int j = list1.size();

    while (i > 0 && j > 0) {
        if (list1[i - 1] >= list2[j - 1]) {
            res[i + j - 1] = list1[i - 1];
            i--;
        }
        else {
            res[i + j - 1] = list2[j - 1];
            j--;
        }
    }

    if (i == 0) {
        while (j > 0) {
            res[j - 1] = list2[j - 1];
            j--;
        }
    }
    else {
        while (i > 0) {
            res[i - 1] = list1[i - 1];
            i--;
        }
    }

    return res;
}


int main(int argc, char *argv[]) {
    // int arr_left[3] = {1, 2, 4};
    // int arr_right[3] = {1, 3, 4};

    std::vector<std::vector<std::string>> args;
    args = parselist(argc, argv, args);

    // Convert input string digits to ints
    std::vector<int> arr_left;
    for (int i=0; i < args[0].size(); i++) {
        arr_left.push_back(stoi(args[0][i]));
    }

    std::vector<int> arr_right;
    for (int i=0; i < args[1].size(); i++) {
        arr_right.push_back(stoi(args[1][i]));
    }

    int total_size = arr_left.size() + arr_right.size();
    int res[total_size];

    mergeTwoList(arr_left, arr_right, res);

    for (int k=0; k < total_size; k++) {
        std::cout << res[k] << " ";
    }

    std::cout << std::endl;

    return 0;
}