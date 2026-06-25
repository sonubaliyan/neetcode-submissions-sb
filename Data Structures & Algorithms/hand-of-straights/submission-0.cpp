class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> counts;
        for (int card : hand) {
            counts[card]++;
        }

        for (auto const& [card, count] : counts) {
            if (counts[card] > 0) {
                int startCount = counts[card];
                for (int i = 0; i < groupSize; ++i) {
                    if (counts[card + i] < startCount) return false;
                    counts[card + i] -= startCount;
                }
            }
        }

        return true;
    }
};