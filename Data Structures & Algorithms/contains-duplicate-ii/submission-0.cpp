class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        multiset<long long> S;
        for (int i = 0; i < nums.size(); i++) {

            if (i > k) {
                auto it = S.lower_bound(nums[i - k - 1]);
                S.erase(it);
            }

            long long x = nums[i];
            auto it = S.lower_bound(x);
            if (it != S.end() && *it == x)
                return true;

            S.insert(x);
        }
        return false;
    }
};