class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int n1 = s1.length();
        int n2 = s2.length();
        
        // Edge case: if s1 is longer than s2, s2 cannot contain a permutation of s1
        if (n1 > n2) return false;
        
        // Frequency arrays for 'a' through 'z'
        vector<int> s1_count(26, 0);
        vector<int> window_count(26, 0);
        
        // Step 1: Initialize the frequency counts for s1 and the first window of s2
        for (int i = 0; i < n1; i++) {
            s1_count[s1[i] - 'a']++;
            window_count[s2[i] - 'a']++;
        }
        
        // If the first window matches, we found a permutation immediately
        if (s1_count == window_count) return true;
        
        // Step 2: Slide the window across s2
        for (int i = n1; i < n2; i++) {
            // Add the new character coming into the window
            window_count[s2[i] - 'a']++;
            
            // Remove the old character leaving the window
            window_count[s2[i - n1] - 'a']--;
            
            // Compare the frequency counts
            if (s1_count == window_count) return true;
        }
        
        return false;
    }
};
