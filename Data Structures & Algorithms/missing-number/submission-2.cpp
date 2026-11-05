class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int rangeSum = 0;
        for (int i = 0; i <= n; i++)
            rangeSum = rangeSum ^ i;
        
        for (int num : nums)
            rangeSum = rangeSum ^ num;
        
        return rangeSum;
    }
};
