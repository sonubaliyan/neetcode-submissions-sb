class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        // Treat the array like a linked list:
        //
        // index -> nums[index]
        //
        // Example:
        // nums = [1,3,4,2,2]
        //
        // 0 -> 1
        // 1 -> 3
        // 3 -> 2
        // 2 -> 4
        // 4 -> 2
        //
        // This creates a cycle:
        //
        // 2 -> 4
        // ^    |
        // |____|
        //
        // The duplicate number is the entrance of the cycle.

        int slow = nums[0];
        int fast = nums[0];

        // Phase 1:
        // Find an intersection point inside the cycle.
        //
        // slow moves 1 step:
        //     slow = nums[slow]
        //
        // fast moves 2 steps:
        //     fast = nums[nums[fast]]
        //
        // Just like Floyd's Cycle Detection in a linked list.
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // We found a meeting point inside the cycle.
        //
        // Now move slow back to the start.
        slow = nums[0];

        // Phase 2:
        //
        // Move both pointers one step at a time.
        //
        // The point where they meet again is
        // the entrance of the cycle.
        //
        // In this problem, the entrance of the cycle
        // is exactly the duplicate number.
        while (slow != fast) {

            slow = nums[slow];
            fast = nums[fast];
        }

        // Both pointers are now at the duplicate number.
        return slow;
    }
};