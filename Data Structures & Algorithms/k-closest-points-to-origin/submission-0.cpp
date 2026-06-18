class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // {distance, index}
        priority_queue<pair<int, int>> maxHeap;

        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];

            // as one corrdinate is 0,0 and squrt does not change ordering 
            int dist = x * x + y * y;

            maxHeap.push({dist, i});

            // Keep only k closest points, pop the largest elem, i,e largest distance
            // so that we will be left with smallest element only.
            if (maxHeap.size() > k) {
                maxHeap.pop();
            }
        }

        vector<vector<int>> result;

        while (!maxHeap.empty()) {
            // as we have stored the fisrt index as distance and 2nd as row now ...
            result.push_back(points[maxHeap.top().second]);
            maxHeap.pop();
        }

        return result;
    }
};