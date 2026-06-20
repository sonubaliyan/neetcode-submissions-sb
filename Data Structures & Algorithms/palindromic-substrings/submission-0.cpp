class Solution {
public:
    int count = 0;

    // Expand from the center and count palindromes
    void expand(string& s, int left, int right) {

        // Keep expanding while:
        // 1. pointers are inside the string
        // 2. characters match
        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right]) {

            count++; // Found one palindrome

            left--;
            right++;
        }
    }

    int countSubstrings(string s) {

        for (int i = 0; i < s.size(); i++) {

            // Odd length palindrome
            // Example: "aba"
            expand(s, i, i);

            // Even length palindrome
            // Example: "abba"
            expand(s, i, i + 1);
        }

        return count;
    }
};
