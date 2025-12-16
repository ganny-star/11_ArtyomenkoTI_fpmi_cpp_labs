#include "palindrome.h"
#include <algorithm>
#include <cctype>

bool IsPalindrome(const int originalNumber) {
    int digit, reversed = 0;
    int number = originalNumber;
    while (number != 0) {
        digit = number % 10;
        reversed = reversed * 10 + digit;
        number = number / 10;
    }

    if (originalNumber == reversed) {
        return true;
    } else {
        return false;
    }

}
