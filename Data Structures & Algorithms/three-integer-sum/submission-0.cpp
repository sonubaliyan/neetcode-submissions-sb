class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();

        // Step 1: Sort the array.
        // Sorting helps us:
        // 1. Use the two-pointer technique.
        // 2. Easily skip duplicate values.
        sort(nums.begin(), nums.end());

        // Step 2: Fix one element at a time.
        for (int i = 0; i < n - 2; i++) {

            // Since array is sorted:
            // If current number is already > 0,
            // then all remaining numbers will also be > 0.
            // Therefore, their sum can never become 0.
            if (nums[i] > 0)
                break;

            // Skip duplicate first elements.
            // Example:
            // [-1, -1, 0, 1]
            // We only process the first -1.
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // Two pointers for finding the remaining two numbers.
            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int sum = nums[i] + nums[left] + nums[right];

                // Found a valid triplet.
                if (sum == 0) {

                    result.push_back(
                        {nums[i], nums[left], nums[right]}
                    );

                    // Skip duplicate values on the left side.
                    while (left < right &&
                           nums[left] == nums[left + 1]) {
                        left++;
                    }

                    // Skip duplicate values on the right side.
                    while (left < right &&
                           nums[right] == nums[right - 1]) {
                        right--;
                    }

                    // Move both pointers inward
                    // to search for the next unique triplet.
                    left++;
                    right--;
                }

                // Sum is too small.
                // Move left pointer to a larger value.
                else if (sum < 0) {
                    left++;
                }

                // Sum is too large.
                // Move right pointer to a smaller value.
                else {
                    right--;
                }
            }
        }

        return result;
    }
};
