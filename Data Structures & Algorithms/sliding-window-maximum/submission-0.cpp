class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        

        vector<int> res;
        for(int right=0; right <= nums.size()-k; right++)
        {

            auto maxelem = *max_element(nums.begin() + right, nums.begin() + right + k);

            res.push_back(maxelem);

        }
        return res;
    }
};