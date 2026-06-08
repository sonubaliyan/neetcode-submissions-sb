class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        // Left pointer of the sliding window
        int left = 0;

        // Stores the maximum length found so far
        int maxlen = 0;

        // Stores characters currently inside the window
        unordered_set<char> st;

        // Right pointer expands the window
        for (int right = 0; right < s.size(); right++) {

            // If the current character already exists in the window,
            // keep shrinking the window from the left until it is removed.
            while (st.find(s[right]) != st.end()) {

                // Remove the leftmost character from the set
                st.erase(s[left]);

                // Move the left pointer forward
                left++;
            }

            // Add the current character to the window
            st.insert(s[right]);

            // Calculate current window length and update maximum
            maxlen = max(maxlen, right - left + 1);
        }

        // Return the length of the longest substring
        // without repeating characters
        return maxlen;
    }
};
