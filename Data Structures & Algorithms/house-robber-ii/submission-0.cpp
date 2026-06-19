#include <cstring>
class Solution {
public:
    int dp[100];
    int maxrob(vector<int>& arr, int index, int end) // Changed parameter name size to end
    {
        if(index > end) return 0;
        if(dp[index] != -1) return dp[index];

        dp[index] = max(arr[index] + maxrob(arr, index + 2, end), maxrob(arr, index + 1, end));

        return dp[index];
    }
    int rob(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return nums[0];
        
        memset(dp, -1, sizeof(dp));
        int res1 = maxrob(nums, 0, size - 2);
        
        memset(dp, -1, sizeof(dp));
        int res2 = maxrob(nums, 1, size - 1);

        return max(res1, res2);
    }
};