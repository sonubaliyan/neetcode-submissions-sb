class Solution {
public:
    int count = 0;

    // Try to expand around a center and count all palindromes
    void expand(string& s, int left, int right) {

        // Example:
        // s = "acdca"
        //
        // left = 2, right = 2
        //
        // First palindrome: "d"
        // Then expand -> "cdc"
        // Then expand -> "acdca"

        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right]) {

            // Current substring s[left...right]
            // is a valid palindrome
            count++;

            // Expand outward
            left--;
            right++;
        }
    }

    int countSubstrings(string s) {

        // Consider every index as a possible center
        for (int i = 0; i < s.size(); i++) {

            // -------------------------
            // Odd length palindromes
            // -------------------------
            //
            // Center is a single character
            //
            // Example:
            // "aba"
            //   ^
            //
            // expand(i, i)
            //
            // First checks:
            // "b"
            //
            // Then:
            // "aba"
            //
            expand(s, i, i);

            // -------------------------
            // Even length palindromes
            // -------------------------
            //
            // Center lies between two chars
            //
            // Example:
            // "abba"
            //   ^^
            //
            // expand(i, i+1)
            //
            // First checks:
            // "bb"
            //
            // Then:
            // "abba"
            //
            expand(s, i, i + 1);
        }

        // Total palindromic substrings found
        return count;
    }
};