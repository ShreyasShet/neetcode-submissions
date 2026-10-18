class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        int prev2 = nums[0], prev1 = max(nums[0], nums[1]);

        if (n == 2)
            return prev1;

        int current;
        for(int j = 2; j < n; j++){
            current = max(prev1, prev2 + nums[j]);
            prev2 = prev1;
            prev1 = current;
        }
        return current;
    }
};
