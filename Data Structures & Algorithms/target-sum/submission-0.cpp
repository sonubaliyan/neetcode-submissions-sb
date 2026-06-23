class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = 0;
        for (int x : nums) total += x;

        if (abs(target) > total) return 0;

        if ((total + target) % 2) return 0;

        int required = (total + target) / 2;

        vector<int> dp(required + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int s = required; s >= num; s--) {
                dp[s] += dp[s - num];
            }
        }

        return dp[required];
    }
};
