class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

        vector<string> dp = {""};

        for (char digit : digits) {
            vector<string> next;

            for (string &curr : dp) {
                for (char ch : mp[digit]) {
                    next.push_back(curr + ch);
                }
            }

            dp = move(next);
        }

        return dp;
    }
};