class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxEnding(n);
        vector<int> minEnding(n);

        maxEnding[0] = minEnding[0] = nums[0];

        int result = nums[0];

        for (int i = 1; i < n; i++) {
            int x = nums[i];

            if (x < 0) {
                maxEnding[i] = max(x, x * minEnding[i - 1]);
                minEnding[i] = min(x, x * maxEnding[i - 1]);
            } else {
                maxEnding[i] = max(x, x * maxEnding[i - 1]);
                minEnding[i] = min(x, x * minEnding[i - 1]);
            }

            result = max(result, maxEnding[i]);
        }

        return result;
    }
};
