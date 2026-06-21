#include <cstring>
class Solution {
public:
    int dp[101];
    int solve(int i, string &s, int n) {

        // Successfully decoded entire string
        if (i == n) {
            return 1;
        }

        // Cannot start a decoding with 0
        if (s[i] == '0') {
            return 0;
        }

        if (dp[i] != -1) return dp[i];

        // Option 1: Take current digit alone
        int ways = solve(i + 1, s, n);

        // Option 2: Take current digit and next digit together
        if (i + 1 < n &&
            (s[i] == '1' ||
             (s[i] == '2' && s[i + 1] <= '6'))) {

            ways += solve(i + 2, s, n);
        }

        return dp[i] = ways;
    }

    int numDecodings(string s) {
        memset(dp, -1, sizeof(dp));
        return solve(0, s, s.size());
    }
};