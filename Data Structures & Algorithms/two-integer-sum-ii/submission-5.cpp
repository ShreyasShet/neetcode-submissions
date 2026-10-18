class Solution {
public:
    int binSearch(vector<int>& nums, int lo, int hi, int ele) {
        if (lo > hi)
            return -1;

        int mid = lo + (hi - lo) / 2;

        if (nums[mid] < ele)
            return binSearch(nums, mid + 1, hi, ele);
        else if (nums[mid] > ele)
            return binSearch(nums, lo, mid - 1, ele);
        else
            return mid;
}

    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        for (int i = 0; i < n; i++) {
            int rem = target - numbers[i];
            int pos = binSearch(numbers, i + 1, n - 1, rem);
            if (pos != -1)
                return {i + 1, pos + 1};
        }

        return {};
    }
};
