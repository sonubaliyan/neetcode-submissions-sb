#include <cstring>
class Solution {
public:
    int memo[101];
    int mincost(vector<int> & arr, int i)
    {
        if(i >= arr.size()) return 0;
        if(memo[i] != -1) return memo[i];

        int res = arr[i] + min(mincost(arr, i + 1), mincost(arr, i + 2));
        return memo[i] = res;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(memo, -1, sizeof(memo));
        int res = min(mincost(cost, 0), mincost(cost, 1));
        return res;
    }
};