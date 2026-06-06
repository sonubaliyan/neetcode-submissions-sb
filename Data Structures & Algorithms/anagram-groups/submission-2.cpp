class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (const string& str : strs) { // Avoid copying the original string
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());
            mp[sorted_str].push_back(str);
        }

        vector<vector<string>> res;
        res.reserve(mp.size()); // Pre-allocate memory for efficiency
        
        for (auto& pa : mp) { // Use reference here
            res.push_back(move(pa.second)); // move() transfers ownership without copying
        }
        return res;
    }
};
