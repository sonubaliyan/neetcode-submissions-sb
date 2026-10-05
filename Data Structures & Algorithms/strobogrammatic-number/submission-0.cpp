class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> map = {
            {'0', '0'}, {'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}
        };
        int left = 0, right = num.size() - 1;
        while (left <= right) {
            if (!map.count(num[left]) || map[num[left]] != num[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};