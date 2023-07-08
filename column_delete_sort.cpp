/*
You are given an array of n strings strs, all of the same length. We may choose
any deletion indices, and we delete all the characters in those indices for 
each string. For example, if we have strs = ["abcdef","uvwxyz"] and deletion 
indices {0, 2, 3}, then the final array after deletions is ["bef", "vyz"].
Suppose we chose a set of deletion indices answer such that after deletions, 
the final array has its elements in lexicographic order 
(i.e., strs[0] <= strs[1] <= strs[2] <= ... <= strs[n - 1]). 
Return the minimum possible value of answer.length.

Input: strs = ["ca","bb","ac"]
Output: 1
Explanation: 
After deleting the first column, strs = ["a", "b", "c"].
Now strs is in lexicographic order (ie. strs[0] <= strs[1] <= strs[2]).
We require at least 1 deletion since initially strs was not in lexicographic 
order, so the answer is 1.

Example 2:

Input: strs = ["xc","yb","za"]
Output: 0
Explanation: 
strs is already in lexicographic order, so we do not need to delete anything.
Note that the rows of strs are not necessarily in lexicographic order:
i.e., it is NOT necessarily true that (strs[0][0] <= strs[0][1] <= ...)

Constraints:

    n == strs.length
    1 <= n <= 100
    1 <= strs[i].length <= 100
    strs[i] consists of lowercase English letters.

    a b c
    d e f
    x y z
*/
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include <string.h>

using namespace std;


int lower = static_cast<int>('a');
int upper = static_cast<int>('z');


bool is_lower_alphabet(const int int_str) {
    return (lower <= int_str <= upper);
    }

std::vector<int> get_common_denominators(const std::vector<int> &left, const std::vector<int> &right) {
    /* Return elements common to both left and right */
    int i = 0;
    int j = 0;
    std::vector<int> common;
    if (left.size() * right.size() == 0) {
        return std::vector<int> {};
    }

    while (i < left.size()) {
        if (left[i] == right[j]) {
            common.push_back(left[i]);
            i++;
            j++;
        }
        else if (left[i] > right[j]) {
            j++;
        }
        else {
            i++;
        }

        if (j >= right.size()) {
            break;
        }
    }

    return common;
}

std::vector<int> right_ge_left(const std::vector<int> &left, const std::vector<int> &right) {
    // Return the indices where the right array elements are 
    // greater or equal to the left. Right and left are guaranteed to have the
    // same length
    std::vector<int> idx{};
    for (int i=0; i<left.size(); i++) {
        if (right[i] >= left[i]) {
            idx.push_back(i);
        }
    }

    return idx;
}

std::vector<int> split_and_search(
    const std::vector<std::vector<int> > &mtx,
    const int left_idx, 
    const int right_idx) {
    // If the rightmost edge is unpaired, we return the values of the left
    if (right_idx - left_idx < 1) {
        return mtx[left_idx];
    }
    else if (right_idx - left_idx == 1) {
        return get_common_denominators(mtx[left_idx], mtx[right_idx]);
    }

    std::vector<int> left = split_and_search(mtx, left_idx, (left_idx + right_idx)/2);
    std::vector<int> right = split_and_search(mtx, ((left_idx + right_idx)/2) + 1, right_idx);

    return get_common_denominators(left, right);
}

void char_arr_to_intvect(std::vector<int> &container, const int ln, const char* str) {
    for (int i=0; i < ln; i++) {
        int int_str = static_cast<int>(*str);
        if (!is_lower_alphabet(int_str)) {
            throw runtime_error("Elements must contain alphabets only");
        }

        container[i] = int_str;
        str++;
    }
}

int main(int argc, char* argv[]) {
    // Validation - number of elements
    if (argc > 100) {
        throw runtime_error("Number of elements must be less than 100");
        return 1;
    }

    int ln = std::strlen(argv[1]);

    std::vector<int> row(ln, -1);
    std::vector<std::vector<int> > matrix(argc - 1, row);
    for (int i = 1; i < argc; i++) {
        // Validation: length of each element
        if (std::strlen(argv[i]) != ln) {
            throw runtime_error("All elements need to be of the same length");
            return 1;
        }

        // Convert to int array, implicit validation that each element contains only lower alphabets
        char_arr_to_intvect(matrix[i-1], ln, argv[i]);
    }

    // If the number of rows in mtx is odd, we pad the end to allow a balanced comparison
    if (matrix.size() % 2 != 0) {
        std::vector<int> lastrow = matrix.back();
        int last_max = *std::max_element(lastrow.begin(), lastrow.end());
        matrix.push_back(std::vector<int> (ln, last_max));
    }

    // Normalize to indices
    std::vector<std::vector<int> > matrix_idx;
    for (int i=0; i < matrix.size(); i += 2) {
        std::vector<int> idx = right_ge_left(matrix[i], matrix[i+1]);
        matrix_idx.push_back(idx);
    }

    // Search for the smallest common index denominator
    std::vector<int> idx = split_and_search(matrix_idx, 0, matrix_idx.size()-1);

    if (idx.empty()) {
        std::cout << ln << std::endl;
        return 0;
    }

    int min_idx = *std::min_element(idx.begin(), idx.end());

    std::cout << min_idx << std::endl;

    return 0;
}