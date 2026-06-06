class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.length();

        int strt= 0, end = len -1;
        while(strt<=end)
        {
            // this check is to skip the spaces
            // Input: "A man, a plan, a canal: Panama"
            // Your output: false  (comma vs space mismatch)
            // Expected:    true
            if (!isalnum(s[strt])) {
                strt++;
                continue;
            }

             // this check is to skip the spaces
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