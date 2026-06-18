class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(int num : nums)
        {
            pq.push(num);
        }


        if ( k == 1)
            return pq.top();

        // find the kth largest element.
        while(k > 1)
        {
            pq.pop();
            k--;

            if(k==1)
                return pq.top();
        }
        return pq.top();
    }
};