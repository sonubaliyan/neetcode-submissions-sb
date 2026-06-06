class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {

        unordered_map<int, int> map;
        for(auto elem : nums)
        {
            if(map[elem] >= 1)
                return true;
            map[elem]++;
        }
        return false;
    }
};