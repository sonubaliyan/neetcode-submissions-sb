class Solution {
public:
    bool canJump(vector<int>& nums) {

    int len = nums.size();
    int reachable = 0;
    for(int i = 0; i < len; ++i)
    {
        if (i > reachable) return false;
        reachable = max(reachable, i + nums[i]);
    }

    if(reachable < len - 1)
        return false;
    return true;
    
    }
};