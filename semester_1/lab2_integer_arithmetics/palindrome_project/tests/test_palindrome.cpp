#include <gtest/gtest.h>
#include "palindrome.h"

TEST(PalindromeTest, IntegerPalindromes) {
    EXPECT_TRUE(IsPalindrome(121));
    EXPECT_TRUE(IsPalindrome(12321));
    EXPECT_TRUE(IsPalindrome(1));
    EXPECT_TRUE(IsPalindrome(99));
    EXPECT_TRUE(IsPalindrome(0));

    EXPECT_FALSE(IsPalindrome(123));
    EXPECT_FALSE(IsPalindrome(10));
}
