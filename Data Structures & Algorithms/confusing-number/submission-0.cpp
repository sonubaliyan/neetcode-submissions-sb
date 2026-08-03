class Solution {
public:
    bool confusingNumber(int n) {
        unordered_map<int, int> rotateMap = {{0, 0}, {1, 1}, {6, 9}, {8, 8}, {9, 6}};
        long long rotatedNum = 0;
        int originalN = n;
        
        if (n == 0) return false;

        while (n > 0) {
            int digit = n % 10;
            if (rotateMap.find(digit) == rotateMap.end()) {
                return false;
            }
            rotatedNum = rotatedNum * 10 + rotateMap[digit];
            n /= 10;
        }

        return rotatedNum != originalN;
    }
};