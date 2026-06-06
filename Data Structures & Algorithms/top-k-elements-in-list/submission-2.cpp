class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Step 1: Count frequencies using an unordered_map
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }
        
        // Step 2: Set up a Max-Heap (Standard priority_queue in C++)
        // It stores pairs of {frequency, element}
        priority_queue<pair<int, int>> maxHeap;
        
        // Step 3: Push ALL unique elements from the map into the Max-Heap
        for (auto& pair : mp) {
            maxHeap.push({pair.second, pair.first});
        }
        
        // Step 4: Extract the top k elements from the top of the heap
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(maxHeap.top().second); // Grab the actual number
            maxHeap.pop();                       // Remove the largest element
        }
        
        return res;
    }
};
