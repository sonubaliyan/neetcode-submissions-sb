class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

    unordered_map<int, int> mp;

    for(int num = 0; num < nums.size(); num++)
    {
        int sec = target - nums[num];
        if(mp.find(sec) != mp.end())
            //return {mp[nums[num]], num};
            return {mp[sec], num};
        mp[nums[num]] = num;
    }
    return {};

    }
};
