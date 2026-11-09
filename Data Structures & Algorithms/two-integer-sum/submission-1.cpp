class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> indexMap;

        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int req = target - nums[i];
            if (indexMap.find(req) != indexMap.end()) {
                result.push_back(indexMap[req]);
                result.push_back(i);
                return {indexMap[req], i};
            }
            else
                indexMap[nums[i]] = i;
        }
        return result;
    }
};
