class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        int n = s.size();
        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            // Treat s[i] as an extra character
            dp[i] = 1 + dp[i + 1];

            string curr = "";

            // Try every substring starting at i
            for (int j = i; j < n; j++) {
                curr += s[j];

                if (dict.count(curr)) {
                    dp[i] = min(dp[i], dp[j + 1]);
                }
            }
        }

        return dp[0];
    }
        
};