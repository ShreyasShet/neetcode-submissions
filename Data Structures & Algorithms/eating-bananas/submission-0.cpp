class Solution {
public:
    bool canFinish(vector<int>& piles, int h, int k) {
        int hours = 0;
        for (int pile : piles) {
            hours += (pile + k - 1) / k;
            if (hours > h)
                return false;
        }
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxPile = *max_element(piles.begin(), piles.end());
        
        int lo = 1, hi = maxPile;

        while(lo < hi) {
            int k = lo + (hi - lo) / 2;         //eating rate

            if (canFinish(piles, h, k)) {
                hi = k;
            } else {
                lo = k + 1;
            }
        }
        return lo;
    }
};
