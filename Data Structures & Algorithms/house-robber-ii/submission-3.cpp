class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        int prev12 = nums[0], prev11 = max(nums[0], nums[1]);       //S1 = a1 and S2 = max(a1, a2)
        for(int i = 2; i < n - 1; i++) {              //loop so that you dont consider an-1
            int current = max(prev11, prev12 + nums[i]);
            prev12 = prev11;
            prev11 = current;
        }

        int prev22 = nums[1], prev21 = max(nums[1], nums[2]);       //S1 = a2 and S2 = max(a2, a3) to exclude a1
        for(int i = 3; i < n; i++) {                  
            int current = max(prev21, prev22 + nums[i]);
            prev22 = prev21;
            prev21 = current;
        }

        return max(prev11, prev21);
    }
};
