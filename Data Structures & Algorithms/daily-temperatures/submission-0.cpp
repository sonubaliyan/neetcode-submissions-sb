class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        int n = temperatures.size();

        // Result array initialized with 0
        // If no warmer day is found, answer remains 0
        vector<int> result(n, 0);

        // Stack stores indices of days
        // These are days for which we haven't found a warmer future day yet
        stack<int> s;

        for (int i = 0; i < n; i++) {

            // While stack is not empty AND current temperature is warmer
            // than the temperature at index stored at top of stack
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {

                // Index of previous colder day
                int prevIndex = s.top();
                s.pop();

                // We found a warmer day for prevIndex
                // So distance = current day - previous day
                result[prevIndex] = i - prevIndex;
            }

            // Push current day index into stack
            // We are now waiting for a warmer future day for this index
            s.push(i);
        }

        // Any index left in stack means:
        // no warmer day was found → value stays 0
        return result;
    }
};