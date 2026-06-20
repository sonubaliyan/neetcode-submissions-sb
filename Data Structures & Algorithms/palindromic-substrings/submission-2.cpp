class Solution {
public:
    int countSubstrings(string s) {

        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        int count = 0;

        // Length 1 substrings
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
            count++;
        }

        // Length 2 substrings
        for (int i = 0; i < n - 1; i++) {

            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                count++;
            }
        }

        // Length >= 3 substrings
        for (int len = 3; len <= n; len++) {

            for (int i = 0; i + len - 1 < n; i++) {

                int j = i + len - 1;

                if (s[i] == s[j] && dp[i + 1][j - 1]) {

                    dp[i][j] = true;
                    count++;
                }
            }
        }

        return count;
    }
};