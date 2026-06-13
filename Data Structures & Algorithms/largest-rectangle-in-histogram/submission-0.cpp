class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        // stack stores indices of bars
        // maintaining increasing height order in stack
        stack<int> st;

        int maxArea = 0;
        int n = heights.size();

        // we go till i = n to flush out remaining bars in stack
        for (int i = 0; i <= n; i++) {
            
            // treat i == n as a virtual bar of height 0
            // this forces all remaining bars to be processed
            int currHeight = (i == n) ? 0 : heights[i];

            // if current bar is smaller, it means:
            // current bar is the "right boundary" for taller bars in stack
            while (!st.empty() && currHeight < heights[st.top()]) {
                
                // height of bar for which we are calculating area
                int height = heights[st.top()];
                st.pop();

                // right boundary is current index i
                int right = i;

                // left boundary is previous smaller element in stack
                int left = st.empty() ? -1 : st.top();

                // width = number of bars between left and right boundaries
                int width = right - left - 1;

                // calculate area and update answer
                maxArea = max(maxArea, height * width);
            }

            // push current index into stack
            st.push(i);
        }

        return maxArea;
    }
};
