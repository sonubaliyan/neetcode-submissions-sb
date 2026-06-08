class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // Keep track of the lowest stock price seen so far.
        // We assume the first day's price is the minimum initially.
        int minp = prices[0];

        // Stores the maximum profit found so far.
        // Initialized to 0 because if no profit is possible,
        // the answer should be 0.
        int maxp = 0;

        // Start from day 1 since day 0 is already used
        // as the initial minimum price.
        for (int i = 1; i < prices.size(); i++)
        {
            // If current price is lower than the minimum price seen,
            // update the minimum buying price.
            if (prices[i] < minp)
            {
                minp = prices[i];
            }

            // Calculate profit if we sell on the current day
            // after buying at the lowest price seen so far.
            // Update maxp if this profit is greater.
            maxp = max(maxp, prices[i] - minp);
        }

        // Return the maximum profit achievable.
        return maxp;
    }
};
