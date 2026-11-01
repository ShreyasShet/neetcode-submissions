class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s1 = 0, s2 = 0, sum = 0;
        for(int num : nums) {
            sum += num;
        }

        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int x : nums) {
            for (int s = target; s >= x; s--) {
                if (dp[s - x])
                    dp[s] = true;
            }
        }
        return dp[target];
    }
};
