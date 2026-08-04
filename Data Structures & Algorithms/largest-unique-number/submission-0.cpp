class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        unordered_map<int, int> counts;
        for(int num : nums) {
            counts[num]++;
        }
        int max_num = -1;
        for(auto const& [num, count] : counts)
        {
            if(num > max_num && count == 1)
            {
                max_num = num;
            }
        }
        return max_num;
    }
};