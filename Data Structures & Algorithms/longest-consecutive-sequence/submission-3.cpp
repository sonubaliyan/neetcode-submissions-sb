class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxVal = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if (numSet.find(nums[i] - 1) == numSet.end()) {
                int count = 1;
                int currnum = nums[i];
                while(numSet.find(currnum + 1) != numSet.end())
                {
                    currnum += 1;
                    count++;
                }
                if (count > maxVal) maxVal = count;
            }
        }

        return maxVal;

    }
};