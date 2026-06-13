class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        
        int n = position.size();
        vector<pair<int, double>> cars;

        // step 1: compute time
        for (int i = 0; i < n; i++) {
            double time = (double)(target - position[i]) / speed[i];
            cars.push_back({position[i], time});
        }

        // step 2: sort by position descending
        sort(cars.rbegin(), cars.rend());

        stack<double> st;

        // step 3: process cars
        for (auto &c : cars) {
            double time = c.second;

            if (st.empty() || time > st.top()) {
                st.push(time);   // new fleet
            }
            // else: joins existing fleet → do nothing
        }

        return st.size();
    }
};