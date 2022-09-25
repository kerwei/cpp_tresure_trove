/**
    You are given the heads of two sorted linked lists list1 and list2.
    Merge the two lists in a one sorted list. 

    Constraints:
        a. The number of nodes in both lists is in the range [0, 50].
        b. -100 <= Node.val <= 100
        c. Both list1 and list2 are sorted in non-decreasing order.
 **/
#include <iostream>

using namespace std;


template <class T, std::size_t N>
constexpr std::size_t size(const T (&array)[N]) noexcept {
    return N;
}


int* mergeTwoList(int* list1, int* list2, int* res, int i, int j) {
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


int main() {
    int arr_left[3] = {1, 2, 4};
    int arr_right[3] = {1, 3, 4};
    int i = size(arr_left);
    int j = size(arr_right);

    int res[i + j] = {};
    mergeTwoList(arr_left, arr_right, res, i, j);

    for (int k=0; k < i + j; k++) {
        std::cout << res[k] << " ";
    }

    std::cout << std::endl;

    return 0;
}