class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, vector<int>> valToIndex;
        for (int i = 0; i < nums2.size(); ++i) {
            valToIndex[nums2[i]].push_back(i);
        }
        
        vector<int> mapping;
        for (int x : nums1) {
            mapping.push_back(valToIndex[x].back());
            valToIndex[x].pop_back();
        }
        return mapping;
    }
};