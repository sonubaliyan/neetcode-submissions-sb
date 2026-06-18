class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        // Step 1: Count frequency of each task (A-Z)
        vector<int> counts(26, 0);
        for (char t : tasks) {
            counts[t - 'A']++;
        }

        // Step 2: Sort frequencies in ascending order
        // So the largest frequency will be at the end
        sort(counts.begin(), counts.end());

        // Step 3: Get the maximum frequency task
        // counts[25] is the highest frequency
        // We subtract 1 because we only care about gaps between tasks
        int max_val = counts[25] - 1;

        // Step 4: Compute initial idle slots
        // We create "frames" of size n between most frequent tasks
        // Example: A _ _ A _ _ A
        int idle_slots = max_val * n;

        // Step 5: Try to fill idle slots using remaining tasks
        // Start from second highest frequency (index 24)
        for (int i = 24; i >= 0 && counts[i] > 0; i--) {

            // Each task can fill at most 'max_val' gaps
            // We subtract the minimum possible fill
            idle_slots -= min(counts[i], max_val);
        }

        // Step 6: If idle slots remain, they must be added to total time
        // Otherwise, tasks already fit without idle time
        return idle_slots > 0
            ? idle_slots + tasks.size()
            : tasks.size();
    }
};