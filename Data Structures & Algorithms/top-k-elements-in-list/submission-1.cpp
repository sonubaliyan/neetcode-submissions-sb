class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
    unordered_map<int, int> mp;

    for(int num : nums){
        mp[num]++;
    }

    priority_queue<pair<int, int>> maxheap;

    for(auto pa : mp)
        maxheap.push({pa.second, pa.first});

    vector<int> res;
    for(int i =0; i<k; i++)
    {
        res.push_back(maxheap.top().second);
        maxheap.pop();
    }
    return res;

    }
};
