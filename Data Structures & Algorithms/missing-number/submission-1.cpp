class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if (nums[0] != 0)
            return 0;
        int sum = 0, mask = n * (n + 1) / 2;
        for (int num : nums) {
            sum += num;
        }
        return mask - sum;
    }
};
