class Solution {
public:

    vector<vector<int>> dp;

    int solve(int i, int j, string& text1, string& text2) {
        
        // One string finished
        if (i == text1.size() ||
            j == text2.size()) {
            return 0;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (text1[i] == text2[j]) {

            return dp[i][j] = 1 + solve(i + 1, j + 1, text1, text2);
        }

        // Characters don't match
        return dp[i][j] = max( solve(i + 1, j, text1, text2), solve(i, j + 1, text1, text2));
    }

    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.length();
        int n = text2.length();

        dp.resize(m, vector<int>(n, -1));

        return solve(0, 0, text1, text2);
    }
};
