class Solution {
public:
    vector<int> dp;

    bool solve(int idx, string& s, vector<string>& wordDict) {

        // Successfully segmented entire string
        if (idx == s.size())
            return true;

        // Already computed
        if (dp[idx] != -1)
            return dp[idx];

        for (string& word : wordDict) {

            int len = word.length();

            // Word doesn't fit
            if (idx + len > s.length())
                continue;

            // Check if word matches starting at idx
            if (s.substr(idx, len) == word) {

                if (solve(idx + len, s, wordDict))
                    return dp[idx] = true;
            }
        }

        return dp[idx] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        dp.resize(s.size(), -1);

        return solve(0, s, wordDict);
    }
};