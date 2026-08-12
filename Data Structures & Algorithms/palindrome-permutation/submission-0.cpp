class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> counts;
        for (char c : s) {
            counts[c]++;
        }
        
        int oddCount = 0;
        for (auto const& [key, val] : counts) {
            if (val % 2 != 0) {
                oddCount++;
            }
        }
        
        return oddCount <= 1;
    }
};