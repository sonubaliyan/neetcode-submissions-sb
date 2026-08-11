class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        int k = 1;
        for(int i=0; i < (int)nums.size() - 1; i++)
        {
            if(nums[i] != nums[i+1])
            {
                nums[k] = nums[i+1];
                k++;
            }
        }
        return k;
    }
};