class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        // left = minimum possible eating speed
        // right = maximum possible eating speed (largest pile)
        int left = 1, right = 0;

        // find max pile to set upper bound of binary search
        for (int p : piles) 
            right = max(right, p);

        // now it bacame binary search problem which has min bound 1 ... max(pile)
        // we need to find the minimum int value k b/w this.

        // store answer (we try to minimize k)
        int result = right;

        // binary search on eating speed k
        while (left <= right) {

            // mid = current eating speed to test
            int k = left + (right - left) / 2;

            long long hours = 0;

            // calculate total hours needed at speed k
            for (int p : piles) {

                // ceil(p / k) without floating point
                // (p + k - 1) / k gives ceiling division
                hours += (p + k - 1LL) / k;
            }

            // if Koko can finish within h hours
            if (hours <= h) {

                // k is valid, try to find smaller k
                result = k;
                right = k - 1;
            }
            else {

                // k is too slow, need faster eating speed
                left = k + 1;
            }
        }

        // minimum valid eating speed found
        return result;
    }
};