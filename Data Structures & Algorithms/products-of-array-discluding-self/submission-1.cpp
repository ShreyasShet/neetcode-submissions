class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> L = nums;
        vector<int> R = nums;
        vector<int> result;
        L[0] = 1;
        R[n-1] = 1;
        for(int i = 1; i < n; i++)
            L[i] = L[i-1] * nums[i-1];
        
        for(int j = n-2; j >= 0; j--)
            R[j] = R[j+1] * nums[j+1];

        for(int k = 0; k < n; k++)
            result.push_back(L[k] * R[k]);
        
        return result;
    }
};
