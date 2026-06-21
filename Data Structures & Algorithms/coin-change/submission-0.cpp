class Solution {
public:

    // dp[amount] = minimum coins needed
    // to make this amount
    vector<int> dp;

    int solve(vector<int>& coins, int amount) {

        // Successfully formed the amount
        // No more coins are needed
        if (amount == 0)
            return 0;

        // Invalid path
        // We overshot the amount
        if (amount < 0)
            return 1e9;

        // Already computed
        if (dp[amount] != -1)
            return dp[amount];

        // Start with a very large value
        // and try to minimize it
        int ans = 1e9;

        // Try every coin as the next coin
        for (int coin : coins) {

            // If we take this coin,
            // 1 coin is used right now
            // plus whatever is needed
            // for the remaining amount
            // same coin can be taken unlimited times.
            // Example:
            // amount = 12
            // coin = 5
            //
            // 1 + solve(7)
            //
            ans = min(ans,
                      solve(coins, amount - coin) + 1);
        }

        // Store and return answer
        return dp[amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {

        // Initialize memoization array
        // -1 means "not computed yet"
        dp.resize(amount + 1, -1);

        int ans = solve(coins, amount);

        // If answer is still very large,
        // no valid combination exists
        return ans >= 1e9 ? -1 : ans;
    }
};