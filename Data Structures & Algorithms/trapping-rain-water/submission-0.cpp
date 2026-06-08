class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size();
        int left = 0;
        int right = n - 1;

        // Tallest bar seen so far from the left
        int leftMax = 0;

        // Tallest bar seen so far from the right
        int rightMax = 0;

        // Total trapped water
        int water = 0;

        while (left < right) {

            // If left bar is smaller,
            // process the left side.
            if (height[left] < height[right]) {

                // Update tallest wall seen from left.
                leftMax = max(leftMax, height[left]);

                // Water trapped at current left position.
                water += leftMax - height[left];

                // Move left pointer.
                left++;
            }
            else {

                // Update tallest wall seen from right.
                rightMax = max(rightMax, height[right]);

                // Water trapped at current right position.
                water += rightMax - height[right];

                // Move right pointer.
                right--;
            }
        }

        return water;

    }
};
