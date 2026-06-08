class Solution {
public:
    int characterReplacement(string s, int k) {
        // Frequency of each uppercase character
        vector<int> freq(26, 0);

        int left = 0;

        // Stores the highest frequency character
        // in the current window
        int maxFreq = 0;

        // Stores the answer
        int maxLen = 0;

        // Expand the window using right pointer
        for (int right = 0; right < s.size(); right++) {

            // Add current character to frequency table
            freq[s[right] - 'A']++;

            // Update maximum frequency seen in the window
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            // Current window size
            int windowLen = right - left + 1;

            // If replacements needed exceed k,
            // shrink the window from the left
            while (windowLen - maxFreq > k) {

                freq[s[left] - 'A']--;

                left++;

                windowLen = right - left + 1;
            }

            // Update answer
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
