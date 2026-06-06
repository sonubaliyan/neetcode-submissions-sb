class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 1); // Initialize the output array with 1s
        
        // Step 1: Calculate the prefix (left) products
        // res[i] will contain the product of all elements to the left of i
        int left_product = 1;
        for (int i = 0; i < n; i++) {
            res[i] = left_product;
            left_product *= nums[i]; // Update left product for the next element
        }
        
        // Step 2: Calculate the suffix (right) products on the fly
        // Multiply the left product already in res[i] by the cumulative right product
        int right_product = 1;
        for (int i = n - 1; i >= 0; i--) {
            res[i] *= right_product;
            right_product *= nums[i]; // Update right product for the next element
        }
        
        return res;
    }
};
