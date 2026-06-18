class Solution {
public:

    void solve(int index, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
        
        // Step 1: Every state is a valid subset
        result.push_back(current);

        // Step 2: Try adding each remaining element
        for (int i = index; i < nums.size(); i++) {

            // include nums[i] (choose last element)
            current.push_back(nums[i]);

            // move forward
            solve(i + 1, nums, current, result);

            // backtrack (remove last element)
            current.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        solve(0, nums, current, result);

        return result;
    }
};
