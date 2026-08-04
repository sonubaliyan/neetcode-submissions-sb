class Solution {
public:
    int calculateTime(string keyboard, string word) {
        int time = 0;
        int pos[26];
        for (int i = 0; i < 26; i++) pos[keyboard[i] - 'a'] = i;
        int prev_idx = 0;
        for(char ch : word)
        {
            int curr_idx = pos[ch - 'a'];
            time += abs(curr_idx - prev_idx);
            prev_idx = curr_idx;
        }
        return time;
    }
};