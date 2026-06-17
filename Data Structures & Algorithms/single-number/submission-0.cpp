class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        // XOR of two same numbers will be zero.
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};