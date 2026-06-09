class Solution {
public:
    string minWindow(string s, string t) {
      // Edge case
        if (s.size() < t.size())
            return "";

        // Stores required frequency of each character from t
        unordered_map<char, int> need;

        // Build frequency map for t
        for (char ch : t)
            need[ch]++;

        // Number of unique characters that must satisfy frequency
        int required = need.size();

        // Number of characters currently satisfying frequency
        int formed = 0;

        // Frequency of characters inside current window
        unordered_map<char, int> window;

        // Result variables
        int minLen = INT_MAX;
        int startIndex = 0;

        // Left pointer of sliding window
        int left = 0;

        // Expand window using right pointer
        for (int right = 0; right < s.size(); right++) {

            char ch = s[right];

            // Add current character into window
            window[ch]++;

            // If frequency becomes exactly equal,
            // one required character is satisfied
            if (need.count(ch) &&
                window[ch] == need[ch]) {

                formed++;
            }

            // Window is valid when all required chars are satisfied
            while (formed == required) {

                // Update minimum window
                int windowLen = right - left + 1;

                if (windowLen < minLen) {
                    minLen = windowLen;
                    startIndex = left;
                }

                // Character going out of window
                char leftChar = s[left];

                window[leftChar]--;

                // If removing breaks a requirement,
                // window becomes invalid
                if (need.count(leftChar) &&
                    window[leftChar] < need[leftChar]) {

                    formed--;
                }

                // Shrink further
                left++;
            }
        }

        // No valid window found
        if (minLen == INT_MAX)
            return "";

        // Return shortest valid substring
        return s.substr(startIndex, minLen);
    }
};
