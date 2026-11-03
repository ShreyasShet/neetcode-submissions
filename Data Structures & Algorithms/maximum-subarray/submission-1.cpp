class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix = nums;
        for(int i = 1; i < n; i++)
            prefix[i] += prefix[i-1];
        
        int min = 0, result = prefix[0];
        for (int x : prefix) {
            int max = x - min;
            if (result < max)
                result = max;
            if (x < min)
                min = x;
        }
        return result;
    }
};
