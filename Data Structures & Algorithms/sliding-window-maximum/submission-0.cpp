class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> high;

        for (int i = 0; i < k; i++) {
            high.insert(nums[i]);
        }

        vector<int> result;
        for (int i = k; ; i++) {
            result.push_back(*prev(high.end()));

            if (i == nums.size())
                break;
            
            high.erase(high.find(nums[i - k]));
            high.insert(nums[i]);
        }
        return result;
    }
};
