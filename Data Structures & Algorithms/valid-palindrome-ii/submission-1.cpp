class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int end = s.length()-1;
        int st = 0;

        while(st<end)
        {            
            if(s[st] == s[end])
            {
                st++;
                end--;
            }
            else
            {               
                return isPalindrome(s, st + 1, end) || isPalindrome(s, st, end - 1);
            }
        }
        return true;
    }
};