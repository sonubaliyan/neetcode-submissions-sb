class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combined;
        int i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) combined.push_back(nums1[i++]);
            else combined.push_back(nums2[j++]);
        }
        while (i < nums1.size()) combined.push_back(nums1[i++]);
        while (j < nums2.size()) combined.push_back(nums2[j++]);

        int n = combined.size();
        if (n % 2 == 1) return combined[n / 2];
        return (combined[n / 2 - 1] + combined[n / 2]) / 2.0;
    }
};