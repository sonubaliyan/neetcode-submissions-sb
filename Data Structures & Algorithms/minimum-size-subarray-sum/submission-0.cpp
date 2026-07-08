class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int min_len = INT_MAX;

        int left = 0;
        int sum = 0;
        for(int right=0; right< nums.size(); right++)
        {
            sum += nums[right];
            if(sum >= target)
            {
                while(sum >= target)
                {
                    sum = sum - nums[left];
                    left++;
                }

                min_len = min(min_len, right-(left-1)+1);
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};