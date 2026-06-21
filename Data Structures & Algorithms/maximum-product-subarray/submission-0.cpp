class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxProd = nums[0];
        int minProd = nums[0];
        int result  = nums[0];

        for (int i = 1; i < nums.size(); i++) {

            // Negative number swaps roles
            if (nums[i] < 0)
                swap(maxProd, minProd);

            // Either:
            // 1. Start a new subarray from nums[i]
            // 2. Extend previous subarray
            maxProd = max(nums[i], maxProd * nums[i]);
            minProd = min(nums[i], minProd * nums[i]);

            result = max(result, maxProd);
        }

        return result;
    }
};
