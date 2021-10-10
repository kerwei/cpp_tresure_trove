#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

bool IsPalindrome(string text) {
    int n = text.length();
    int mid = n / 2;
    string left_string = text.substr(0, mid);

    // If length of text is odd, remove the middle character
    if (n % 2 == 1) {
        mid ++;
    }

    string right_string = text.substr(mid, n);
    reverse(right_string.begin(), right_string.end());

    return left_string.compare(right_string) == 0;
}


int main() {
    bool res = IsPalindrome("aabaa");
    cout << res;
    return 0;
}