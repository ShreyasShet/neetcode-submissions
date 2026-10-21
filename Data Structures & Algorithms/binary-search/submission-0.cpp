class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), L = 0, R = n - 1;
        int mid = L + (R - L)/2;
        while(L <= R){
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                L = mid + 1;
                mid = L + (R - L)/2;
            } else {
                R = mid - 1;
                mid = L + (R - L)/2;
            }
        }
        return -1;
    }
};
