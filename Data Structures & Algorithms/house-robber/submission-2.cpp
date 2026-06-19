#include <cstring>
class Solution {
public:

    int dp[100];
    int maxrob(vector<int>& arr, int index, int size)
    {
        if(index > size-1) return 0;
        if(dp[index] != -1) return dp[index];

        dp[index] = max(arr[index] + maxrob(arr, index + 2, size), maxrob(arr, index + 1, size));

        return dp[index];
    }
    int rob(vector<int>& nums) {
        
        int size = nums.size();
        memset(dp, -1, sizeof(dp));
        int res = maxrob(nums, 0, size);

        return res;
    }
};