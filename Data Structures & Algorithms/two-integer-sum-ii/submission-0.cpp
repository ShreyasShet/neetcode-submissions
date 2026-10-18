class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> nums = numbers;
        vector<int> result;
        int L = 0, n = nums.size(), R = n - 1;
        while(L < R){
            int sum = nums[L] + nums[R];
            if (sum < target)
                L++;
            else if (sum > target)
                R--;
            else {
                result.push_back(L+1);
                result.push_back(R+1);
                break;
            }
        }
        return result;
    }
};
