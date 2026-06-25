class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_surplus = 0;
        int current_surplus = 0;
        int start_node = 0;

        for (int i = 0; i < gas.size(); i++) {
            total_surplus += gas[i] - cost[i];
            current_surplus += gas[i] - cost[i];
            if (current_surplus < 0) {
                current_surplus = 0;
                start_node = i + 1;
            }
        }

        return (total_surplus < 0) ? -1 : start_node;
    }
};