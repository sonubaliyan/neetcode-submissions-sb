class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();

        int strt= 0, end = len -1;
        while(strt<=end)
        {
            if (!isalnum(s[strt])) {
                strt++;
                continue;
            }
            if (!isalnum(s[end])) {
                end--;
                continue;
            }
            if (tolower(s[strt]) != tolower(s[end]))
            {
                return false;
            }
            strt++;
            end--;
        }
        return true;
    }
};