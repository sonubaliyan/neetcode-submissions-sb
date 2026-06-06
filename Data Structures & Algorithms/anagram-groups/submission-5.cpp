class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> mp;
        for(auto str : strs){
            string sortted = str;
            sort(sortted.begin(), sortted.end());

            mp[sortted].push_back(str);

        }

        vector<vector<string>> res;
        for(auto pa : mp)
        {
            res.push_back(pa.second);
        }
        return res;


    }
};
