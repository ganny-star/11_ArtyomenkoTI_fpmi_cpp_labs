#ifndef PALINDROME_H
#define PALINDROME_H

#include <string>

bool IsPalindrome(int number);
bool IsPalindrome(const std::string& str, bool ignoreCase = true, bool ignoreNonAlphanumeric = true);

#endif
