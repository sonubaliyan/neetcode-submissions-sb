class Solution {
public:

    vector<vector<string>> partition(string s) {

        // Stores all valid palindrome partitions
        vector<vector<string>> result;

        // Stores the current partition being built
        vector<string> currentPartition;

        // Start exploring from index 0
        backtrack(s, 0, currentPartition, result);

        return result;
    }

private:

    void backtrack(string& s,
                   int startIndex,
                   vector<string>& currentPartition,
                   vector<vector<string>>& result) {

        // Base Case:
        // We have processed the entire string
        if (startIndex == s.size()) {
            result.push_back(currentPartition);
            return;
        }

        // Try every possible substring starting at startIndex
        for (int endIndex = startIndex;
             endIndex < s.size();
             endIndex++) {

            // Check if substring s[startIndex...endIndex]
            // is a palindrome
            if (isPalindrome(s, startIndex, endIndex)) {

                // Extract the palindrome substring
                string currentSubstring =
                    s.substr(startIndex,
                             endIndex - startIndex + 1);

                // CHOOSE
                currentPartition.push_back(currentSubstring);

                // EXPLORE the remaining string
                backtrack(s,
                          endIndex + 1,
                          currentPartition,
                          result);

                // UNDO (Backtrack)
                currentPartition.pop_back();
            }
        }
    }

    bool isPalindrome(string& s, int left, int right) {

        // Compare characters from both ends
        while (left < right) {

            if (s[left] != s[right]) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};