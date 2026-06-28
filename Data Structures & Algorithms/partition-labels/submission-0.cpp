class Solution {
public:
    vector<int> partitionLabels(string s) {
        int last[26];
        for (int i = 0; i < s.length(); i++) {
            last[s[i] - 'a'] = i;
        }
        
        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            end = max(end, last[s[i] - 'a']);
            if (i == end) {
                res.push_back(i - start + 1);
                start = i + 1;
            }
        }
        return res;
    }
};