class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int count = 0;
        int cookieIndex = 0;
        for(int cand : g)
        {
            while(cookieIndex < s.size() && s[cookieIndex] < cand)
            {
                cookieIndex++;
            }
            if(cookieIndex < s.size())
            {
                count++;
                cookieIndex++;
            }
            else
            {
                break;
            }
        }
        return count;
    }
};