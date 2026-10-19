class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-2; i++){
            //to avoid computing triplets for duplicates
            if (i > 0 && nums[i] == nums[i-1])
                continue;

            //early stopping condition if the smallest value is positive
            if (nums[i] + nums[i+1] + nums[i+1] > 0)
                continue;
            
            /*early stopping condition if adding largest values to fixed element from outer
            loop is negative*/
            if (nums[i] + nums[n-2] + nums[n-1] < 0)
                continue;

            int L = i + 1, R = n - 1;
            while (L < R) {
                int sum = nums[i] + nums[L] + nums[R];

                if (sum < 0) 
                    L++;
                else if (sum > 0) 
                    R--;
                else {
                    result.push_back({
                        nums[i], nums[L], nums[R]
                    });

                    L++;
                    R--;

                    //skip adjacent element of L and R if they were equal to old values
                    while (L < R &&
                        nums[L] == nums[L - 1]) {
                        L++;
                    }

                    while (L < R &&
                        nums[R] == nums[R + 1]) {
                        R--;
                    }
                }
            }
        }
        return result;
    }
};
