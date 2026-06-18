class Solution {
public:

    void solve(int index, vector<int>& nums, int target,
               vector<int>& current, vector<vector<int>>& result) {

        // Base case: valid combination found
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // If we exceed bounds or target becomes negative
        if (index == nums.size() || target < 0) {
            return;
        }

        // Try all numbers starting from current index
        for (int i = index; i < nums.size(); i++) {

            // include nums[i]
            current.push_back(nums[i]);

            // NOTE: we pass i again (not i+1) because reuse is allowed
            solve(i, nums, target - nums[i], current, result);

            // backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;

        solve(0, nums, target, current, result);

        return result;
    }
};