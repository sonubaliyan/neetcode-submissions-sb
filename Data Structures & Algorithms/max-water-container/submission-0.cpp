class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int right = heights.size() - 1;

        int maxWater = 0;

        while (left < right) {

            // Width of the container
            int width = right - left;

            // Height is limited by the shorter bar
            int height = min(heights[left], heights[right]);

            // Current area
            int area = width * height;

            // Update maximum area found so far
            maxWater = max(maxWater, area);

            // Move the pointer pointing to the shorter bar.
            // The shorter bar is the bottleneck.
            if (heights[left] < heights[right]) {
                left++;
            } else {
                right--;
            }
        }
        return maxWater;
    }
};
