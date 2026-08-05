class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        int n = word.length(), m = abbr.length();
        
        while (i < n && j < m) {
            if (isdigit(abbr[j])) {
                if (abbr[j] == '0') return false;
                int num = 0;
                while (j < m && isdigit(abbr[j])) {
                    num = num * 10 + (abbr[j++] - '0');
                }
                i += num;
            } else {
                if (word[i++] != abbr[j++]) return false;
            }
        }
        
        return i == n && j == m;
    }
};