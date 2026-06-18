class Solution {
public:

    void solve(int index, vector<int>& nums, int target,
               vector<int>& current, vector<vector<int>>& result) {

        // Base case: valid combination found
        if (target == 0) {
            result.push_back(current);
            return;
        }

        // Stop if invalid
        if (target < 0) return;

        // Try all elements from current index
        for (int i = index; i < nums.size(); i++) {

            // 🚫 Skip duplicates at same level
            if (i > index && nums[i] == nums[i - 1]) continue;

            // include current element
            current.push_back(nums[i]);

            // move to next index (i+1 because we can't reuse element)
            solve(i + 1, nums, target - nums[i], current, result);

            // backtrack
            current.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        // Step 1: sort to handle duplicates
        sort(candidates.begin(), candidates.end());

        solve(0, candidates, target, current, result);

        return result;
    }
};
